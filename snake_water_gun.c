#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct snake_water_gun
{
    int user;
    int computer;

} score;

int result(int input, int com_generated);
void playgame();
void showscore();
void title();
void updatescore(score *s, int r);
void gamerules();
void title()
{
    printf("\n");

    printf("  _____ _   _          _  __ ______     __          __     _______ ______ _____      _____ _    _ _   _ \n");
    printf(" / ____| \\ | |   /\\   | |/ /|  ____|    \\ \\        / /\\   |__   __|  ____|  __ \\    / ____| |  | | \\ | |\n");
    printf("| (___ |  \\| |  /  \\  | ' / | |__        \\ \\  /\\  / /  \\     | |  | |__  | |__) |  | |  __| |  | |  \\| |\n");
    printf(" \\___ \\| . ` | / /\\ \\ |  <  |  __|        \\ \\/  \\/ / /\\ \\    | |  |  __| |  _  /   | | |_ | |  | | . ` |\n");
    printf(" ____) | |\\  |/ ____ \\| . \\ | |____        \\  /\\  / ____ \\   | |  | |____| | \\ \\   | |__| | |__| | |\\  |\n");
    printf("|_____/|_| \\_/_/    \\_\\_|\\_\\|______|        \\/  \\/_/    \\_\\  |_|  |______|_|  \\_\\   \\_____|\\____/|_| \\_|\n");

    printf("\n");
}

int result(int input, int com_generated)
{

    if (input == com_generated)
    {
        return 0;
    }

    else if (
        (input == 0 && com_generated == 2) ||
        (input == 1 && com_generated == 0) ||
        (input == 2 && com_generated == 1))
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

void updatescore(score *s, int r)
{

    if (r == 1)
    {
        s->user++;
    }

    else if (r == -1)
    {
        s->computer++;
    }
}

void playgame()
{

    int input;
    int com_generated;
    int r;

    score s;

    FILE *ptr;

    s.user = 0;
    s.computer = 0;

    char *name[3] = {"Snake", "Water", "Gun"};

    for (int i = 1; i <= 5; i++)
    {

        printf("\n=====================\n");
        printf("\n=======Round %d=======\n", i);
        printf("\n=====================\n");

        printf("Press --> 0 = Snake\n");
        printf("Press --> 1 = Water\n");
        printf("Press --> 2 = Gun\n");

        printf("Enter your choice: ");
        scanf("%d", &input);

        com_generated = rand() % 3;

        printf("Computer chose: %s\n", name[com_generated]);

        r = result(input, com_generated);

        if (r == 1)
        {
            printf("You win this round!\n");
            printf("===================\n");
            updatescore(&s, r);
        }

        else if (r == -1)
        {
            printf("Computer wins this round!\n");
            printf("=========================\n");
            updatescore(&s, r);
        }

        else
        {
            printf("Draw round!\n");
            printf("===========\n");
        }
    }

    printf("\n=====================\n");
    printf("\n=====Final Score=====\n");
    printf("\n=====================\n");

    printf("You      = %d\n", s.user);
    printf("Computer = %d\n", s.computer);
    if (s.user > s.computer)
    {
        printf("You win!\n");
    }
    else if (s.user < s.computer)
    {
        printf("Computer win!\n");
    }
    else
    {
        printf("It's a Draw!");
    }

    ptr = fopen("score.txt", "a");

    if (ptr == NULL)
    {
        printf("File error!\n");
        return;
    }
    fprintf(ptr, "\n=======================\n");
    fprintf(ptr, "\n===== R E S U L T =====\n");
    fprintf(ptr, "\n=======================\n");
    time_t t;
    time(&t);
    fprintf(ptr, "-->Date & Time:%s", ctime(&t));
    fprintf(ptr, "You Wins      = %d\n", s.user);
    fprintf(ptr, "Computer Wins = %d\n", s.computer);

    if (s.user > s.computer)
    {
        fprintf(ptr, "Winner: You\n");
    }

    else if (s.computer > s.user)
    {
        fprintf(ptr, "Winner: Computer\n");
    }

    else
    {
        fprintf(ptr, "Game Draw\n");
    }

    fclose(ptr);
}

void showscore()
{

    FILE *ptr;
    char ch;

    ptr = fopen("score.txt", "r");

    if (ptr == NULL)
    {
        printf("No score history found!\n");
        return;
    }

    printf("\n==========^^^^^==========\n");

    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(ptr);
}
void gamerules()
{
    FILE *pointer;
    char ch;
    pointer = fopen("Game_Rules.txt", "r");
    if (pointer == NULL)
    {
        printf("Invalid!");
        return;
    }
    while ((ch = fgetc(pointer)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(pointer);
}
int main()
{

    int choice;

    srand(time(0));

    while (1)
    {

        title();
        printf("\n===================\n");
        printf("\n==== MAIN MENU ====\n");
        printf("\n===================\n");

        printf("Press: 1 --> Play Game\n");
        printf("Press: 2 --> Show Score History\n");
        printf("Press: 3 --> Game Rules\n");
        printf("Press: 4 --> Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        {
            playgame();
            break;
        }

        case 2:
        {
            showscore();
            break;
        }
        case 3:
        {
            gamerules();
            break;
        }

        case 4:
        {
            printf("=====T H E <---> E N D=====\n");
            exit(0);
        }

        default:
        {
            printf("Invalid Choice!\n");
        }
        }
    }

    return 0;
}
