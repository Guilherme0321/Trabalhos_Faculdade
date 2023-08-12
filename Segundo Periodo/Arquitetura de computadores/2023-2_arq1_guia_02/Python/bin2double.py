class Operacoes:

    def __init__(self):
        self.bin:str = ''
        self.dec:str = ''
        self.separador = []
        self.temp:int = 0
    
    def is_bin(self,num:str):
        isTrue = True
        count:int = 0
        for i in num:
            if not('0' <= i and i <= '1' or i == '.' or i == ','):
                isTrue = False
            if i == '.':
                count += 1
            if count > 1:
                isTrue = False
        return isTrue

    def arr_Sep(self):
        temp = ''
        if ',' in self.bin:
            self.bin.replace(',','.')
            
        self.bin.replace(',','.')
        for i in self.bin:
            if i != ',' and i != '.':
                temp += i
            else:
                self.separador.append(temp)
                temp = ''
        self.separador.append(temp)

    def before_binTodec(self) -> int:
        temp:int = 0
        length:int = len(self.separador[0])
        tempSTR:str = self.separador[0]

        for i in range(length):
            temp += int(tempSTR[i]) * pow(2,length -1 -i)
        return temp

    def after_binTodec(self) -> int:
        temp:float = 0
        length:int = len(self.separador[1])
        tempSTR:str = self.separador[1]
        for i in range(length):
            temp += int(tempSTR[i]) * pow(2,-i-1)
        return temp

    def Controller(self):
        self.arr_Sep()
        self.dec = self.before_binTodec() + self.after_binTodec()

    def setBin_Number(self, num: str):
        if self.is_bin(num):
            self.bin = num
            self.dec = ''
            self.temp = 0
            self.separador = []
            self.Controller()
        else:
            print('Entrada Invalida!')

    def getNumber(self):
        return self.dec
    