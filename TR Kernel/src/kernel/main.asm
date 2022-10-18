org 0x0
bits 16


%define ENDL 0x0D, 0x0A


start:

    pusha
    mov ah, 0x00
    mov al, 0x03
    int 0x10
    popa

    ; print welcome message
    mov si, msg_hello
    call puts

;
; Prints a string to the screen
; Params:
;   - ds:si points to string
;
puts:
    ; save registers we will modify
    push si
    push ax
    push bx

.loop:
    lodsb               ; loads next character in al
    or al, al           ; verify if next character is null?
    jz .done

    mov ah, 0x0E        ; call bios interrupt
    mov bh, 0           ; set page number to 0
    int 0x10

    jmp .loop

.done:
    pop bx
    pop ax
    pop si    
    ret

msg_hello: db 'Welcome to zeqOS Extension 16.05!', 0
