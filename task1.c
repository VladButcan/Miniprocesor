#include <stdio.h>

#define BIT_32 32
#define BIT_16 16
#define FIRSTBIT 7
int main() {
    unsigned int mask = 0, inst = 0, Dim = 0, N = 0;
    int i = 0;

    scanf("%u", &inst);
// creem o masca care are 1 pe 3 cei mai semnificativi biti
    mask = FIRSTBIT << (BIT_32 - 3);
// comparam numarul N cu masca si-i aflam valoarea dup siftare
    N = inst & mask;
    N = N >> (BIT_32 - 3);
    N = N + 1;

    printf("%d ", N);
// numarul initial il sifta la stanga cu 3 pentru a scapa de primii 3 biti
    inst = inst << 3;
// creem o masca care are 1 pe cel mai semnificativ bit
    mask = 1 << (BIT_32 -1);
// aflam cate operatii vom avea in afisare si citim cate 2 biti
    for (i = 0; i < N; i ++) {
        if (inst & mask) {
            inst = (inst << 1);
            if (inst & mask) {
// printeaza '/' daca cei 2 biti cei mai semnificativi sun 11
                printf("/ ");
                inst = inst << 1;
            } else {
// printeaza '*' daca cei 2 biti cei mai semnificativi sun 10
                printf("* ");
                inst = inst << 1;
                }
        } else {
            inst = inst << 1;
            if (inst & mask) {
// printeaza '-' daca cei 2 biti cei mai semnificativi sun 01
                printf("- ");
                inst = inst << 1;
            } else {
// printeaza '+' daca cei 2 biti cei mai semnificativi sun 00
                printf("+ ");
                inst = inst << 1;
            }
        }
    }
// creem o masca pentru cei 4 biti de dupa operatii
    mask = (BIT_16 - 1) << (BIT_32 - 4);
// cei 4 biti acum sunt cei mai semnificativi,deci comparam cu masca creata
    Dim = inst & mask;
    Dim = Dim >> (BIT_32 - 4);
    Dim = Dim + 1;

    printf("%d\n", Dim);

    return 0;
}
