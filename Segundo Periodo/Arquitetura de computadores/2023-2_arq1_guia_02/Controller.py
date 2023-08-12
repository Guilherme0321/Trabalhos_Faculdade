from Python.bin2double import Operacoes
from Python.double2bin import double2bin

def exercicio01():
    op = Operacoes()
    x = input('Digite um numero em binario: ')
    op.setBin_Number(x)
    print(op.getNumber())


def exercicio02():
    x = double2bin()
    y = input('Digite um numero real em decimal: ')
    x.setNumber(y)
    print(x.getNumber())

option = -1

while option != 0:
    option = int(input('0 - sair do loop\n1 - exercicio 1\n2 - exercicio 2\n'))
    if option == 0:
        continue
    elif option == 1:
        exercicio01()
    elif option == 2:
        exercicio02()
    else:
        print('Opção invalida!')