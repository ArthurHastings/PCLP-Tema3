#include "./utils.h"

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    void *vect = info;
    int aux = 0;
    unsigned short poz_x = 0, poz_y = 0;
    unsigned char directie = 0;
    unsigned char tip_a = 0;
    for (int i = 0; i < nr_avioane; i++) {
        poz_x = *(unsigned short *)(vect + aux);
        poz_y = *(unsigned short *)(vect + aux + sizeof(unsigned short));
        aux += 4;
        directie = *(unsigned char *)(vect + aux);
        aux += 1;
        tip_a = *(unsigned char *)(vect + aux);
        aux += 4;
        aux += 4;
        if (tip_a == '1') {
            if (directie == 'N') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x+1][poz_y-2] = '*';
                mat[poz_x+1][poz_y-1] = '*';
                mat[poz_x+1][poz_y] = '*';
                mat[poz_x+1][poz_y+1] = '*';
                mat[poz_x+1][poz_y+2] = '*';
                mat[poz_x+2][poz_y] = '*';
                mat[poz_x+3][poz_y] = '*';
                mat[poz_x+3][poz_y-1] = '*';
                mat[poz_x+3][poz_y+1] = '*';

            } else if (directie == 'S') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x-1][poz_y-2] = '*';
                mat[poz_x-1][poz_y-1] = '*';
                mat[poz_x-1][poz_y] = '*';
                mat[poz_x-1][poz_y+1] = '*';
                mat[poz_x-1][poz_y+2] = '*';
                mat[poz_x-2][poz_y] = '*';
                mat[poz_x-3][poz_y] = '*';
                mat[poz_x-3][poz_y-1] = '*';
                mat[poz_x-3][poz_y+1] = '*';

            } else if (directie == 'E') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x-2][poz_y-1] = '*';
                mat[poz_x-1][poz_y-1] = '*';
                mat[poz_x][poz_y-1] = '*';
                mat[poz_x+1][poz_y-1] = '*';
                mat[poz_x+2][poz_y-1] = '*';
                mat[poz_x][poz_y-2] = '*';
                mat[poz_x][poz_y-3] = '*';
                mat[poz_x-1][poz_y-3] = '*';
                mat[poz_x+1][poz_y-3] = '*';

            } else if (directie == 'W') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x-2][poz_y+1] = '*';
                mat[poz_x-1][poz_y+1] = '*';
                mat[poz_x][poz_y+1] = '*';
                mat[poz_x+1][poz_y+1] = '*';
                mat[poz_x+2][poz_y+1] = '*';
                mat[poz_x][poz_y+2] = '*';
                mat[poz_x][poz_y+3] = '*';
                mat[poz_x-1][poz_y+3] = '*';
                mat[poz_x+1][poz_y+3] = '*';
            }
        } else {
            if (directie == 'N') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x+1][poz_y-1] = '*';
                mat[poz_x+1][poz_y+1] = '*';
                mat[poz_x+1][poz_y] = '*';
                mat[poz_x+2][poz_y-3] = '*';
                mat[poz_x+2][poz_y-2] = '*';
                mat[poz_x+2][poz_y-1] = '*';
                mat[poz_x+2][poz_y] = '*';
                mat[poz_x+2][poz_y+1] = '*';
                mat[poz_x+2][poz_y+2] = '*';
                mat[poz_x+2][poz_y+3] = '*';
                mat[poz_x+3][poz_y] = '*';
                mat[poz_x+4][poz_y-1] = '*';
                mat[poz_x+4][poz_y] = '*';
                mat[poz_x+4][poz_y+1] = '*';
                mat[poz_x+4][poz_y+2] = '*';
                mat[poz_x+4][poz_y-2] = '*';
            }
            if (directie == 'S') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x-1][poz_y-1] = '*';
                mat[poz_x-1][poz_y+1] = '*';
                mat[poz_x-1][poz_y] = '*';
                mat[poz_x-2][poz_y-3] = '*';
                mat[poz_x-2][poz_y-2] = '*';
                mat[poz_x-2][poz_y-1] = '*';
                mat[poz_x-2][poz_y] = '*';
                mat[poz_x-2][poz_y+1] = '*';
                mat[poz_x-2][poz_y+2] = '*';
                mat[poz_x-2][poz_y+3] = '*';
                mat[poz_x-3][poz_y] = '*';
                mat[poz_x-4][poz_y-1] = '*';
                mat[poz_x-4][poz_y] = '*';
                mat[poz_x-4][poz_y+1] = '*';
                mat[poz_x-4][poz_y+2] = '*';
                mat[poz_x-4][poz_y-2] = '*';
            }
            if (directie == 'E') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x-1][poz_y-1] = '*';
                mat[poz_x+1][poz_y-1] = '*';
                mat[poz_x][poz_y-1] = '*';
                mat[poz_x-3][poz_y-2] = '*';
                mat[poz_x-2][poz_y-2] = '*';
                mat[poz_x-1][poz_y-2] = '*';
                mat[poz_x][poz_y-2] = '*';
                mat[poz_x+1][poz_y-2] = '*';
                mat[poz_x+2][poz_y-2] = '*';
                mat[poz_x+3][poz_y-2] = '*';
                mat[poz_x][poz_y-3] = '*';
                mat[poz_x-1][poz_y-4] = '*';
                mat[poz_x][poz_y-4] = '*';
                mat[poz_x+1][poz_y-4] = '*';
                mat[poz_x+2][poz_y-4] = '*';
                mat[poz_x-2][poz_y-4] = '*';
            }
            if (directie == 'W') {
                mat[poz_x][poz_y] = '*';
                mat[poz_x-1][poz_y+1] = '*';
                mat[poz_x+1][poz_y+1] = '*';
                mat[poz_x][poz_y+1] = '*';
                mat[poz_x-3][poz_y+2] = '*';
                mat[poz_x-2][poz_y+2] = '*';
                mat[poz_x-1][poz_y+2] = '*';
                mat[poz_x][poz_y+2] = '*';
                mat[poz_x+1][poz_y+2] = '*';
                mat[poz_x+2][poz_y+2] = '*';
                mat[poz_x+3][poz_y+2] = '*';
                mat[poz_x][poz_y+3] = '*';
                mat[poz_x-1][poz_y+4] = '*';
                mat[poz_x][poz_y+4] = '*';
                mat[poz_x+1][poz_y+4] = '*';
                mat[poz_x+2][poz_y+4] = '*';
                mat[poz_x-2][poz_y+4] = '*';
            }
        }
    }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                printf("%c", mat[j][k]);
            }
            printf("\n");
        }
}
