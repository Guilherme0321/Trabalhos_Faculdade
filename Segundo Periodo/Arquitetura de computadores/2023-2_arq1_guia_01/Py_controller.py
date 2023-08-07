from Python.toBinary import ToBinary
from Python.toDecimal import ToDeciamal
from Python.Dec2Base import Dec2Base
from Python.Bin2Base import Bin2Base
from Python.AsciixHex import AsciixHex

converterB = ToBinary()
converterD = ToDeciamal()
decTobase = Dec2Base()
binTobase = Bin2Base()
AcXHex = AsciixHex()

def Exercicio01():
    while True:
        number = input("\n\nDIGITE 0 PARA SAIR DO LOOP!\nNumero em decimal para ser convertido em binario: ")
        if number == '0':
            break
        elif converterB.isNumber(number):
            converterB.setNumber(number)
            print(converterB.getNumber())
        else:
            continue

def Exercicio02():
    while True:
        number = input("\n\nDIGITE 0 PARA SAIR DO LOOP!\nNumero em binario para ser convertido em decimal: ")
        if number == '0':
            break
        elif converterD.isBinary(num=number):
            converterD.setNumber(num=number)
            print(converterD.getNumber())
        else:
            print('\n\nNúmero não binário!')
            continue


def Exercicio03():
    while True:
        number = input("\n\nDIGITE 0 PARA SAIR DO LOOP!\nNumero em decimal: ")
        if number == '0':
            break
        op = int(input("Converter para a base: "))
        if decTobase.isNumber(number) and decTobase.baseValid(op):
            decTobase.setNumber(number,op)
            print(decTobase.getNumber())
        else:
            print('\n\nNúmero não binário ou base invalida!')

def Exercicio04():
    while True:
        number = input('\n\nDIGITE 0 PARA SAIR DO LOOP!\nNumero em binário: "')
        if number == '0':
            break
        op = int(input('Converter para a base: '))
        if binTobase.isBInary(number) and binTobase.baseisValid(op):
            binTobase.setNumber(number,op)
            print(binTobase.getNumber())
        else:
            print('\n\nNúmero não binário ou base invalida!')

def Exercicio05():
    recive = ""
    while True:
        while True:
            print("\n\n0 - sair do loop\n 1 - Ascii => Hexadecimal\n 2 - Hexadeciaml => Ascii")
            op = int(input("Option: "))
            if op == 0:
                break
            elif op == 1:
                recive = input("String para converter para Ascii(16): ")
                input("Aperte enter!")
                AcXHex.ascii_to_hexa(recive)
            elif op == 2:
                recive = input("Ascii(16) para converter para String: ")
                input("Aperte enter!")
                AcXHex.hexa_to_ascii(recive)
            input("Aperte enter!")

while True:
    choice = int(input('0 - Termina o loop\n1 - Exercício 01\n2 - Exercício 02\n3 - Exercício 03\n4 - Exercicío 04\n5 - Exercicío 05\nOpção: '))
    if choice == 0:
        break
    elif choice == 1:
        Exercicio01()
    elif choice == 2:
        Exercicio02()
    elif choice == 3:
        Exercicio03()
    elif choice == 4:
        Exercicio04()
    elif choice == 5:
        Exercicio05()
    else:
        print('\nOpção invalida!\n')
        continue