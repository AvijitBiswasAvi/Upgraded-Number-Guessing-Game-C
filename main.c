#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    char choice_of_replay;

    srand(time(0));

    do
    {

        int choice;
        int random;
        int max_attempts;
        int guessed;
        int attempts = 0;

        printf("\n========= YOUR OPTIONS ========\n");
        printf("1. Easy (1 - 100)[ 10 Tries ]\n");
        printf("2. Medium (1 - 200)[ 8 Tries ]\n");
        printf("3. Hard (1 - 500)[ 6 Tries ]\n");
        printf("===============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            random = rand() % 100 + 1;
            max_attempts = 10;
        }
        else if (choice == 2)
        {
            random = rand() % 200 + 1;
            max_attempts = 8;
        }
        else if (choice == 3)
        {
            random = rand() % 500 + 1;
            max_attempts = 6;
        }
        else
        {
            printf("Invalid choice! Defaulting to Easy mode.\n");
            random = rand() % 100 + 1;
            max_attempts = 10;
        }

        do
        {

            printf("Guess the number: ");
            scanf("%d", &guessed);

            if (guessed > random)
            {
                printf("Try lower number\n");
            }
            else if (guessed < random)
            {
                printf("Try higher number\n");
            }
            else
            {
                printf("\n--Congratulations! You guessed it!--\n");
            }

            attempts++;

            if (attempts == max_attempts && guessed != random)
            {
                printf("\n-- GAME OVER --\n");
                printf("The number was: %d\n", random);
                break;
            }

        } while (guessed != random);

        if (guessed == random)
        {
            int score = (max_attempts - attempts + 1) * 100;

            if (score < 0)
                score = 0;

            printf("Number of guesses: %d\n", attempts);
            printf("Your score: %d\n", score);
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &choice_of_replay);

    } while (choice_of_replay == 'y');

    printf("Thanks for playing!\n");

    return 0;
}