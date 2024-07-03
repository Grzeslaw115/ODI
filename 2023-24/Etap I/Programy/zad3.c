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

// Counts the number of splits in the word
int count_splits(char* str, int start, int length) {
    if (start >= length) {
        return 0;
    }

    int total_splits = 0;
    for (int i = start + 1; i < length; i++) {
        if (contains_vowel(str, start, i)) { // Checks if there is vowel in first part
            if (contains_vowel(str, i, length)) { // Checks if there is vowel in second part, if so, it is a valid split
                total_splits++; 
            }
            total_splits += count_splits(str, i, length); // Recursively check for more splits
        }
    }
    return total_splits;
}

int main() {

    // Read input
    char word[101];
    if (scanf("%100s", word) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    int n = strlen(word);

    printf("%d\n", count_splits(word, 0, n));
    return 0;
}