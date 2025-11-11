Project Title & Description
This project is a text-based Hangman Word Guessing Game implemented completely in C using only the stdio.h library. The program selects a secret word that the player must guess one letter at a time. For every incorrect guess, the player loses a life. The game ends either when the player reveals the full word or exhausts all lives.

The project demonstrates structured programming in C, modular design through functions, and interactive console-based gameplay. Each section of logic — such as initialization, guess checking, display updates, and win validation — is implemented as a separate function.

Features

-Displays the current progress of the guessed word.

-Tracks remaining lives dynamically.

-Validates each letter guess and updates the display.

-Declares clear win or loss results.

-Uses modular function-based structure for clarity and reusability.

Concepts Used

C Programming Concepts:

-Character arrays (char secret[], char display[])

-Loops (while, for) for iteration and control flow

-Conditional statements (if / else) for logic decisions

-Functions for modularization (initializeDisplay(), processGuess(), etc.)

-Console input/output using printf() and scanf()

-Null termination and string handling


Mathematical / Logical Reasoning:

-Deductive thinking for letter selection

-Basic probability consideration when guessing letters

-Pattern recognition while identifying possible words


File Structure

hangman.c       -> Main C program file

README.md       -> Documentation file describing the project


How to Compile

Use the following command in your terminal to compile the program:

gcc hangman.c -o hangman


How to Run

After compilation, you can execute the game by typing:

./hangman


Sample Gameplay

Welcome to the Hangman Game!


Current Word: _ _ _ _ _ _

Lives Remaining: 6

Enter your guess: M

Good guess!

Current Word: M _ _ _ _ _

Lives Remaining: 6

Enter your guess: X

Wrong guess! You lost a life.


Learning Outcomes

-Understands the use of arrays, loops, and decision-making in C.

-Implements modular design and code reusability.

-Reinforces logic building for text-based games and player interaction in the console.

