#include <iostream>

int main()
{
    unsigned char A = 50;
    short int B = 100, C = 90;
    int D;//D = A ^ 3 + B;
    int E;//E = C ^ 2 * (B - C) / B

    printf("A=%d, B=%d C=%d\n", A, B, C);
    printf("A=%x, B=%x C=%x\n", A, B, C);
    __asm {
    mov AL, A
    imul AL
    mov BX, AX
    mov AL, A
    cbw
    imul BX
    mov word ptr D, AX
    mov word ptr D+2, DX
    mov EBX, D
    mov AX,B
    cwde
    add  EBX, EAX
    mov D, EBX

    mov  AX, C
    imul AX
    mov word ptr E, AX
    mov word ptr E+2, DX
    mov AX, B
    sub AX, C
    cwde

    mov EBX, E
    imul EBX
    mov BX, B
    movsx EBX, BX

    idiv EBX
    mov E,EAX
    }
    printf("\nD=%d, E=%d", D, E);
    printf("\nD=%x, E=%x\n", D, E);


    return 0;
    }