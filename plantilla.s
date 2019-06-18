// prj.s
// 22 de Mayo de 2019
// Arqui I UCC

.text

.global main
main:
      LDR R3, = array // load base address of a into R3
      loop:
          MOV R0,#16
          SUBS R0,R0,#1
          LD outpu
          
      BL 
done: NOP            // dummy instruction for breakpoint instruccion boba, que no hace nada
      BX LR          // return from main

.data
array:
      .byte 0x80
      .byte 0x80
      .byte 0x40
      .byte 0x40
      .byte 0x20
      .byte 0x20
      .byte 0x10
      .byte 0x10
      .byte 0x88
      .byte 0x48
      .byte 0x24
      .byte 0x14
      .byte 0x0A
      .byte 0x06
      .byte 0x03
      .byte 0x01
.end


/*
gcc main.c -lncurses -o main
gcc -g plantilla.s -o prueba1

-g 
-o es para generar con el nombre prueba1


debugger: ddd nombre.s, pongo breakpoints en main y done 

*/
