class double2bin:
    def __init__(self):
        self.dec:str = ''
        self.bin:str = ''
        self.separador = []
        
        
    def before_toBinary(self) -> str:
        inteiro:int = int(self.separador[0])
        i:int = 0
        temp:int = 0
        while inteiro > 0:
            temp += (inteiro % 2) * pow(10,i)
            i += 1
            inteiro //= 2
        return f'{temp}'

    def after_toBinary(self,precisao:int=10) -> str:
        real:float = float(f'0.{self.separador[1]}')
        inteira:str = ''
        i:int = 0
        while real != 0 and i < precisao:
            real *= 2
            inteira += f'{int(real)}'
            real -= int(real)
            i += 1
        return inteira

    def separar(self):
        if ',' in self.dec:
            self.dec = self.dec.replace(',','.')
        temp = ''
        for i in self.dec:
            if i != '.' and i != '\0' and i != '\n':
                temp += i
            else:
                self.separador.append(temp)
                temp = ''
        self.separador.append(temp)
    
    def isNumber(self,num:str) -> bool:
        length = len(num)
        isNumber = True
        couter:int = 0
        for i in range(length):
            if not(('0' <= num[i] and num[i] <= '9') or num[i] == '.' or num[i] == ','):
                isNumber = False
                i = length
            if num[i] == ',' or num[i] == '.':
                couter += 1
            if couter > 1:
                isNumber = False
        return isNumber
    
    def isFloat(self,num:str) -> bool:
        length:int = len(num)
        isfloating:bool = False
        for i in range(length):
            if num[i] == ',' or num[i] == '.':
                isfloating = True
                i = length
        return isfloating
    
    def setNumber(self,num:str):
        if self.isNumber(num):
            self.dec = num
            self.bin = ''
            self.separador = []
            self.temp = 0
            self.separar()
            if self.isFloat(num):
                precisao = int(input('Precisão: '))
                self.bin = f'{self.before_toBinary()}.{self.after_toBinary(precisao)}'
            else:
                self.bin = f'{self.before_toBinary()}'
        else:
            print('Formato invalido"')
    def getNumber(self):
        return self.bin
    
