segment .data
	LF 	      equ 0xA  ; line feed - quebra de linha
	NULL      equ 0xD  ; final da string
	SYS_CALL  equ 0x80 ; envia informação ao SO

	; EAX
	SYS_EXIT  equ 0x1  ; codigo de chamada para finalizar o  programa
	SYS_READ  equ 0x3  ; operacao de leitura
	SYS_WRITE equ 0x4  ; operacao de escrita

	; EBX
	RET_EXIT  equ 0x0  ; operação realizada com sucesso.
	STD_OUT   equ 0x1  ; valor de saida padrao
	STD_IN    equ 0x0  ; indica uma entrada padrao
	
; constantes
section .data
	msg db "hello world", LF, NULL
	tam equ $ - msg

; variaveis
section .bss 
	nome resb 1

section .text

global _start

_start:
	MOV EAX, SYS_WRITE
	MOV EBX, STD_OUT
	MOV ECX, msg
	MOV EDX, tam
	int SYS_CALL

	MOV EAX, SYS_READ
	MOV EBX, STD_IN
    MOV ECX, nome  ; lê um grupo de caracters
    MOV EDX, 0xA   ; com tamanho 0xA -> 10

    MOV EAX, SYS_EXIT
    MOV EBX, RET_EXIT
    int SYS_CALL