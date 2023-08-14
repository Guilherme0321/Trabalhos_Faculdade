from Python.bin2double import Operacoes
from Python.double2bin import double2bin
from Python.bin2base import bin2base
from Python.dbase2base import dbase2base
from Python.operations import Operacoes

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


def exercicio03():
    x = bin2base()
    y = input("Digite o numero em binario: ")
    z = int(input('Base: '))
    x.setNumber(y,z)

def exercicio04():
    x = int(input('Numero: '))
    base = int(input('Base do numero escrito: '))
    tobase = int(input('Converter para a base: '))
    print(dbase2base(base,tobase,x))

def exercicio05():
    x = Operacoes()
    n1 = input('Numero em binario: ')
    op = input('Operação: ')
    n2 = input('Outro numero binario: ')
    x.setNumber(n1,op,n2)

option = -1

while option != 0:
    option = int(input('0 - sair do loop\n1 - exercicio 1\n2 - exercicio 2\n3 - exercicio 3\n4 - exercicio 4\n5 - exercicio 5\n'))
    if option == 0:
        continue
    elif option == 1:
        exercicio01()
    elif option == 2:
        exercicio02()
    elif option == 3:
        exercicio03()
    elif option == 4:
        exercicio04()
    elif option == 5:
        exercicio05()
    else:
        print('Opção invalida!')