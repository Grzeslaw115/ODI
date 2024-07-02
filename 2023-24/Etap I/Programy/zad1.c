#include <stdio.h>
#include <math.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    int result = 0;
    int i = 0;
    double factorial = 1.0;
    double e = 1.0;

    // Calculate e to n decimal places
    while (factorial > pow(10, -n)) {
        factorial /= ++i;
        e += factorial;
    }

    printf("%.*f\n", n, e);

    // Shift e by n decimal places and convert to integer
    long long int shifted_e = (long long int)(e * pow(10, n));

    // Sum the digits of the shifted value of e
    while (shifted_e > 0) {
        result += shifted_e % 10;
        shifted_e /= 10;
    }

    printf("%d\n", result);

    return 0;
}