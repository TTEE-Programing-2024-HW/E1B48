#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#define ROWS 9
#define COLS 9
#define RESERVED_COUNT 10

void generate_seat_map(char seat_map[ROWS][COLS]) 
{
    int reserved_seats = 0, row, col;
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seat_map[i][j] ='-';
  
    while (reserved_seats < RESERVED_COUNT) 
	{
        row = rand() % ROWS;
        col = rand() % COLS;
        if (seat_map[row][col] !='*') 
		{
            seat_map[row][col] ='*';
            reserved_seats++;
        }
    }
}

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

void select_seats(char seat_map[ROWS][COLS], int num_seats) 
{
    int row, col, direction, found = 0;

    srand(time(NULL));

    while (!found) 
	{
        row = rand() % ROWS;
        col = rand() % COLS;
        direction = rand() % 2;

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
		else if (direction == 1 && row + 1 < ROWS && col + 1 < COLS) 
		{
            found = 1;
            if (seat_map[row][col] != '-' || seat_map[row][col+1] != '-' || seat_map[row+1][col] != '-' || seat_map[row+1][col+1] != '-') 
			{
                found = 0;
            }
            if (found) 
			{
                seat_map[row][col] = '@';
                seat_map[row][col+1] = '@';
                seat_map[row+1][col] = '@';
                seat_map[row+1][col+1] = '@';
            }
        }
    }
}

void record_selected_seats(char seat_map[ROWS][COLS], char user_map[ROWS][COLS]);
void ask_and_select_seats(char seat_map[ROWS][COLS]) 
{
    int num_seats;
    char input;
    char temp_map[ROWS][COLS]; 

    
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            temp_map[i][j] = seat_map[i][j];
        }
    }

    while (1) 
    {
        printf("需要幾個座位?(1-4): ");
        scanf("%d", &num_seats);
        getchar();

        if (num_seats < 1 || num_seats > 4) 
        {
            printf("座位選擇錯誤 請重試\n"); 
        } 
        else 
        {
            
            if (num_seats < 4) {
                select_seats(temp_map, num_seats);
            } else {
                select_seats(temp_map, 2);
                select_seats(temp_map, 2);
            }
            
            break;
        }
    }

    system("cls");    
	display_seat_map(temp_map);

    printf("是否滿意現在座位?(y/n): ");
    input = getchar();
    getchar();

    if (input == 'y' || input == 'Y') 
	{
        
        record_selected_seats(seat_map, temp_map);
        system("cls");
    }
}

void choose_seats(char seat_map[ROWS][COLS]) 
{
    char input[10];
    int row, col;

    printf("目前的座位表:\n");
    printf("\n");
    display_seat_map(seat_map);

    while (1) 
    {
        printf("輸入你的選擇(例如 1-2或2-9)，若已選擇完畢 請按'q'以退出: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q') 
            break;

        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS) 
        {
            printf("座位不存在 請重選\n");
            continue;
        }

        if (seat_map[row-1][col-1] == '*' || seat_map[row-1][col-1] == '@') 
        {
            printf("座位已被預定 請重選\n");
            continue;
        }

        seat_map[row-1][col-1] = '@';
    }
}


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


void seat_selection_menu(char seat_map[ROWS][COLS]) 
{
    char user_map[ROWS][COLS]; 

    
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
	printf("已記錄位置\n");
	printf("按下3次ENTER回到主選單\n");
    display_seat_map(user_map);
    getchar(); 
    record_selected_seats(seat_map, user_map);
}

int main(void)
{ 
    printf("版權所有，翻印必究\n");
    for(int i=1;i<20;i++) 
    {
        printf("版權所有，翻印必究\n");  
    }
    printf("按ENTER進入下一步");
    getchar();  
    system("cls");

    int password, times = 0; 
    while (times < 3)  
    {
        printf("密碼:");
        scanf("%d", &password);
        if (password != 2024) 
        {
            printf("密碼錯誤 再試一次\n");
            times++;
        } 
        else  
        {
            printf("按ENTER進入下一步");
            getchar();
            system("cls");

            char seat_map[ROWS][COLS],ch; 
            generate_seat_map(seat_map);
            while (1)
            {
                printf("-------------------------\n"); 
                printf("| a. Available seats    |\n");
                printf("| b. Arrange for you    |\n");
                printf("| c. Choose by yourself |\n");
                printf("| d. Exit               |\n");
                printf("-------------------------\n");
               
                printf("請輸入:");
                scanf(" %c", &ch);
                
                switch(ch)
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
                        if(ch2 == 'Y' || ch2 == 'y') 
                        {
                            system("cls");
                            break;
                        } 
                        else if(ch2 == 'N' || ch2 == 'n') 
                        {
                            printf("程式結束\n");
                            return 0;
                        } 
                        else 
                        {
                            printf("輸入錯誤 請輸入y或n\n");
                            printf("按任何鍵繼續");
                            getch();
                            system("cls");
                            break;
                        } 
                    }
                    default : 
                        printf("\a");
                        system("cls");
                } 
            }
        }
    }
	if (times == 3) 
    {
        system("cls");
        printf("錯誤次數已到三 程式結束\a");
        return 0;
    }
    return 0;
}