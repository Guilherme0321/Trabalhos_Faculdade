class ToBinary:
    def __init__(self):
        self.strNum = ''
        self.intNum = ''

    def isNumber(self):
        numb = 0
        for i in range(len(self.strNum)):
            if '0' <= self.strNum and self.strNum <= '9':
                numb += 1
        if numb == len(self.strNum):
            return True
        else:
            return False

    def toBinary(self):
        if self.isNumber():
            numtoInt = int(self.strNum)
            if numtoInt == 0:
                self.intNum = '0'
            while numtoInt > 0:
                self.intNum = f'{numtoInt % 2}{self.intNum}'
                numtoInt = numtoInt // 2

        else:
            print('Entrada invalida!')
    
    def setNumber(self,num):
        self.strNum = num
        self.intNum = ''
        self.toBinary()

    def getNumber(self):
        return self.intNum

converter = ToBinary()

while(True):
    number = input('Digite end para sair do loop\nDigite o numero que quer converter para binario: ')
    if number == 'end':
        break
    converter.setNumber(number)
    print(converter.getNumber())
