import numpy as np

from piece import pawn
from piece import rook
from piece import knight
from piece import bishop
from piece import queen
from piece import king
from piece import empty

class board():
    def __init__(self):
        self.board = np.empty([8, 8], dtype=object)
        self.reset()

    def reset(self):
        for i in range(2,6):
            for j in range(8):
                self.board[i][j] = empty(i, j)
        for j in range(8):
            self.board[1][j] = pawn("white", 1, j)
            self.board[6][j] = pawn("black", 6, j)
        #white
        self.board[0][0] = rook("white", 0, 0)
        self.board[0][1] = knight("white", 0, 1)
        self.board[0][2] = bishop("white", 0, 2)
        self.board[0][3] = king("white", 0, 3)
        self.board[0][4] = queen("white", 0, 4)
        self.board[0][5] = bishop("white", 0, 5)
        self.board[0][6] = knight("white", 0, 6)
        self.board[0][7] = rook("white", 0, 7)
        #black
        self.board[7][0] = rook("black", 7, 0)
        self.board[7][1] = knight("black", 7, 1)
        self.board[7][2] = bishop("black", 7, 2)
        self.board[7][3] = king("black", 7, 3)
        self.board[7][4] = queen("black", 7, 4)
        self.board[7][5] = bishop("black", 7, 5)
        self.board[7][6] = knight("black", 7, 6)
        self.board[7][7] = rook("black", 7, 7)

    def getPiece(self, x, y):
        return self.board[y][x]

    def move(self, prev, now):
        oldSpot = self.board[prev[1]][prev[0]]
        if(now[1] >= 0 and now[1] < 8):
            if(now[0] >= 0 and now[0] < 8):
                newSpot = self.board[now[1]][now[0]]
        else:
            return False

        if(oldSpot.isLegal(self.board, oldSpot, newSpot)):
            return self.swap(oldSpot, newSpot)
        return False

    def swap(self, prev, now):
        if(not now.isEmpty()):
            if(prev.getColor() != now.getColor):
                temp = empty(prev.getY(), prev.getX())
                prev.setCord(now.getX(), now.getY())
                self.board[now.getY()][now.getX()] = prev   
                self.board[temp.getY()][temp.getX()] = temp
                return True
        else:
            temp = empty(prev.getY(), prev.getX())
            prev.setCord(now.getX(), now.getY())
            self.board[now.getY()][now.getX()] = prev   
            self.board[temp.getY()][temp.getX()] = temp
            return True
        return False

    def printBoard(self):
        print("  ", end='')
        for i in range(8):
            print(str(i+1) + " ", end='')
        print()
        for i in range(8):
            print(str(i+1) + " ", end='')
            for j in range(8):
                self.board[i][j].printPiece()

            print()

#if __name__ == '__main__':
    #run = board()
    #run.printBoard()

