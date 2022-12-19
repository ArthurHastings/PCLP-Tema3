#include "./utils.h"
/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/
#define MAXVAL_VECT 51

struct test {
    unsigned short poz_x, poz_y;
    unsigned char directie;
    unsigned char tip_a;
    unsigned char cod[3];
    unsigned int viteza;
};

struct test test[MAXVAL_VECT];

int comp_types(const void * a, const void * b) {
    const struct test * arg1 = a;
    const struct test * arg2 = b;
    if (arg1->tip_a < arg2->tip_a) {
        return -1;
    } else if (arg1->tip_a > arg2->tip_a) {
        return 1;
    } else {
        if (strcmp(arg1->cod, arg2->cod) < 0) {
            return 1;
        } else if (strcmp(arg1->cod, arg2->cod) > 0) {
            return -1;
        } else {
            if (arg1->viteza < arg2->viteza) {
                return -1;
            } else if (arg1->viteza > arg2->viteza) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

void SolveTask3(void *info, int nr_avioane) {
    void *vect = info;
    int aux = 0;
    for (int i = 0; i < nr_avioane; i++) {
        test[i].poz_x = *(unsigned short *)(vect + aux);
        test[i].poz_y = *(unsigned short *)(vect + aux + sizeof(unsigned short));
        aux += 4;
        test[i].directie = *(unsigned char *)(vect + aux);
        aux += 1;
        test[i].tip_a = *(unsigned char *)(vect + aux);
        aux += 1;
        for (int j = 0; j < 3; j++) {
            test[i].cod[j] = *(unsigned char *)(vect + aux + j);
        }
        aux += 3;
        test[i].viteza = *(unsigned int *)(vect + aux);
        aux += 4;
    }
    qsort(test, nr_avioane, sizeof(struct test), comp_types);

    for (int i = 0; i < nr_avioane; i++) {
        printf("(%hu, %hu)\n", test[i].poz_x, test[i].poz_y);
        printf("%c\n", test[i].directie);
        printf("%c%c%c%c\n", test[i].tip_a, test[i].cod[0], test[i].cod[1], test[i].cod[2]);
        printf("%d\n\n", test[i].viteza);
    }
}
