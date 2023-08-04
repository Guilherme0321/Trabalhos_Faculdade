class ToBinary:
    def __init__(self):
        self.strNum = ''
        self.intNum = ''

    def isNumber(self, num = ''):
        numb = 0
        if num == '':
            for i in range(len(self.strNum)):
                if '0' <= self.strNum and self.strNum <= '9':
                    numb += 1
            if numb == len(self.strNum):
                return True
            else:
                return False
        else:
            for i in range(len(num)):
                if '0' <= num and num <= '9':
                    numb += 1
            if numb == len(num):
                return True
            else:
                return False

    def convert(self,base=2):
        if self.isNumber():
            numtoInt = int(self.strNum)
            if numtoInt == 0:
                self.intNum = '0'
            while numtoInt > 0:
                self.intNum = f'{numtoInt % base}{self.intNum}'
                numtoInt = numtoInt // base
        else:
            print('Entrada invalida!')
    
    

    def toBinary(self):
        self.convert(base=2)

    def setNumber(self,num):
        self.strNum = num
        self.intNum = ''
        self.toBinary()

    def getNumber(self):
        return self.intNum

