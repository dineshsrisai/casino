#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void play(int bet)
{
    char *c = (char *)malloc(3 * sizeof(char)); // cpp : char *c = new char[3];
    c[0] = 'J', c[1] = 'Q', c[2] = 'K';
    printf("Shuffling... ");
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 3, y = rand() % 3;
        int temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }
    int guess;
    printf("Guess the position of Queen - 1, 2 or 3 ? ");
    scanf("%d", &guess);
    if (c[guess - 1] == 'Q')
    {
        cash += 3 * bet;
        printf("You Won!!! Result : %c %c %c Total Cash : %d ", c[0], c[1], c[2], cash);
    }
    else
    {
        cash -= bet;
        printf("OOP'S Wrong Guess, Try Again!!! Result : %c %c %c Total Cash : %d ", c[0], c[1], c[2], cash);
    }
    free(c);
}

int main()
{
    int bet;
    printf("Welcome!!! ");
    printf("Total cash : %d ", cash);
    while (cash > 0)
    {
        printf("What's your bet? ");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
        {
            break;
        }
        play(bet);
        printf("\n---------------------------------\n");
    }
    return 0;
}