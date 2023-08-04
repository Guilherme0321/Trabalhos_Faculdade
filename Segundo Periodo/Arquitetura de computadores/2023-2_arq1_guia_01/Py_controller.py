from Python.toBinary import ToBinary
from Python.toDecimal import ToDeciamal
from Python.Dec2Base import Dec2Base

converterB = ToBinary()
converterD = ToDeciamal()
decTobase = Dec2Base()
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

        

while True:
    choice = int(input('0 - Termina o loop\n1 - Exercício 01\n2 - Exercício 02\n3 - Exercício 03\nOpção: '))
    if choice == 0:
        break
    elif choice == 1:
        Exercicio01()
    elif choice == 2:
        Exercicio02()
    elif choice == 3:
        Exercicio03()
    else:
        print('\nOpção invalida!\n')
        continue