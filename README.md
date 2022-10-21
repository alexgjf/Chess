# Chess UI
 
Authors: \<[Aaron Song](https://github.com/AaronSxng)\> \<[Jingfang Guan](https://github.com/alexgjf)\> \<[Haseeb Umerani](https://github.com/HaseebU)\> \<[Jordan Peck](https://github.com/Mimin7447)\>

## Project Description
  * Why is it important or interesting to you?
    * Programming a chess game is interesting because there are a lot of specific rules to the game. The game requires you to know how each pieces moves as well as how it captures and wins. Because of this, programming the game can be a challenge since we don't want the user making ilegal moves.
  * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
    * [C++](https://www.cplusplus.com/) - Language for classes and objects
    * [Python](https://www.python.org/) - Language for gui and ai
    * [PyGame](https://www.pygame.org/news) - Python Game GUI
    * [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) - C++ GUI
  * What will be the input/output of your project? What are the features that the project provides?
    * The output of the program will be the chess board along with the pieces. The input is the players movement. Some of the features may include a timer, an undo button, and a simple ai. The chess program will have a menu page and a fully functional board and pieces. These pieces and boards will have individual roles that work together. The features added to the game is mainly for ease of use.
 
## Class Diagram
[Copy of Chess UML]![image](https://user-images.githubusercontent.com/74108022/171981409-73c2b504-f0b6-4230-afad-4d1a7eee02bb.png)



Description: 
* **Main** class is the driver for our program and has an instance of a board, all 32 pieces, and both players. It initializes the board and displays the game to the GUI. Checks Who's turn it is, and can undo turns.
* **Piece** keeps track of its own position and has a unique move method defnied in its subclass (Pawns also handle their own promotion). Has a color, type, and a counter for how many moves it has made.
* **Board** Records the moves that have been played and tracks the state of the game. Determines if a player is in check.
 
 > ## Phase III
 > In our project we used **strategy** design patterns in for chesses in piece class. For the implementation of our chess pieces, we used a **strategy** pattern in that each piece has a different **'islegal' strategy**. Since the chess pieces are very similar, we were able to simplify our code by using an abstract class **Piece**. Because of this, we only had to define the **'islegal' strategy** that each strategy is unique to each piece. **'islegal' strategy** of each kind of chess's function are checking 3 things, whether the movement follows the chess's rule, certain pieces are not jumping over non empty tile, and capturing opponent's pieces.
 
 > ## Final deliverable
 ## Screenshots
 > Screenshots of the input/output after running your application
 > ![image](https://user-images.githubusercontent.com/46555484/171975710-5c3156b0-fcc3-41f5-8e55-0158d436ef85.png)
 > ![image (1)](https://user-images.githubusercontent.com/46555484/171975779-0208e66f-fb9b-4efb-be5a-df7f7f6a529d.png)
 > ![image](https://user-images.githubusercontent.com/93061497/171981245-96be7595-0e0e-44a7-b123-695f66ba00af.png)
 > <img width="356" alt="image (2)" src="https://user-images.githubusercontent.com/93061497/171981302-1057bf6d-cfc0-443d-8191-01990a647f5b.png">
 > <img width="353" alt="image (1)" src="https://user-images.githubusercontent.com/93061497/171981309-c873e81c-e249-4103-bc6c-c3ee250856d2.png">




 ## Installation/Usage
 > Instructions on installing and running your application
 > * Download an IDE, preferably VS Code.
 > * Download Python 3.10.
 > * Download the following Graphics library for the GUI: https://www.sfml-dev.org/download/sfml/2.5.1/
 > * In the terminal, install pygame and numpy.
 > * In board.py, we input numpy library and it is used for working with the board arrays or matrice.
 > * Run the program through main.
 > * Terminal UI will open with text based move operations
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 >  >![image](https://user-images.githubusercontent.com/74108022/171978444-5167e1fc-a92d-4bcc-82b9-3a93ac4cfc4b.png)
 > * The first test case is testing when the chess board is initialized, are all chess pieces at the correct position, class, and color.
 > * We unit tested each function for the individual pieces, such as getX, getY, move (different movement mechanisms for each piece), color, collision, capturing, etc.
 > * More specifically, each piece of chess(pawn, rook, biship, king, knight, queen) are tested for all movements following its rule, including capturing opponents' pieces and not capturing teammates. It also passed the test for chess pieces that move more than 1 space are not jumping over any non empty tile. 
 > * There are also test cases for pieces to detect illegal movement of each kind of chess that should return false when it happens.
 
