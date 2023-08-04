planilha = [
]

with open('exercicio01/textos.txt','rt') as archive:
    dados = archive.readline()
    excessoes = [' ', '','|','\n','\0']
    while dados != '':
        newColumn = []
        frases = ''
        for i in range(len(dados)):
            if dados[i] not in excessoes:
                frases += dados[i]
            else:
                if frases != '':
                    newColumn.append(frases)
                    frases = ''
        planilha.append(newColumn)
        dados = archive.readline()

def lengthSpace(plan):
    length = 1
    for i in plan:
        for j in i:
            if len(j) > length:
                length = len(j)
    return length
    
space = lengthSpace(planilha)
for i in planilha:
    for s in range(space*len(planilha[0])*2):
        print('-',end="")
    print()
    for j in i:
        while len(j) < space:
            j += ' '
        j = f' {j} '
        print(f'{j}',end="|")
    print()