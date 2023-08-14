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
                self.separador.append(self.paddingLeft(temp))
                temp = ''
        self.separador.append(self.paddingRight(temp))
    
    def toHex(self,num: str, start: int, end: int) -> str:
        i: int = start
        temp: int = 0
        resul: str = ''
        while i < end:
            if num[i] != '0':
                temp += int(num[i]) * pow(2,end -1 -i)
            i += 1

        if temp > 9 and self.base == 16:
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
                
    def toRealHex(self, num: str, start: int, end: int) -> str:
        temp = 0.0
        count = 1  # Start count at 1 for 2^-1 (0.5)
        resul = ''
        
        while start < end:
            temp += int(num[start]) * pow(2, -count)
            start += 1
            count += 1

        if self.base == 16:
            hex_chars = "0123456789abcdef"
            int_part = int(temp)
            frac_part = temp - int_part
            hex_int_part = str(int_part)
            hex_frac_part = ''
            
            while frac_part > 0:
                frac_part *= 16
                hex_digit = int(frac_part)
                hex_frac_part += hex_chars[hex_digit]
                frac_part -= hex_digit
            
            if hex_frac_part:
                resul = hex_int_part + '.' + hex_frac_part
            else:
                resul = hex_int_part
        else:
            resul = str(temp)
            
        return resul[2:]

        
    
    def converterInt(self,num: str,counter: int=4):
        if len(num) % counter != 0:
            num = self.paddingLeft(num,counter)
        start: int = 0
        end: int = start + counter
        length: int = len(num)
        for i in range(length//counter):
            self.number += self.toHex(num=num,start=start,end=end)
            start = end
            end += counter
            
    def separardoPonto(self,num: str) -> str:
        temp: str = ''
        passed: bool = False
        i: int = 0
        for i in num:
            if passed:
                temp += i
            if i == '.':
                passed = True
        return num

            
    def converterRealInt(self,num: str, counter: int = 4):
        if len(num) % counter != 0:
            num = self.paddingRight(num,counter)
        start: int = 0
        end: int = start + counter
        length: int = len(num)
        for i in range(length//counter):
            self.number += self.separardoPonto(self.toRealHex(num,start,end))
            start = end
            end += counter


    def isBinary(self,num: str) -> bool:
        isbinario: bool = True
        for i in range(len(num)):
            if num[i] != '0' and num[i] != '1' and num[i] != '.' and num[i] != ',':
                isbinario = False
                i = len(num)
                
        return isbinario
    
    def paddingLeft(self,num: str,counter: int = 4) -> str:
        while len(num) % counter != 0:
            num = '0' + num
        return num
            
    def paddingRight(self, num: str,counter: int = 4) -> str:
        while len(num) % counter != 0:
            num += '0'
        return num
    
    def setNumber(self,num: str, base: int):
        if self.isBinary(num):
            self.bin = num
            self.base = base
            self.number = ''
            self.separador = []
            self.sepArray()
            if base == 16:
                self.converterInt(num=self.separador[0],counter=4)
                self.number += '.'
                self.converterRealInt(num=self.separador[1],counter=4)

            elif base == 8:
                self.converterInt(num=self.separador[0],counter=3)
                self.number += '.'
                self.converterRealInt(num=self.separador[1],counter=3)


            elif base == 4:
                self.converterInt(num=self.separador[0],counter=2)
                self.number += '.'
                self.converterRealInt(num=self.separador[1],counter=2)

            
            else:
                print('Base invalida!')
            print(self.number)
        else:
            print('Formato invalido!')
        
