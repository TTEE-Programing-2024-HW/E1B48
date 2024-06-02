#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct 
{
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

void inputStudents(int n, Student students[]);
int getIntegerInput(const char* prompt, int min, int max);
void displayStudents(int n, Student students[]);
void printError(const char* message);
float calculateAverage(int math, int physics, int english);
void searchStudent(int n, Student students[]);

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

            char ch;
            int n = 0;
            Student students[10];
            while (1)
            {
                printf("------------------------------------\n"); 
                printf("|   a. Enter student grades        |\n");
                printf("|   b. Display student grades      |\n");
                printf("|   c. Search for student grades   |\n");
                printf("|   d. Grade ranking               |\n");
                printf("|   e. Exit system                 |\n");
                printf("------------------------------------\n");
               
                printf("請輸入:");
                scanf(" %c", &ch);
                
                switch(ch)
                {
                    case 'A':	
                    case 'a':
                    { 
                        system("cls");
                        n = getIntegerInput("請輸入學生數目(5~10): ", 5, 10);
                        inputStudents(n, students);
                        break;  
                    }
           
                    case 'B':	 
                    case 'b':
                    {
                        system("cls");
                        displayStudents(n, students);
                        getchar();
                        break; 
                    }

                    case 'C':
                    case 'c':
                    {
                        system("cls");
                        searchStudent(n, students);
                        getchar();
                        break;
                    }
                    
                    case 'D':
                    case 'd':
                    {
                    	
                    }
                    
                    case 'E':	 
                    case 'e':
                    {
                        char ch2;
                        printf("確定離開? (y/n): ");
                        scanf(" %c", &ch2);
                        if(ch2 == 'N' || ch2 == 'n') 
                        {
                            system("cls");
                            break;
                        } 
                        else if(ch2 == 'Y' || ch2 == 'y') 
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
void printError(const char* message) 
{
    printf("錯誤: %s\n", message);
}

float calculateAverage(int math, int physics, int english)
{
    return (math + physics + english) / 3.0;
}

void inputStudents(int n, Student students[]) 
{
    for (int i = 0; i < n; i++) {
        printf("輸入第%d個學生資料:\n", i + 1);
        printf("姓名: ");
        scanf("%s", students[i].name);
        students[i].id= getIntegerInput("學號(6位整數): ", 100000, 999999);
        students[i].math = getIntegerInput("數學成績(0~100): ", 0, 100);
        students[i].physics = getIntegerInput("物理成績(0~100): ", 0, 100);
        students[i].english = getIntegerInput("英文成績(0~100): ", 0, 100);
        students[i].average = calculateAverage(students[i].math, students[i].physics, students[i].english);
    }
}

int getIntegerInput(const char* prompt, int min, int max) 
{
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printError("輸入無效。請輸入一個整數。");
            fflush(stdin); 
        } else if (value < min || value > max) {
            printError("數值超出範圍。請重新輸入。");
        } else {
            break;
        }
    }
    return value;
}

void displayStudents(int n, Student students[]) 
{
    for (int i = 0; i < n; i++) {
        printf("姓名: %s, 學號: %s, 數學: %d, 物理: %d, 英文: %d, 平均成績: %.1f\n", 
                students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
}

void searchStudent(int n, Student students[])
{
    char searchName[50];
    printf("請輸入要搜尋的學生姓名: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("姓名: %s, 學號: %d, 數學: %d, 物理: %d, 英文: %d, 平均成績: %.1f\n", 
                    students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("資料不存在。\n");
    }
}