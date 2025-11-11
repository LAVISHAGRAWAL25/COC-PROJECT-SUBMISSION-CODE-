# COC-PROJECT-SUBMISSION-CODE-
Hangman Word Guessing Game

Project Description

This is a classic "Hangman" word-guessing game implemented in the C programming language. The computer stores a secret word ("CLASH" in the hard-coded version), and the player must guess it, letter by letter. The player has a limited number of "lives" (6 wrong guesses) before losing.

The program controls the entire game logic, including:

Initializing the player's hidden view (e.g., _ _ _ _ _).

Handling the main game loop (while loop) until a win or loss condition is met.

Tracking remaining lives and checking the win condition (checking for remaining underscores).

Key Constraint

This project strictly adheres to using only the <stdio.h> header file. All other necessary string and character manipulation logic (like finding string length and converting case) is implemented through custom helper functions (my_strlen, my_toupper).

Concepts Used

C Programming Concepts (Days 2 - 6)

char Arrays (Day 5): Used to store the secret_word and the player's player_view.

while and for Loops (Day 4): Used for the main game loop and iterating through the word to check guesses.

if/else Statements (Day 3): Used for handling matches/misses, win/loss conditions, and custom logic.

printf()/scanf() (Day 2): Used for all game output and receiving player input.

User-Defined Functions (Day 6): Logic separated into functions like check_guess and is_game_won.

Custom Logic: Implemented helper functions (my_strlen, my_toupper) to replace standard library calls.

Maths / Data Concepts (Day 5 - 6)

Data Application (Day 6): The game itself acts as an application built upon data manipulation.

Statistical Data Analysis (Day 5): The player is (unknowingly) performing data analysis by attempting to guess letters based on their statistical probability in the English language.

How to Compile

Using the gcc compiler, you can compile the program with the following command:

gcc hangman.c -o hangman


How to Run

Once compiled, execute the program from your terminal:

./hangman
