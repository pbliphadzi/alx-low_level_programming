#include <stdio.h>
/* This function void guessnumber is the function that guesses if the number is correct*/
void guessNumber(int guess) {
    if (guess = 555){
        printf("Correct. You guessed it!\n");
    } else if (guess > 555){
        printf("Your guess is too high.\n");
    } else if (guess < 555)(
        printf("Your guess is too low.\n")
    )
}
/* This functions int main provides guesses, so you add values to guessNumber */
int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}