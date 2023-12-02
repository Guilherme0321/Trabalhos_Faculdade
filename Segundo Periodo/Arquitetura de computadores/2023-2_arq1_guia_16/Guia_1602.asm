# ORG 2000H        

# BEGIN 2000H       
	   LHLD 2501        ; Carrega o par de registros L e H com o valor armazenado no endereço 2501H
	   LDA 2503     ; Carrega o acumulador (registrador A) com o valor armazenado no endereço 2503H
	   MOV B,A     ; Move o conteúdo do registrador A para o registrador B
	   MVI C,08     ; Move o valor imediato 08 para o registrador C

LOOP:	   DAD H     ; Adiciona o conteúdo dos registradores D e H (H,L) ao par de registros HL
	   MOV A,H   ; Move o conteúdo do registrador H para o registrador A
	   SUB B        ; Subtrai o conteúdo do registrador B do registrador A
	   JC AHEAD      ; Salta para o rótulo AHEAD se a condição de carry (JC - Jump on Carry) for verdadeira
	   MOV H,A      ; Move o conteúdo do registrador A para o registrador H
	   INR L    ; Incrementa o registrador L

AHEAD:	   DCR C          ; Decrementa o registrador C
	   JNZ LOOP     ; Salta de volta para LOOP se o registrador C não for zero
	   SHLD 2504  ; Armazena o conteúdo dos registradores L e H no endereço 2504H
	   HLT      ; Halt - instrução de parada, encerrando a execução do programa

# ORG 2501H         ; Define o endereço de origem (2501H) para os dados
# DB 9BH,48H,1AH    ; Define os dados em hexadecimal: 9BH, 48H, 1AH
