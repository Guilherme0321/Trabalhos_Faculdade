LXI H,C050 ; HL = endereço de 2501
MOV C,M ; copiando o conteudo de memória para B
MOV B,C
INX H ; como se estivesse indo para a segundo posição do array com o segundo valor ou seja o do endereço 2502
MOV C,M ; copiando o conteudo de memória para C
MVI A,00H 
SOMAR: 
    ADD B ; similar A += B
    DCR C ; decrementa c ou seja c = c -1
    JNZ SOMAR ; pula para a linha somar até C seja == 0

INX H ; agora endereço 2503
MOV M,A ; agora no endereço 2503 tem o valor de A

HLT