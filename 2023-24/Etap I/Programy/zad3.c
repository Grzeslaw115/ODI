#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Checks if there is a vowel in substring of word from start to end
bool contains_vowel(char *word, int start, int end) {
    for (int i = start; i < end; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            return true;
        }
    }
    return false;
}

int main() {

    // Read input
    char word[101];
    if (scanf("%100s", word) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    
    // Initialize dp array
    int n = strlen(word);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    // Calculate dp values
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (contains_vowel(word, j, i)) {
                dp[i] += dp[j];
            }
        }
    }

    // Print result, -1 because string must be cut at least once
    printf("%d\n", dp[n] - 1);
    return 0;
}