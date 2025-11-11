/**
 * @file hangman.c
 * @brief A simple implementation of the "Hangman" word guessing game in C,
 * using only the <stdio.h> header file.
 *
 * All string manipulation and character conversion logic is implemented
 * using custom functions to meet the required constraint.
 */

#include <stdio.h> 

// --- Custom Function Implementations (To avoid string.h and ctype.h) ---

/**
 * @brief Custom implementation of strlen to get the length of a null-terminated string.
 * @param s The string (char array).
 * @return The length of the string, excluding the null terminator.
 */
int my_strlen(const char* s)
{
    int length = 0;
    // Iterate until the null terminator '\0' is found
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}

/**
 * @brief Custom implementation of toupper to convert a lowercase letter to uppercase.
 * @param c The character to convert.
 * @return The uppercase version of the character, or the original character if not lowercase.
 */
char my_toupper(char c)
{
    // Check if the character is a lowercase letter (ASCII range)
    if (c >= 'a' && c <= 'z')
    {
        // Convert to uppercase by using the fixed difference between 'a' and 'A' in ASCII
        return c - ('a' - 'A');
    }
    return c; // Return as is if already uppercase or not a letter
}

// --- Function Prototypes ---

/**
 * @brief Initializes the player's view of the word with underscores.
 */
void initialize_player_view(char* player_view, int length);

/**
 * @brief Prints the current state of the player's view (e.g., "C L A S H").
 */
void print_player_view(const char* player_view, int length);

/**
 * @brief Checks the player's guess against the secret word and updates the view.
 * @return 1 if a match was found, 0 otherwise.
 */
int check_guess(char guess, const char* secret_word, char* player_view, int length);

/**
 * @brief Checks if the player has won the game (no more underscores).
 * @return 1 if the player has won, 0 otherwise.
 */
int is_game_won(const char* player_view, int length);

// --- Main Game Function ---

int main()
{
    // 1. The Secret Word (Hard-coded as uppercase for simplicity)
    const char secret_word[] = "CLASH";
    // Use the custom length function
    const int word_length = my_strlen(secret_word); 
    int lives = 6; 

    // 2. The Player's View
    char player_view[word_length + 1]; 
    initialize_player_view(player_view, word_length);

    int game_won = 0;

    printf("Welcome to Hangman!\n");
    printf("Secret word length: %d letters. Lives: %d\n", word_length, lives);
    printf("--------------------------------------------------\n");

    // 3. The Game Loop
    while (lives > 0 && !game_won)
    {
        // Print current state
        print_player_view(player_view, word_length);
        printf("Lives remaining: %d\n", lives);

        // Ask user for a guess
        printf("Guess a letter: ");
        char guess;
        // The " %c" format specifier skips leading whitespace
        scanf(" %c", &guess);
        
        // Clear the input buffer using getchar() from stdio.h
        while (getchar() != '\n');

        // Standardize the guess to uppercase using the custom function
        guess = my_toupper(guess);

        // 4. The Logic
        if (check_guess(guess, secret_word, player_view, word_length))
        {
            printf("Good guess!\n");
        }
        else
        {
            printf("Sorry, '%c' is not in the word. You lose a life.\n", guess);
            lives--; 
        }

        // 5. Check for win
        game_won = is_game_won(player_view, word_length);
        
        printf("--------------------------------------------------\n");
    }

    // 6. Win/Loss Condition
    if (game_won)
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("You lost! The word was: %s\n", secret_word);
    }
    
    return 0;
}


// --- Function Definitions ---

void initialize_player_view(char* player_view, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        player_view[i] = '_';
    }
    // Add the null terminator
    player_view[length] = '\0';
}

void print_player_view(const char* player_view, int length)
{
    int i;
    printf("Word: ");
    for (i = 0; i < length; i++)
    {
        printf("%c ", player_view[i]); // Print with spaces
    }
    printf("\n");
}

int check_guess(char guess, const char* secret_word, char* player_view, int length)
{
    int match_found = 0; 
    int i;

    // Iterate through the secret_word array
    for (i = 0; i < length; i++)
    {
        // Check if the guess matches a letter
        if (secret_word[i] == guess)
        {
            // Update the player's view
            player_view[i] = guess;
            match_found = 1;
        }
    }
    
    return match_found;
}

int is_game_won(const char* player_view, int length)
{
    int i;
    // Loop through the player's view
    for (i = 0; i < length; i++)
    {
        // If we find even one underscore, the game is still active
        if (player_view[i] == '_')
        {
            return 0; // Not won
        }
    }
    // If the loop finishes, all letters have been guessed
    return 1; // Won
}
