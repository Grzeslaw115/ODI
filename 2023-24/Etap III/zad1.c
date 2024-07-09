#include <stdio.h>

int N;

int main() {

    if (scanf("%d", &N) != 1) {
        printf("Incorrect input");
        return 1;
    }
    int frac[N][2];
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d", &frac[i][0], &frac[i][1]) != 2) {
            printf("Incorrect input");
            return 1;
        }
    }
    return 0; 
}