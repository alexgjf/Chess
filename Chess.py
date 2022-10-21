import pygame
pygame.init()
from PieceSprite import PieceSprite

class Chess:
    def __init__(self) :
        self.black = (0, 0, 0)
        self.size = 76
        self.pieceSprites = []*32

        self.boardNums = [[-5, -4, -3, -1, -2, -3, -4, -5],
                          [-6, -6, -6, -6, -6, -6, -6, -6],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [6, 6, 6, 6, 6, 6, 6, 6],
                          [5, 4, 3, 1, 2, 3, 4, 5]]

        self.populateSprites()

        self.moving = False

        self.offsetX = 0
        self.offsetY = 0

        self.mouseX = pygame.mouse.get_pos()[0]
        self.mouseY = pygame.mouse.get_pos()[1]

        self.display_surface = pygame.display.set_mode((612, 612 ))
        pygame.display.set_caption('Chess')

        self.board = pygame.image.load(r'.\images\board.png')
        self.pieces = pygame.image.load(r'.\images\pieces.png')

    def populateSprites(self) :
        for i in range(8):
            for j in range(8):
                pieceNum = self.boardNums[i][j]

                if (pieceNum != 0):
                    x = (abs(pieceNum) - 1)
                    y = 0
                    if (pieceNum < 0):
                        y = 1

                    piece = PieceSprite(self.size*i, self.size*j, self.size, self.size*x, self.size*y)
                    self.pieceSprites.append(piece)

    def listen(self) :
        self.mouseX = pygame.mouse.get_pos()[0]
        self.mouseY = pygame.mouse.get_pos()[1]

        for event in pygame.event.get() :
            if event.type == pygame.QUIT :
                pygame.quit()
                quit()

            elif event.type == pygame.MOUSEBUTTONDOWN :
                i = 0
                for piece in self.pieceSprites :
                    if (piece.inBounds(self.mouseX, self.mouseY)) :
                        
                        print(str(self.mouseX) + ", " + str(self.mouseY))
                        self.moving = True

                        self.movePiece = i
                        print(self.movePiece)

                        self.offsetX = self.mouseX - piece.getX()
                        self.offsetY = self.mouseY - piece.getY()
                    i += 1
                        
                        

            elif (self.moving and event.type == pygame.MOUSEBUTTONUP) :
                self.moving = False
                self.gameStart = True

                self.pieceSprites[self.movePiece].setPos(((self.mouseX/self.size)*self.size), ((self.mouseY/self.size)*self.size))

    def display(self) :
        self.display_surface.fill(self.black)

        self.display_surface.blit(self.board, (0,0))

        if (self.moving) :
            self.pieceSprites[self.movePiece].setPos(self.mouseX - self.size/2, self.mouseY - self.size/2)
        for piece in self.pieceSprites:
            self.display_surface.blit(self.pieces, (piece.getY(), piece.getX()), (piece.getImgX(), piece.getImgY(), piece.getSize(), piece.getSize()))

        pygame.display.update()