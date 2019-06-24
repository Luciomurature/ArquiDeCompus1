// prj.s
// 22 de Mayo de 2019
// Arqui I UCC
.text

.extern outputLED
.extern delayc
.global inicializar



inicializar:
    MOV R1,#0
    MOV R2,#20
loop:
     LDR R3, = array // load base address of a into R3
     LDRB R3,[R3,R1]
     ADD R1,R1,#1
     MOV R0,R1
     BL outputLED
     MOV R0,R2
     BL delayc
     MOV R2,R0
     AL loop

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
gcc -g carrera2.s -o prueba1

-g
-o es para generar con el nombre prueba1


debugger: ddd nombre.s, pongo breakpoints en main y done

*/

