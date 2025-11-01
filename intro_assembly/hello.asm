; compilar: transformar em linguagem de máquina.
; linkar: transformar o programa de linguagem de máquina em um executável.
; comando compilar -> nasm -f elf64 hello.asm
; linkar -> ld -s -o hello hello.o

section .text
section .data
	msg db "hello world", 0x04
	tam equ $ - msg

global _start
_start:
	MOV ECX, msg
	MOV EDX, tam
	MOV EAX, 4
	MOV EBX, 1
	int 0x80

	MOV EAX, 1 ; SO termina o programa
	MOV EBX, 0 ; SO retorna o valor 0
	int 0x80