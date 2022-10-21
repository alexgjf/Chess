//#include <Python.h>
#include <SFML/Graphics.hpp>
//#include <time.h>
#include <string>
using namespace sf;

#include <iostream>
#include <sstream>
#include <iomanip>
//#include "GameTimer.hpp"
#include "GameTimer.cpp"
#include <cstdint>
//#include "Stub.py"


//Helper, Sets the size and position of the piece sprites
void populateSprites(int boardNums[8][8], Sprite pieceSprites[32], int size) {
    int k = 0;

    for (int i=0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int pieceNum = boardNums[i][j];     //The int stored at location i, j in the boardNums array

            if (pieceNum != 0) {                //Skip 0's
                int x = abs(pieceNum) - 1;      //Select the type of Piece this will be
                int y;
                if (pieceNum < 0 ) {y = 1;}     //For negative numbers choose from the black sprites from the bottom row of pieces.png
                if (pieceNum > 0 ) {y = 0;}     //For postitive numbers choose from the white sprites from top row of pieces.png

                pieceSprites[k].setTextureRect(IntRect(x*size, y*size, size, size));    //Determines the section of pieces.png that will be assigned to this sprite
                pieceSprites[k].setPosition(size*j, size*i);                            //Determines this sprites position on the board

                k++;
            }
        }
    }
}



int main() {
    // PyObject *pName, *pModule, *pDict, *pClass, *pInstance, *pValue;
    // Py_Initialize();
    // pName = PyUnicode_FromString("Stub");
    // pModule = PyImport_Import(pName);
    // pDict = PyModule_GetDict(pModule);
    // pClass = PyDict_GetItemString(pDict, "Stub");
    // if (PyCallable_Check(pClass))
    // {
    //     pInstance = PyObject_CallObject(pClass,NULL);
    // }
    // pValue = PyObject_CallMethod(pInstance, "getPiece", "(i)", (0, 0));
    // int cResult = (intptr_t)pValue;

    // Py_Finalize();

    const int size = 76;           //Used for grid size in pieces.png
    Sprite pieceSprites[32];       //Array of all Sprites for chess pieces
    GameTimer timer;

    //Stub Init, Eventually should get board data from Board class//
    //6->Pawn           //3->Bishop
    //5->Rook           //2->Queen
    //4->Knight         //1->King
    //Positive->White   //Negative->Black
    int boardNums[8][8] =  {-5, -4, -3, -1, -2, -3, -4, -5,
                            -6, -6, -6, -6, -6, -6, -6, -6,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            6, 6, 6, 6, 6, 6, 6, 6,
                            5, 4, 3, 1, 2, 3, 4, 5};


    //Renders the window
    RenderWindow window(VideoMode(700, 612), "CHESS");

    //Font for timer printout
    Font font;
    font.loadFromFile("fonts/ARIAL.ttf");
    //Text to be displayed for timer
    Text wTimerText("00:00", font, 20), bTimerText("00:00", font, 20);

    //Set timer printout positions
    wTimerText.setPosition(630, 538);
    bTimerText.setPosition(630, 70);

    Texture t1, t2;
    t1.loadFromFile("images/pieces.png");
    t2.loadFromFile("images/board.png");

    //Assign all pieces sprites to the pieces.png texture
    for (int i=0; i<32; i++) {pieceSprites[i].setTexture(t1);}
    populateSprites(boardNums, pieceSprites, size);

    Sprite sBoard(t2);          //Assign Sprite to board.png texture
    int movePiece = 0;          //Tracks which piece in the piece sprites array is to be moved

    bool moving = false;        //Tracks if a piece is being moved
    bool gameStart = false;     //Tracks if the game has begun
    bool blackTurn = false;     //Tracks who's turn it is

    int offsetX = 0, offsetY = 0;

    while (window.isOpen()) {
        Vector2i mouseVec = Mouse::getPosition(window);

        Event e;
        while (window.pollEvent(e)) {

            //Check if window is still opened
            if (e.type == Event::Closed) {
                window.close();
            }
            
            //Pick up object
            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left) {
                    for (int i=0; i<32; i++) {
                        if (pieceSprites[i].getGlobalBounds().contains(mouseVec.x,mouseVec.y)) {
                            movePiece = i;      //indicate the piece in pieceSprites to be moved
                            moving = true;
                            
                            offsetX = mouseVec.x - pieceSprites[i].getPosition().x;
                            offsetY = mouseVec.y - pieceSprites[i].getPosition().y;
                        }
                    }
                }
            }

            //Drop object
            if (moving) {
                if (e.type == Event::MouseButtonReleased) {
                    if (e.key.code == Mouse::Left) {
                        moving = false;
                        gameStart = true;   //Indicate that the game has begun
                        pieceSprites[movePiece].setScale(1, 1); //Set piece back to original size

                        pieceSprites[movePiece].setPosition((mouseVec.x/size)*size, ((mouseVec.y/size)*size));  //Snap piece into place when dropped

                        blackTurn = !blackTurn;     //Switch who's turn it is
                    }
                }
            }

            //Update position of the piece while it is being moved
            if (moving) {
                pieceSprites[movePiece].setScale(1.1f, 1.1f);
                pieceSprites[movePiece].setPosition(mouseVec.x-offsetX, mouseVec.y-offsetY);      //Center the piece on the mouse while moving
            }
        }

        //Handle clocks
        if (gameStart == false) {
            timer.resetTimer();
        }

        if (blackTurn == true) {
            bTimerText.setString(timer.getBTimeString());
        }
        else {
            wTimerText.setString(timer.getWTimeString());
        }

        //display
        window.clear();
        window.draw(sBoard);
        for (int i=0; i<32; i++) {window.draw(pieceSprites[i]);}
        window.draw(wTimerText);
        window.draw(bTimerText);
        window.display();
    } //End WindowIsOpen
    return 0;
} //End main