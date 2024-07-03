#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int remove_factor(int n, int factor) {
    while (n % factor == 0) {
        n /= factor;
    }
    return n;
}

// Function to check if two numbers have the same set of prime factors
bool are_compatible(int a, int b) {

    for (int i = 2; i <= max(a, b); i++) {
        bool divides_a = (a % i == 0);
        bool divides_b = (b % i == 0);

        if (divides_a != divides_b) {
            return false;
        }

        if (divides_a && divides_b) {
            a = remove_factor(a, i);
            b = remove_factor(b, i);
        }

        if (a == 1 && b == 1) {
            break;
        }
    }

    return (a == 1 && b == 1);
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
                    if (are_compatible(matrix[i][j], matrix[new_i][new_j])) {
                        count += 2;
                        break; // It doesn't matter how many are compatible
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    // Read input
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

    // Declare and fill the matrix
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

    // Calculate and print the result
    int result = count_compatible(matrix, N);
    printf("%d\n", result);
    return 0;
}