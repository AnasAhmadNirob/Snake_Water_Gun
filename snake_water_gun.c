/*
    Project Title : Snake Water Gun Game
    Language      : C
    Type          : Console Based Game

    Description:
    This is a simple Snake-Water-Gun game implemented in C programming language.
    In this game, the user selects one option from Snake, Water, or Gun and the
    computer also randomly generates an option. The winner is decided based on
    the rules of the game.

    Game Rules:
    Snake drinks Water  -> Snake wins
    Water drowns Gun    -> Water wins
    Gun kills Snake     -> Gun wins
    Same choice         -> Draw

    Features of the Project:
    - Menu based system
    - Random number generation for computer choice
    - Score tracking using structure
    - File handling to save score
    - ASCII graphics for better interface
    - Modular programming using functions

    Concepts Used:
    - Structure
    - Pointer
    - Call by Reference
    - File Handling
    - Random Number Generation
    - Function Modularization

    Author : Anas Ahmad Nirob
    Course : CSE-1210
    Project: University Programming Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure to store user and computer score
typedef struct snake_water_gun
{
    int user;
    int computer;

} score;

// function prototypes
int result(int input, int com_generated); // determines winner of a round
void playgame();                          // main gameplay function
void showscore();                         // displays score history from file
void title();                             // prints ASCII title
void updatescore(score *s, int r);        // updates score using pointer
void gamerules();                         // reads and prints rules from file

// function to display game title using ASCII art
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

// function to determine result of the round
int result(int input, int com_generated)
{

    if (input == com_generated) // same choice -> draw
    {
        return 0;
    }

    // conditions where user wins
    else if (
        (input == 0 && com_generated == 2) ||
        (input == 1 && com_generated == 0) ||
        (input == 2 && com_generated == 1))
    {
        return 1;
    }

    else // otherwise computer wins
    {
        return -1;
    }
}

// updates score using call by reference
void updatescore(score *s, int r)
{

    if (r == 1)
    {
        s->user++; // increase user score
    }

    else if (r == -1)
    {
        s->computer++; // increase computer score
    }
}

// main gameplay function
void playgame()
{

    int input;
    int com_generated;
    int r;

    score s; // structure variable for score

    FILE *ptr; // file pointer for saving score

    s.user = 0;
    s.computer = 0;

    // array of names for choices
    char *name[3] = {"Snake", "Water", "Gun"};

    for (int i = 1; i <= 5; i++) // total 5 rounds
    {

        printf("\n=====================\n");
        printf("\n=======Round %d=======\n", i);
        printf("\n=====================\n");

        printf("Press --> 0 = Snake\n");
        printf("Press --> 1 = Water\n");
        printf("Press --> 2 = Gun\n");

        printf("Enter your choice: ");
        scanf("%d", &input);

        com_generated = rand() % 3; // computer generates random choice

        printf("Computer chose: %s\n", name[com_generated]);

        r = result(input, com_generated); // check result

        if (r == 1)
        {
            printf("You win this round!\n");
            printf("===================\n");
            updatescore(&s, r); // update score
        }

        else if (r == -1)
        {
            printf("Computer wins this round!\n");
            printf("=========================\n");
            updatescore(&s, r); // update score
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

    // determine final winner
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

    // open file to store result
    ptr = fopen("score.txt", "a");

    if (ptr == NULL)
    {
        printf("File error!\n");
        return;
    }

    // writing result to file
    fprintf(ptr, "\n=======================\n");
    fprintf(ptr, "\n===== R E S U L T =====\n");
    fprintf(ptr, "\n=======================\n");

    time_t t;
    time(&t);

    fprintf(ptr, "-->Date & Time:%s", ctime(&t));
    fprintf(ptr, "You Wins      = %d\n", s.user);
    fprintf(ptr, "Computer Wins = %d\n", s.computer);

    // writing winner in file
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

    fclose(ptr); // close file
}

// function to show previous score history
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

    // read file character by character
    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(ptr);
}

// function to read game rules from file
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

    // print rules from file
    while ((ch = fgetc(pointer)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(pointer);
}

int main()
{

    int choice;

    srand(time(0)); // seed for random number generation

    while (1)
    {

        title(); // show title

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
            playgame(); // start game
            break;
        }

        case 2:
        {
            showscore(); // show score history
            break;
        }

        case 3:
        {
            gamerules(); // show rules
            break;
        }

        case 4:
        {
            printf("=====T H E <---> E N D=====\n");
            exit(0); // exit program
        }

        default:
        {
            printf("Invalid Choice!\n");
        }
        }
    }

    return 0;
}