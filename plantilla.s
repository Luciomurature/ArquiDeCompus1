// prj.s
// 22 de Mayo de 2019
// Arqui I UCC

.text

.global main
main:
      LDR R3, =array // load base address of a into R3
      ... more code here
done: NOP            // dummy instruction for breakpoint instruccion boba, que no hace nada
      BX LR          // return from main

.data
array:
      .byte 0x08
      .byte 0x10
      .byte 0xFF
      ... more data here
.end


/*
gcc main.c -lncurses -o main
gcc -g plantilla.s -o prueba1

-g 
-o es para generar con el nombre prueba1


debugger: ddd nombre.s, pongo breakpoints en main y done 


10000001
11000001
10100001
10010001
10001001
10000101
10000011

11000111
11001011
11010011
11100011






*/
