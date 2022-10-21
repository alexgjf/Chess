class PieceSprite:
    def __init__(self, x, y, size, imgx, imgy) :
        self.xPos = x
        self.yPos = y
        self.size = size
        self.imgX = imgx
        self.imgY = imgy

    def getSize(self) :
        return self.size
    def getX(self) :
        return self.xPos
    def getY(self) :
        return self.yPos
    def getImgX(self) :
        return self.imgX
    def getImgY(self):
        return self.imgY

    def setX(self ,x) :
        self.x = x
    def setY(self, y) :
        self.y = y
    def setPos(self, y, x) :
        print("we are in the set Pos")
        self.xPos = x
        self.yPos = y
    
    def inBounds(self, y, x) :
        if (x > self.xPos and y > self.yPos and x < (self.xPos + self.size) and y < (self.yPos + self.size)) :
            return True
        else : return False
