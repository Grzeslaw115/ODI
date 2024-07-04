#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if our precision condition is met
bool precision_condition(double factorial, int n, int N) {
    return (1.0 / (factorial * n)) < pow(10, -N);
}

int main() {
    
    // Read input
    int N;
    if (scanf("%d", &N) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    int result = 0;
    int i = 1;
    double factorial = 1.0;
    double e = 1.0;

    // Calculate e with precision N
    while (true) {
        factorial *= i; // i!
        e += 1.0 / factorial;
        if (precision_condition(factorial, i, N)) {
            break;
        }
        i++;
    }

    // Shift e to the right by N digits
    long long int shifted_e = (long long int)(e * pow(10, N));

    // Sum all digits of the shifted number
    while (shifted_e) {
        result += shifted_e % 10;
        shifted_e /= 10;
    }

    // Print the result
    printf("%d\n", result);
    return 0;
}