#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand (time(0));

    int random_1 = rand() % 100 + 1;
    int random_2 = rand() % 200 + 1;
    int random_3 = rand() % 500 + 1;

    int no_of_guesses = 0;
    int guessed;
    int choice;

    printf("==== YOUR OPTIONS ====\n");
    printf("1. Easy (1 --> 100)\n");
    printf("2. Medium (1 --> 200)\n");
    printf("3. Hard (1 --> 500)\n");
    printf("======================\n");

    printf("Enter your choice = ");
    scanf("%d", &choice);

    


    return 0;
}