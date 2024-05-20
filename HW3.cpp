#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define RESERVED_COUNT 10

/*Function to generate the seat map with random reserved seats*/
void generate_seat_map(char seat_map[ROWS][COLS])
{
    int reserved_seats = 0, row, col;
    srand(time(NULL));

    /*Initialize all seats to '-'*/
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seat_map[i][j] = '-';

    /*Randomly reserve seats until RESERVED_COUNT is reached*/
    while (reserved_seats < RESERVED_COUNT)
    {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (seat_map[row][col] != '*')
        {
            seat_map[row][col] = '*';
            reserved_seats++;
        }
    }
}

/* Function to display the seat map*/
void display_seat_map(char seat_map[ROWS][COLS])
{

    printf("  ");
    for (int j = 0; j < COLS; j++)
    {
        printf("%d", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", seat_map[i][j]);
        }
        printf("\n");
    }
    getchar();
    getchar();
}

/* Function to select seats automatically based on the number of seats required*/
void select_seats(char seat_map[ROWS][COLS], int num_seats)
{
    int row, col, direction, found = 0;

    srand(time(NULL));

    while (!found)
    {
        row = rand() % ROWS;
        col = rand() % COLS;
        direction = rand() % 2;

        /* Horizontal selection*/
        if (direction == 0 && col + num_seats <= COLS)
        {
            found = 1;
            for (int i = 0; i < num_seats; i++)
            {
                if (seat_map[row][col + i] != '-')
                {
                    found = 0;
                    break;
                }
            }
            if (found)
            {
                for (int i = 0; i < num_seats; i++)
                {
                    seat_map[row][col + i] = '@';
                }
            }
        }
        /*2x2 selection*/
        else if (direction == 1 && row + 1 < ROWS && col + 1 < COLS)
        {
            found = 1;
            if (seat_map[row][col] != '-' || seat_map[row][col + 1] != '-' || seat_map[row + 1][col] != '-' || seat_map[row + 1][col + 1] != '-')
            {
                found = 0;
            }
            if (found)
            {
                seat_map[row][col] = '@';
                seat_map[row][col + 1] = '@';
                seat_map[row + 1][col] = '@';
                seat_map[row + 1][col + 1] = '@';
            }
        }
    }
}

void record_selected_seats(char seat_map[ROWS][COLS], char user_map[ROWS][COLS]);
/* Function to handle the automatic seat selection process*/
void ask_and_select_seats(char seat_map[ROWS][COLS])
{
    int num_seats;
    char input;
    char temp_map[ROWS][COLS];

    /* Copy the current seat map to a temporary map*/
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            temp_map[i][j] = seat_map[i][j];
        }
    }

    while (1)
    {
        printf("How many seats do you need? (1-4): ");
        scanf("%d", &num_seats);
        getchar();

        if (num_seats < 1 || num_seats > 4)
        {
            printf("Invalid number of seats. Please try again.\n");
        }
        else
        {

            if (num_seats < 4)
            {
                select_seats(temp_map, num_seats);
            }
            else
            {
                select_seats(temp_map, 2);
                select_seats(temp_map, 2);
            }

            break;
        }
    }

    system("cls");
    display_seat_map(temp_map);

    printf("Are you satisfied with the current seats? (y/n): ");
    input = getchar();
    getchar();

    if (input == 'y' || input == 'Y')
    {
        record_selected_seats(seat_map, temp_map);
        system("cls");
    }
}

/* Function to allow the user to choose seats manually*/
void choose_seats(char seat_map[ROWS][COLS])
{
    char input[10];
    int row, col;

    printf("Current seat map:\n");
    printf("\n");
    display_seat_map(seat_map);

    while (1)
    {
        printf("Enter your choice (e.g., 1-2 or 2-9). Press 'q' to quit: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q')
            break;

        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS)
        {
            printf("Invalid seat. Please choose again.\n");
            continue;
        }

        if (seat_map[row - 1][col - 1] == '*' || seat_map[row - 1][col - 1] == '@')
        {
            printf("Seat already reserved. Please choose again.\n");
            continue;
        }

        seat_map[row - 1][col - 1] = '@';
    }
}

/* Function to record the selected seats into the main seat map*/
void record_selected_seats(char seat_map[ROWS][COLS], char user_map[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (user_map[i][j] == '@')
            {
                seat_map[i][j] = '*';
            }
        }
    }
}
/*Function to manage the seat selection menu*/
void seat_selection_menu(char seat_map[ROWS][COLS])
{
    char user_map[ROWS][COLS];

    /* Copy the current seat map to a user map*/
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            user_map[i][j] = seat_map[i][j];
        }
    }

    system("cls");
    choose_seats(user_map);

    system("cls");
    printf("Seats have been recorded.\n");
    printf("Press ENTER three times to return to the main menu.\n");
    display_seat_map(user_map);
    getchar();
    record_selected_seats(seat_map, user_map);
}

int main(void)
{
    printf("All rights reserved.\n");
    for (int i = 1; i < 20; i++)
    {
        printf("All rights reserved.\n");
    }
    printf("Press ENTER to proceed");
    getchar();
    system("cls");

    int password, times = 0;
    while (times < 3)
    {
        printf("Password: ");
        scanf("%d", &password);
        if (password != 2024)
        {
            printf("Incorrect password. Try again.\n");
            times++;
        }
        else
        {
            printf("Press ENTER to proceed");
            getchar();
            system("cls");

            char seat_map[ROWS][COLS], ch;
            generate_seat_map(seat_map);
            while (1)
            {
                printf("-------------------------\n");
                printf("| a. Available seats    |\n");
                printf("| b. Arrange for you    |\n");
                printf("| c. Choose by yourself |\n");
                printf("| d. Exit               |\n");
                printf("-------------------------\n");

                printf("Please enter: ");
                scanf(" %c", &ch);

                switch (ch)
                {
                case 'A':
                case 'a':
                {
                    system("cls");
                    display_seat_map(seat_map);
                    system("cls");
                    continue;
                }

                case 'B':
                case 'b':
                {
                    system("cls");
                    ask_and_select_seats(seat_map);
                    system("cls");
                    continue;
                }

                case 'C':
                case 'c':
                {
                    system("cls");
                    seat_selection_menu(seat_map);
                    system("cls");
                    continue;
                }

                case 'D':
                case 'd':
                {
                    char ch2;
                    printf("Continue? (y/n): ");
                    scanf(" %c", &ch2);

                    if (ch2 == 'Y' || ch2 == 'y')
                    {
                        system("cls");
                        break;
                    }
                    else if (ch2 == 'N' || ch2 == 'n')
                    {
                        printf("Program ended\n");
                        return 0;
                    }
                    else
                    {
                        printf("Invalid input. Please enter y or n\n");
                        printf("Press any key to continue");
                        getch();
                        system("cls");
                        break;
                    }
                }
                default:
                    printf("\a");
                    system("cls");
                }
            }
        }
    }
    if (times == 3)
    {
        system("cls");
        printf("Exceeded the maximum number of attempts. Program ended\a");
        return 0;
    }
    return 0;
}
/*心得寫於commits*/