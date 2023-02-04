#include <stdio.h>
#include <stdint.h>

// vom folosi un subprogram pentru puterile unui numar
unsigned int putere(unsigned int n, unsigned int m) {
    unsigned int cpn = 0, cpm = 0;
    cpn = n;
    cpm = m;
    if (cpm == 0)
        return 1;
    if (cpm == 1) {
        return n;
    } else {
        while (cpm > 1) {
            n = n * cpn;
            cpm = cpm - 1;
        }
    }
    return n;
}


#define BIT_32 32
#define BIT_16 16
#define FIRSTBIT 7

int main() {
    unsigned int mask = 0, inst = 0, Dim = 0, N = 0, nroperanzi = 0;

    int i = 0;

    scanf("%u", &inst);
// creem o masca care are 1 pe 3 cei mai semnificativi biti
    mask = FIRSTBIT << (BIT_32 - 3);
// comparam numarul N cu masca si-i aflam valoarea dup siftare
    N = inst & mask;
    N = N >> (BIT_32 - 3);
    N = N + 1;

    int vop[N];

// numarul initial il sifta la stanga cu 3 pentru a scapa de primii 3 biti
    inst = inst << 3;
// creem o masca care are 1 pe cel mai semnificativ bit
    mask = 1 << (BIT_32 - 1);
// aflam cate operatii vom avea in afisare si citim cate 2 biti
    for (i = 0; i < N; i ++) {
        if (inst & mask) {
            inst = (inst << 1);
            if (inst & mask) {
// in vectorul operatiilor pe pozitia i se trece '/'
                vop[i] = '/';
                inst = inst << 1;
            } else {
// in vectorul operatiilor pe pozitia i se trece '*'
                vop[i] = '*';
                inst = inst << 1;
            }
        } else {
            inst = inst << 1;
            if (inst & mask) {
// in vectorul operatiilor pe pozitia i se trece '-'
                vop[i] = '-';
                inst = inst << 1;
            } else {
// in vectorul operatiilor pe pozitia i se trece '+'
                vop[i] = '+';
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
// deducem cati operanzi vom avea folosind variabila nroperanzi
    if (((N + 1) * Dim) % BIT_16 == 0) {
        nroperanzi = ((N + 1) * Dim) / BIT_16;
    } else {
        nroperanzi = (((N + 1) * Dim) / BIT_16) + 1;
    }
    uint16_t  numere = 0, op = 0, mask2 = 0;
    int CPDim = 0, v[BIT_16], c = 0, j = 0;
// creem o copie pentru Dim pentru a nu-i pierde valoarea
    CPDim = (int)Dim;
// creem o masca pe 16 biti in dependenta de valoare lui Dim
    if (CPDim == 1)
        mask2 = 1;

    if (CPDim == 2) {
        mask2 = 3;
    } else {
        if (CPDim != 1) {
            while (CPDim >= 0) {
                    mask2 = mask2 + putere(2, CPDim);
                    CPDim = CPDim - 1;
                }
        }
    }

    mask2 = mask2 << (BIT_16 - Dim);

// vom citi de la tastatura 'nroperanzi' numere
    for (i = 0; i < nroperanzi; i ++) {
        scanf("%hu", &numere);
// bitii numarului citit ii vom grupa in functie de valoarea lui Dim
        for (j = 0; j < BIT_16 / Dim; j ++) {
            op = numere & mask2;
            if (op != 0) {
                numere = numere << Dim;
                op = op >> (BIT_16 - Dim);
// numarul format dupa gruparea primilor 'Dim' biti il punem intr-un vector
                v[c] = op;
                c = c + 1;
            } else {
                v[c] = 0;
                c = c + 1;
                numere = numere << Dim;
            }
        }
    }
// creem rezultatul format in urma operatiilor cu operanzi
    for (i = 0; i < N; i++) {
        if (vop[i] == '*') {
            v[i + 1] = v[i] * v[i + 1];
        }

        if (vop[i] == '+') {
            v[i + 1] = v[i] + v[i + 1];
        }

        if (vop[i] == '-') {
            v[i + 1] = v[i] - v[i + 1];
        }

        if (vop[i] == '/') {
            v[i + 1] = v[i] / v[i + 1];
        }
    }

    printf("%d\n", v[N]);

    return 0;
}
