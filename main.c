#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(0));

    int random_1 = rand() % 100 + 1;
    int random_2 = rand() % 200 + 1;
    int random_3 = rand() % 500 + 1;

    int no_of_guesses = 0;
    int guessed;
    int choice;
    int score;

    printf("==== YOUR OPTIONS ====\n");
    printf("1. Easy (1 --> 100)\n");
    printf("2. Medium (1 --> 200)\n");
    printf("3. Hard (1 --> 500)\n");
    printf("======================\n");

    printf("Enter your choice = ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        do
        {
            printf("Guess the number = ");
            scanf("%d", &guessed);

            if (guessed > random_1)
            {
                printf("Try lower number\n");
            }
            else if (guessed < random_1)
            {
                printf("Try higher number\n");
            }
            else
            {
                printf("--! Congratulations !--\n");
            }
            no_of_guesses++;

            if (no_of_guesses == 10)
            {
                printf("--! GAME OVER !--");
                break;
            }

        } while (guessed != random_1);

        score = (10 - no_of_guesses + 1) * 100;

        printf("Number of gusses = %d\n", no_of_guesses);
        printf("You'r score = %d\n", score);

        break;

    default:
        break;
    }

    return 0;
}