.model small
.386

.code
.startup

; input 1st number 
mov cx,8
mov ebx,0
mov eax,0
l1:
    shl ebx,4
    mov ah,01
    int 21h
    sub al,30h
    cmp al,39h
    jbe l2
    sub al,37h   
    
    l2:
    add bl,al
    
loop l1

mov dl, 10
mov ah, 02
int 21h

; 2nd number
mov cx,8
mov edx,0
l3:
    shl edx,4
    mov ah,01
    int 21h
    sub al,30h
    cmp al,39h
    jbe l4
    sub al,37h   
    
    l4:
    add dl,al
    
loop l3

adc ebx,edx   ; add operation

mov dl, 10
mov ah, 02  
int 21h

;output sum
mov cx,8
l5:
    rol ebx,4
    mov dl,bl
    and dl,0fh
    add dl,30h
    cmp dl,39h
    jbe l6
    add dl,7h

    l6:
    mov ah,02
    int 21h 
loop l5

.exit
end

