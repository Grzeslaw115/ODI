#include <stdio.h>

// Returns the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    int value[N];
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &value[i]) != 1) {
            printf("Error reading input.\n");
            return 1;
        }
    }

    // Initialize dp array
    int profit[N];
    profit[0] = value[0];
    profit[1] = max(value[0], value[1]);

    // Calculate the maximum profit for each plot
    for (int i = 2; i < N; i++) {
        profit[i] = max(profit[i - 1], value[i] + profit[i - 2]);
    }

    printf("%d\n", profit[N - 1]);
    return 0;
}