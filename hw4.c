#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*定義結構*/
typedef struct 
{
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

/*函數宣告*/
void inputStudents(int n, Student students[]);
int getIntegerInput(const char* prompt, int min, int max);
void displayStudents(int n, Student students[]);
void printError(const char* message);
float calculateAverage(int math, int physics, int english);
void searchStudent(int n, Student students[]);
void sortStudents(int n, Student students[]);

int main(void)
{ 
    /*個人風格畫面*/
    printf("版權所有，翻印必究\n");
    for(int i=1;i<20;i++) 
    {
        printf("版權所有，翻印必究\n");  
    }
    printf("按ENTER進入下一步");
    getchar();  
    system("cls");

    /*密碼驗證*/
    int password, times = 0; 
    while (times < 3)  
    {
        printf("密碼:");
        scanf("%d", &password);
        if (password != 2024) 
        {
            /*失敗*/
            printf("密碼錯誤 再試一次\n");
            times++;
        } 
        else  
        {
            /*成功*/
            printf("按ENTER進入下一步");
            getchar();
            system("cls");

            char ch;
            int n = 0;
            Student students[10];
            while (1)
            {
                /*主畫面*/
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
                        /*輸入資料*/
                        system("cls");
                        n = getIntegerInput("請輸入學生數目(5~10): ", 5, 10);
                        inputStudents(n, students);
                        break;  
                    }
           
                    case 'B':	 
                    case 'b':
                    {
                        /*顯示資料*/
                        system("cls");
                        displayStudents(n, students);
                        getchar();
                        break; 
                    }

                    case 'C':
                    case 'c':
                    {
                        /*搜索特定資料*/
                        system("cls");
                        searchStudent(n, students);
                        getchar();
                        break;
                    }
                    
                    case 'D':
                    case 'd':
                    {
                        /*排序資料*/
                    	system("cls");
                        sortStudents(n, students);
                        getchar();
                        break;
                    }
                    
                    case 'E':	 
                    case 'e':
                    {
                        /*退出*/
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
        /*密碼輸錯三次*/
        system("cls");
        printf("錯誤次數已到三 程式結束\a"); ㄆ
        return 0;
    }
    return 0;
} 
/*提示句*/
void printError(const char* message) 
{
    printf("錯誤: %s\n", message);
}
/*計算平均*/
float calculateAverage(int math, int physics, int english)
{
    return (math + physics + english) / 3.0;
}
/*輸入所有資料*/
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
/*驗證*/
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
/*顯示資料*/
void displayStudents(int n, Student students[]) 
{
    for (int i = 0; i < n; i++) {
        printf("姓名: %s, 學號: %s, 數學: %d, 物理: %d, 英文: %d, 平均成績: %.1f\n", 
                students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
}
/*搜索功能*/
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
/*排序*/
void sortStudents(int n, Student students[]) 
{
    Student temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("姓名: %s, 學號: %d, 平均成績: %.1f\n", 
                students[i].name, students[i].id, students[i].average);
    }
}