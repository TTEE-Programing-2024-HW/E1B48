#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(void)
{ 
    printf("版權所有，翻印必究\n");
    for(int i=1;i<20;i++) /*個人風格畫面*/
    {
        printf("版權所有，翻印必究\n");  
    }
    printf("按ENTER進入下一步");
    getchar();  
    system("cls");

    int password, times = 0; /*輸入密碼*/ 
    while (times < 3) /*當錯誤次數小於3時，所執行的結果*/ 
    {
        printf("密碼:");
        scanf("%d", &password);
        if (password != 2024) 
        {
            printf("密碼錯誤 再試一次\n");
            times++;
        } 
        else /*密碼正確*/ 
        {
            printf("按ENTER進入下一步");
            getchar();
            system("cls");

            
            while (1)
            {
                printf("-------------------------\n"); /*主選單*/ 
                printf("| a. Available seats    |\n");
                printf("| b. Arrange for you    |\n");
                printf("| c. Choose by yourself |\n");
                printf("| d. Exit               |\n");
                printf("-------------------------\n");
               
                printf("請輸入:");
                scanf(" %c", &ch);
                
                switch(ch)
                {
                    case 'A':	/*題一*/ 
                    case 'a':
                    {
                         
                    }
           
                    case 'B':	/*題二*/ 
                    case 'b':
                    {
                        
                    }

                    case 'C':	/*題三*/ 
                    case 'c':
                    {
                        
                    }

                    case 'D':	/*題四*/ 
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
                    default :/*不符合上述三種*/ 
                        printf("\a");
                        system("cls");
                } 
            }
        }
    }
	if (times == 3) /*輸錯三次*/ 
    {
        system("cls");
        printf("錯誤次數已到三 程式結束\a");
        return 0;
    }
    return 0;
}