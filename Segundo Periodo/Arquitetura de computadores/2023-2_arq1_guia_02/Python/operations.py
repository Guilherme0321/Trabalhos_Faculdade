class Operacoes:
    def __init__(self):
        self.num1 = []
        self.num2 = []
        self.op = ''

    def toDecimal(self):
        temp: str = self.num1[0]
        LenTemp = len(temp)
        temp2: str = self.num1[1]
        LenTemp2 = len(temp2)

        temp3: str = self.num2[0]
        lenTemp3: int = len(temp3)
        temp4: str = self.num2[1]
        lenTemp4: int = len(temp4)

        self.num1[0] = 0
        self.num2[0] = 0
        i: int = 0
        while i < LenTemp:
            self.num1[0] += int(temp[i]) * pow(2,LenTemp -1 -i)
            i += 1
        i = 0
        while i < lenTemp3:
            self.num2[0] += int(temp3[i]) * pow(2,lenTemp3 -1 -i)
            i += 1
        i = 0
        self.num1[1] = 0
        self.num2[1] = 0
        while i < LenTemp2:
            self.num1[1] += int(temp2[i]) * pow(2,-i-1)
            i += 1
        i = 0
        while i < lenTemp4:
            self.num2[1] += int(temp4[i]) * pow(2,-i-1)
            i += 1

    def arraySep(self,num: str, array):
        if ',' in num:
            num = num.replace(',','.')
        temp: str = ''
        for i in num:
            if i != '.':
                temp += i
            else:
                array.append(temp)
                temp = ''
        array.append(temp)

    def toNumber(self,array) -> float:
        return int(array[0]) + float(array[1])

    def setNumber(self,num: str, op: str, num2: str) -> float:
        self.arraySep(num,self.num1)
        self.arraySep(num2,self.num2)
        self.op = op
        self.toDecimal()
        result: float = 0.0
        if op == '+':
            result = self.toNumber(self.num1) + self.toNumber(self.num2)
        elif op == '-':
            result = self.toNumber(self.num1) - self.toNumber(self.num2)
        elif op == '*':
            result = self.toNumber(self.num1) * self.toNumber(self.num2)
        elif op == '/':
            result = self.toNumber(self.num1) / self.toNumber(self.num2)
        elif op == '%':
            result = self.toNumber(self.num1) % self.toNumber(self.num2)
        else:
            print('Operador invalido')
        print(result)
        


