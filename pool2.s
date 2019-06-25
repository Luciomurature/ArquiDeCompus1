.text

.extern outputLED
.extern delayass
.global init_pool


init_pool:
    PUSH {R4-R5, LR}
    MOV R4,#20
pool:
    MOV R1,#128
loop:
     ADD R5,R5,#16
     MOV R0,R5
     BL outputLED
     MOV R0,R4
     BL delayass
     MOV R4,R0
     CMP R4,#0
     BEQ salida
     CMP R5,#32
     BEQ division
     BNE vuelta
  vuelta:
     LSR R5,R5,#1
     CMP R5,#1
     BEQ pool
     BNE loop

division:
     LSR R5,R5,#1
     BAL vuelta
salida:
     POP {R4-R5,PC}
.end