#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    void *vect = info;
    int aux = 0;
    for (int i = 0; i < nr_avioane; i++) {
        printf("(%hu, %hu)\n", *(unsigned short *)(vect + aux),
        *(unsigned short *)(vect + aux + sizeof(unsigned short)));
        aux += 4;
        printf("%c\n", *(unsigned char *)(vect + aux));
        aux += 1;
        for (int j = 0; j < 4; j++) {
            printf("%c", *(unsigned char *)(vect + aux + j));
        }
        aux += 4;
        printf("\n");
        printf("%hi\n\n", *(unsigned int *)(vect + aux));
        aux += 4;
    }
}
