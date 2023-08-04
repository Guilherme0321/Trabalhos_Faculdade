from Python.toBinary import ToBinary
from Python.toDecimal import ToDeciamal

converterB = ToBinary()
converterD = ToDeciamal()

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


while True:
    choice = int(input('0 - Termina o loop\n1 - Exercício 01\n2 - Exercício 02\nOpção: '))
    if choice == 0:
        break
    elif choice == 1:
        Exercicio01()
    elif choice == 2:
        Exercicio02()
    else:
        print('\nOpção invalida!\n')
        continue