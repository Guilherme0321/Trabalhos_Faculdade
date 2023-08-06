class Bin2Base:
    def __init__(self):
        self.number = ''
        self.recive = ''
        self.temp = 0
    
    def convertTodecimal(self):
        length = len(self.recive)
        for i in range(length):
            self.temp += int(self.recive[i]) * pow(2,length-1-i)

    def setNumber(self,num):
        self.recive = num
        self.convertTodecimal()

    def getNumber(self):
        return self.temp

x = Bin2Base()

x.setNumber(num='1000')
print(x.getNumber())