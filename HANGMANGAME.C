#include <stdio.h>

// Function Prototypes
void initializeDisplay(char secret[], char display[]);
void showGameState(char display[], int lives);
int processGuess(char secret[], char display[], char guess);
int isWordComplete(char display[]);

// Main Function: Controls game flow
int main() {
    char secret_word[] = "MENTOR";                     // The secret word to guess
    char display_word[7];                              // Display version with underscores
    int lives = 6;                                     // Total number of wrong guesses allowed
    char guess;                                        // Player's input

    printf("Welcome to the Hangman Game!\n\n");

    // Initialize the display array with underscores
    initializeDisplay(secret_word, display_word);

    // Main Game Loop
    while (lives > 0) {
        showGameState(display_word, lives);             // Show current game state
        printf("Enter your guess: ");
        scanf(" %c", &guess);                           // Take single character input

        // Process the player’s guess
        if (processGuess(secret_word, display_word, guess)) {
            printf("Good guess!\n");
        } else {
            lives--;
            printf("Wrong guess! You lost a life.\n");
        }

        // Check if the word is completely guessed
        if (isWordComplete(display_word)) {
            printf("\nCongratulations! You won!\n");
            printf("The word was: %s\n", secret_word);
            return 0;
        }
    }

    // If loop ends, player has lost
    printf("\nYou lost! The word was: %s\n", secret_word);
    return 0;
}

// Function: Initialize display word with underscores
void initializeDisplay(char secret[], char display[]) {
    int i;
    for (i = 0; secret[i] != '\0'; i++) {
        display[i] = '_';                               // Replace letters with underscores
    }
    display[i] = '\0';                                  // Null terminate the display word
}

// Function: Display current game state
void showGameState(char display[], int lives) {
    printf("\nCurrent Word: %s\n", display);
    printf("Lives Remaining: %d\n", lives);
}

// Function: Process a single guessed letter
// Returns 1 if guess is correct, 0 if incorrect
int processGuess(char secret[], char display[], char guess) {
    int i, correct = 0;
    for (i = 0; secret[i] != '\0'; i++) {
        if (secret[i] == guess && display[i] == '_') {
            display[i] = guess;
            correct = 1;
        }
    }
    return correct;
}

// Function: Check if player has guessed the full word
// Returns 1 if the word is complete, 0 otherwise
int isWordComplete(char display[]) {
    int i;
    for (i = 0; display[i] != '\0'; i++) {
        if (display[i] == '_')
            return 0;                                   // Not complete yet
    }
    return 1;                                           // Word fully guessed
}
