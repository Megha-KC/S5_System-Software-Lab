#include<stdio.h>
#include<string.h>

void main()
{
    FILE *f1, *f2, *f3, *f4, *flen;
    int lc, sa, op1, o, len; // locctr, starting addr, operand, machine code, length of byte string
    char m1[20], la[20], op[20], otp[20]; // mnemonic, label, opcode, opcode in optab
    f1 = fopen("input.txt", "r");
    f3 = fopen("symtab.txt", "w");
    f4 = fopen("out1.txt",  "w");
    fscanf(f1, "%s %s %d", la, m1, &op1);
    if(strcmp(m1, "START")==0) {
        sa = op1;
        lc = sa;
        printf("-\t%s\t%s\t%d\n", la, m1, op1);
        fprintf(f4,  "-\t%s\t%s\t%d\n", la, m1, op1);
    }
    else
        lc = 0;
    fscanf(f1, "%s %s", la, m1);
    while(!feof(f1)) {
        fscanf(f1, "%s", op);
        printf("\n%d\t%s\t%s\t%s\n", lc, la, m1, op);
        fprintf(f4,  "%d\t%s\t%s\t%s\n", lc, la, m1, op);
        if(strcmp(la, "-")!=0)
            fprintf(f3, "\n%d\t%s\n", lc, la);
        f2 = fopen("optab.txt", "r");
        fscanf(f2, "%s %d", otp, &o);
        while(!feof(f2)) { // check if mnemonic opcode is there in optab
            if(strcmp(m1, otp)==0) {
                lc += 3;
                break;
            }
            fscanf(f2, "%s %d", otp, &o);
        }
        fclose(f2);
        if(strcmp(m1, "WORD")==0)
            lc += 3;
        else if(strcmp(m1, "RESW")==0) {
            op1 = atoi(op);
            lc += (3*op1);
        }
        else if(strcmp(m1, "BYTE")==0) {
            if(op[0]=='X') // hex value
                lc += 1;
            else { // char const
                len = strlen(op)-2;
                lc += len;
            }
        }
        else if(strcmp(m1, "RESB")==0) {
            op1 = atoi(op);
            lc += op1;
        }
        fscanf(f1, "%s%s",  la, m1);
    }
    if(strcmp(m1, "END")==0) {
        printf("Program length: %d\n\n",  lc-sa);
        flen = fopen("length.txt",  "w");
        fprintf(flen,  "%d\n",  lc-sa);
        fclose(flen);
    }
    fclose(f1);
    fclose(f3);
    fclose(f4);
}