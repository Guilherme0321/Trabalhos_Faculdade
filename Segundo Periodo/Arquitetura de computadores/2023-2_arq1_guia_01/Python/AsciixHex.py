class AsciixHex:
    def to_int(self, num):
        len_num = len(num)
        temp = 0
        for i in range(len_num):
            temp += (int(num[i]) - 0) * (10 ** (len_num - i - 1))
        return temp

    def to_lowercase(self, upper):
        temp = ""
        for c in upper:
            if 'A' <= c <= 'Z':
                c = chr(ord(c) + 32)
            temp += c
        return temp

    def to_decimal(self, num):
        num = self.to_lowercase(num)
        len_num = len(num)
        decimal = 0
        for i in range(len_num):
            num_char = num[i]
            if 'a' <= num_char <= 'f':
                decimal += (ord(num_char) - ord('a') + 10) * (16 ** (len_num - i - 1))
            else:
                decimal += (int(num_char) - 0) * (16 ** (len_num - 1 - i))
        return str(decimal)

    def to_hex(self, num):
        temp = ""
        numero = self.to_int(num)
        resto = 0
        while numero > 0:
            resto = numero % 16
            numero //= 16
            if resto == 10:
                temp = 'a' + temp
            elif resto == 11:
                temp = 'b' + temp
            elif resto == 12:
                temp = 'c' + temp
            elif resto == 13:
                temp = 'd' + temp
            elif resto == 14:
                temp = 'e' + temp
            elif resto == 15:
                temp = 'f' + temp
            else:
                temp = str(resto) + temp
        return temp

    def dec_to_hex(self, recive):
        temp = ""
        number = ""
        for char in recive:
            if char != ' ' and char != '\n' and char != '\0':
                temp += char
            else:
                if temp:
                    number += self.to_hex(temp) + " "
                    temp = ""
        if temp:
            number += self.to_hex(temp)
        return number

    def ascii_to_decimal(self, ascii_str):
        temp_number = ""
        for char in ascii_str:
            if char != '\n' and char != '\0':
                temp_number += ' ' + str(ord(char))
        return temp_number

    def ascii_to_hexa(self, recive):
        temp = ""
        temp = self.ascii_to_decimal(recive)
        print("DECIMAL:", temp)
        temp = self.dec_to_hex(temp)
        print("HEXADECIMAL:", temp)

    def add(self, arr, append):
        arr_length = len(arr)
        arr2 = arr.copy()
        arr2.append(append)
        return arr2

    def print_array(self, arr):
        print(" ".join(arr))

    def to_covert(self, recive):
        temp = ""
        len_recive = len(recive)
        arr = []
        for i in range(len_recive):
            if recive[i] != ' ' and recive[i] != '\n' and recive[i] != '\0':
                temp += recive[i]
            else:
                if temp:
                    arr = self.add(arr, temp)
                    temp = ""
        if temp:  # Añadir este bloque para manejar el último elemento
            arr = self.add(arr, temp)
        return arr

    def to_string(self, arr):
        out = ""
        for item in arr:
            out += chr(self.to_int(item))
        return out

    def hexa_to_ascii(self, recive):
        arr = self.to_covert(recive)
        arr = [self.to_decimal(item) for item in arr]
        print("Decimal:", arr)
        print("Ascii:", self.to_string(arr))

        


