class bin2base:
    def __init__(self):
        self.bin: str = ''
        self.number: str = ''
        self.separador = []
        self.base: int = 0
    
    def sepArray(self):
        temp: str = ''
        if ',' in self.bin:
            self.bin = self.bin.replace(',','.')
        for i in self.bin:
            if i != '.' and i != '\n' and i != '\0':
                temp += i
            else:
                self.separador.append(self.padding(temp))
                temp = ''
        self.separador.append(temp)
    
    def toHex(self,num: str, start: int, end: int) -> str:
        i: int = start
        temp: int = 0
        resul: str = ''
        while i < end:
            if num[i] != '0':
                temp += int(num[i]) * pow(2,end -1 -i)
            i += 1
        if temp > 9:
            if temp == 10:
                resul = 'a'
            elif temp == 11:
                resul = 'b'
            elif temp == 12:
                resul = 'c'
            elif temp == 13:
                resul = 'd'
            elif temp == 14:
                resul = 'e'
            elif temp == 15:
                resul = 'f'
        else:
            resul = str(temp)
        return resul
                
    
    def converterInt(self,num: str,counter: int=4):
        if len(num) % counter != 0:
            num = self.padding(num)
        start: int = 0
        end: int = start + counter
        length: int = len(num)
        for i in range(length//counter):
            self.number += self.toHex(num=num,start=start,end=end)
            start = end
            end += counter
            
            
    def isBinary(self,num: str) -> bool:
        isbinario: bool = True
        for i in range(len(num)):
            if num[i] != '0' and num[i] != '1' and num[i] != '.' and num[i] != ',':
                isbinario = False
                i = len(num)
                
        return isbinario
    
    #def after_toBase(self):
    
    def padding(self,num: str,counter: int = 4) -> str:
        while len(num) % counter != 0:
            num = '0' + num
        return num
            
    
    def setNumber(self,num: str, base: int):
        if self.isBinary(num):
            self.bin = num
            self.base = base
            self.number = ''
            self.separador = []
            self.sepArray()
            self.converterInt(num=self.separador[0],counter=4)
            print(self.number)
        else:
            print('Formato invalido!')
        
x = bin2base()
x.setNumber('11010,01',2)