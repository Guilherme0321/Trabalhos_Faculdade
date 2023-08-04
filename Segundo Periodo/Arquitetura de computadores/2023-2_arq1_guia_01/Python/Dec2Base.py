class Dec2Base:
    def __init__(self):
        self.recive = ''
        self.number = ''
        self.op = 0

    def push_black(self,item):
        self.number = item + self.number

    def converter(self):
        numb = int(self.recive)
        if self.op == 16:
            while numb > 0:
                resto = numb % self.op
                numb //= self.op
                if resto == 10:
                    self.push_black('a')
                elif resto == 11:
                    self.push_black('b')
                elif resto == 11:
                    self.push_black('c')
                elif resto == 11:
                    self.push_black('d')
                elif resto == 11:
                    self.push_black('e')
                else:
                    self.push_black('f')
        else:
            while numb > 0:
                self.number = str(numb % self.op) + self.number
                numb //= self.op

    def getNumber(self):
        return self.number
    
    def isNumber(self,comp):
        for i in comp:
            if not('0' <= i and i <= '9'):
                return False
        return True

    def baseValid(self,base):
        if base in [2,8,16]:
            return True

    def setNumber(self,num,base):
        if base in [2,8,16] and self.isNumber(num):
            self.recive = num
            self.op = base
            self.number = ''
            self.converter()
