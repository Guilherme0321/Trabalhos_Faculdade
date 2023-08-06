class Bin2Base:
    def __init__(self):
        self.number = ''
        self.recive = ''
        self.temp = 0
        self.base = 0
    
    def isBInary(self,num:str):
        for i in num:
            if not('0' <= i and i <= '1'):
                return False
        return True
    
    def baseisValid(self,num:int):
        if num in [10,8,16]:
            return True

    def convertTodecimal(self):
        length = len(self.recive)
        for i in range(length):
            self.temp += int(self.recive[i]) * pow(2,length-1-i)

    def push_back(self, num):
        self.number = f'{num}{self.number}'

    def convertTOhex(self):
        while self.temp > 0:
            resto = self.temp % self.base
            if resto == 10:
                self.push_back('a')
            elif resto == 11:
                self.push_back('b')
            elif resto == 12:
                self.push_back('c')
            elif resto == 13:
                self.push_back('d')
            elif resto == 14:
                self.push_back('e')
            elif resto == 15:
                self.push_back('f')
            else:
                self.push_back(resto)
            self.temp //= self.base

    def convetTooctal(self):
        while self.temp > 0:
            self.push_back(self.temp % self.base)
            self.temp //= self.base

    def controller(self):
        self.convertTodecimal()
        if self.base == 10:
            self.number = self.temp
        elif self.base == 8:
            self.convetTooctal()
        elif self.base == 16:
            self.convertTOhex()

    def setNumber(self,num ,base:int):
        self.recive = num
        self.base = base
        self.number = ''
        self.controller()

    def getNumber(self):
        return self.number
