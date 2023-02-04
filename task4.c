#include <stdio.h>
#include <stdint.h>

#define BIT_32 32
#define BIT_16 16
#define FIRSTBIT 7
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
int main() {
    unsigned int mask = 0, inst = 0, Dim = 0, N = 0, nroperanzi = 0;

    int i = 0, Dim2 = 0;
    scanf("%u", &inst);
// creem o masca care are 1 pe 3 cei mai semnificativi biti
    mask = FIRSTBIT << (BIT_32 - 3);
// comparam numarul N cu masca si-i aflam valoarea dup siftare
    N = inst & mask;
    N = N >> (BIT_32 - 3);
    N = N + 1;

    int vop[N + 1];

// numarul initial il sifta la stanga cu 3 pentru a scapa de primii 3 biti
    inst = inst << 3;
// creem o masca care are 1 pe cel mai semnificativ bit
    mask = 1 << (BIT_32 -1);
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
            if ((inst & mask) == 0) {
                inst = inst << 1;
                if (inst & mask) {
// in vectorul operatiilor pe pozitia i se trece '-'
                    vop[i] = '-';
                    inst = inst << 1;
                } else {
                    if ((inst & mask) == 0) {
// in vectorul operatiilor pe pozitia i se trece '+'
                        vop[i] = '+';
                        inst = inst << 1;
                    }
                }
            }
        }
    }
// creem o masca pentru cei 4 biti de dupa operatii
    mask = (BIT_16 -1) << (BIT_32 -4);
// cei 4 biti acum sunt cei mai semnificativi,deci comparam cu masca creata
    Dim = inst & mask;
    Dim = Dim >> (BIT_32 - 4);
    Dim = Dim + 1;
    Dim2 = (int)Dim;
// deducem cati operanzi vom avea folosind variabila nroperanzi
    if (((N + 1) * Dim) % BIT_16 == 0) {
        nroperanzi = ((N + 1) * Dim) / BIT_16;
    } else {
        nroperanzi = (((N + 1) * Dim) / BIT_16) + 1;
    }

    uint16_t numere = 0, mask3 = 0, op = 0;
    unsigned int sum = N + 1, v[sum];
    int j = 0;
    unsigned int v2[Dim], nrintrari = 0, nr = 0;

// vom citi de la tastatura 'nroperanzi' numere
    int c1 = 0, c2 = 0;

    mask3 = 1 << (BIT_16 - 1);

    for (i = 0; i < Dim; i++)
        v2[i] = 0;

    int dimactuala = 0, z = 0, m = 0;
    int c3 = 0;

    dimactuala = BIT_16 / Dim;
    nrintrari = dimactuala;
// vom citi nroperanzi numere
    for (i = 0; i < nroperanzi; i ++) {
        scanf("%hu", &numere);
// intram pe Dim biti ai primului vector
        for (z = 0; z < nrintrari; z ++) {
            if (z <= N) {
                if (c2 <= N) {
                    op = 0;
// daca c1 = 0 atunci vom forma operandul
// daca c1 != 0 atunci vom pune bitii in vector de pe pozitia c1
                    for (j = c1; j < Dim2; j++) {
                        if ((numere & mask3) != 0) {
                            v2[j] = 1;
                        } else {
                            v2[j] = 0;
                        }
                        numere = numere << 1;
                        c3++;
                    }
// formam operandul conform bitilor din vector
                    for (j = Dim2 - 1; j >= 0; j--) {
                        m = Dim2 - j - 1;
                        op = putere(2, m) * v2[j] + op;
                    }

                    v[c2] = op;
                    c2++;
                }
            }
            c1 = 0;
        }
// verificam daca au ramas biti care nu au format un operand
        if (Dim * dimactuala < BIT_16) {
            c1 = BIT_16 - c3;
// punem bitii nefolositi pe primele c1 pozitii
            for (j = 0; j < c1; j ++) {
                if ((numere & mask3) != 0) {
                    v2[j] = 1;
                } else {
                    v2[j] = 0;
                }
                numere = numere << 1;
            }
        } else {
// calculam de cate ori vom intra in for pentru a crea un vector
            if (Dim * dimactuala == BIT_16) {
                c1 = 0;
            }
        }
        if (c1 == 0) {
            nrintrari = BIT_16 / Dim;
        } else {
            if (Dim - c1 + Dim < BIT_16) {
                nrintrari = 0;
                nr = nr + Dim - c1;
                while (nr < BIT_16) {
                    nr = nr + Dim;
                    nrintrari++;
                }
            } else {
                nrintrari = 1;
            }
        }
        c3 = 0;
    }
// pentru inceput facem operatiile de inmultire si de impartire
    for (i = 0; i < N; i++) {
        if (vop[i] == '*') {
            v[i + 1] = v[i] * v[i + 1];
            for (j = i; j < N; j ++)
                v[j] = v[j + 1];

            N = N - 1;

            for (j = i; j < N; j ++)
                vop[j] = vop[j + 1];

            i = i - 1;
        }
        if (vop[i] == '/') {
            v[i + 1] = v[i] * v[i + 1];

            for (j = i; j < N; j ++)
                v[i + 1] = v[i + 2];

            N = N - 1;

            for (j = i; j < N; j ++)
                vop[i] = vop[i + 1];

            i = i - 1;
        }
    }
// creem rezultatul format in urma operatiilor cu adunare si scadere
    for (i = 0; i < N ; i ++) {
        if (vop[i] == '+') {
            v[i + 1] = v[i] + v[i + 1];
        }

        if (vop[i] == '-') {
            v[i + 1] = v[i] - v[i + 1];
        }
    }
    printf("%d\n", v[N]);

    return 0;
}
