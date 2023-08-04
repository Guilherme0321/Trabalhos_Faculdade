class ToDeciamal:
    def __init__(self):
        self.reciveNumber = ''
        self.convertedNumber = 0
    
    def isNumber(self):
        for i in self.reciveNumber:
            if(not ('0' <= i and i <= '9')):
                return False
        return True
    
    def toDeciamal(self,base=2):
        if self.isNumber():    
            for i in range(len(self.reciveNumber)):
                self.convertedNumber += int(self.reciveNumber[i]) * pow(base,len(self.reciveNumber)-1-i)
        else:
            self.convertedNumber = -1

    def isBinary(self,num=''):
        if num == '':
            num = self.strNum
        for i in num:
            if not('0' <= i and i <= '1'):
                return False
        return True
    
    def setNumber(self,num = '',base = 2):
        self.reciveNumber = num
        self.convertedNumber = 0
        if base == 2 and self.isBinary(num):
            self.toDeciamal(base=base)

    
    def getNumber(self):
        return self.convertedNumber