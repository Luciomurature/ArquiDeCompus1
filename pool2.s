.text

.extern outputLED
.extern delayc
.global inicializar


init_pool:
    MOV R2,#20
pool:
    MOV R1,#128
loop:
     ADD R1,R1,#16
     MOV R0,R1
     LD outputLED
     MOV R1,R0
     MOV R0,R2
     BL outputLED
     MOV R2,R0
     CMP R1,#32
     BEQ LSR R1
     LSR R1
     CMP R1,#1
     BEQ pool
     BNE loop
.end