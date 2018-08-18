.MODEL SMALL
.386
.DATA
   M1 DB ?
   M2 DB ?
   M3 DB ?
   M4 DB ?

.CODE 
.STARTUP
    
  MOV AX,1234H
  MOV BX,7032H
  MOV CX,1282H
  MOV DX,2346H

  ADD AL,CL
  DAA
  MOV M1,AL

  MOV AL,AH
  ADC AL,CH
  DAA
  MOV M2,AL

  MOV AL,BL
  ADC AL,DL
  DAA
  MOV M3,AL

  MOV AL,BH
  ADC AL,DH
  DAA
  MOV M4,AL

  MOV AH,M4
  MOV AL,M3
  CALL DISPH

  MOV AH,M2
  MOV AL,M1
  CALL DISPH

.EXIT



;Procedure to display EAX as a 8 digit hex number
DISPH PROC NEAR
   PUSH EBX        ; Save EBX
   MOV CL,4        ; To rotate the register by 4 bits
   MOV SI,4        ; Count for displaying 8 digits
DISPH1:
   ROL AX,CL      ; Rotate EAX left by 4 bits
   PUSH AX        ; Save EAX
   AND AL,0FH
   ADD AL,30H
   CMP AL,'9'      ; if AL <= '9', AL contains the ASCII code
   JBE DISPH2       
   ADD AL,7        ; if AL > '9' , add 07H to AL to convert into ASCII
DISPH2:
   MOV AH,2H       ; O/P subprogram
   MOV DL,AL       ; Call MS-DOS O/P subprogram
   INT 21H         ; Display the data in DL register on screen
   POP AX         ; retrieve EAX from Stack
   DEC SI
   JNZ DISPH1
   POP EBX         ; Restore EBX
   RET
DISPH ENDP

   END             ; end of file
   