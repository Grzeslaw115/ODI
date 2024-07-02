#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if two numbers have the same set of prime factors
bool have_same_prime_factors(int a, int b) {
    int gcd_ab = gcd(a, b);
    a /= gcd_ab;
    b /= gcd_ab;
    while (a % gcd_ab == 0) a /= gcd_ab;
    while (b % gcd_ab == 0) b /= gcd_ab;
    return a == 1 && b == 1;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to count compatible neighboring elements in the matrix
int count_compatible(int matrix[][1000], int N) {
    int count = 0;
    int neighbours[2][2] = {{0, 1}, {1, 0}};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                int new_i = i + neighbours[k][0];
                int new_j = j + neighbours[k][1];
                if (new_i >= 0 && new_i < N && new_j >= 0 && new_j < N) {
                    if (have_same_prime_factors(matrix[i][j], matrix[new_i][new_j])) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0 || N > 1000) {
        printf("Incorrect input\n");
        return 1;
    }

    int A1;
    if (scanf("%d", &A1) != 1 || A1 <= 0 || A1 >= 100) {
        printf("Incorrect input\n");
        return 1;
    }

    int matrix[1000][1000];
    matrix[0][0] = A1;

    int prev = A1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            matrix[i][j] = 3 * prev % 53;
            prev = matrix[i][j];
        }
    }

    int result = count_compatible(matrix, N);

    printf("%d\n", result);
    return 0;
}