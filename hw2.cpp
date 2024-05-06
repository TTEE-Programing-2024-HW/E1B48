#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
                printf("---------------------------\n"); /*主選單*/ 
                printf("|   a. 畫出直角三角形     |\n");
                printf("|   b. 顯示乘法表         |\n");
                printf("|   c. 結束               |\n");
                printf("---------------------------\n");
            
                printf("請輸入:");
                char ch;
                scanf(" %c", &ch);
                
                switch(ch)
                {
                    case 'A':	/*題一*/ 
                    case 'a':
                    {
                        char ch1;
                        system("cls");
                        printf("輸入一個A到N之間的字元: ");
                        scanf(" %c", &ch1);
                        while(ch1 < 'a' || ch1 > 'n' )
                        {
                            printf("輸入錯誤\n");
                            printf("輸入一個A到N之間的字元: ");
                            scanf(" %c", &ch1);
                            system("cls");
                        }
                        ch1=(ch1>='a' && ch1<='z') ?ch1-('a'-'A'):ch1;
                                    
                        int num=ch1-'A'+1;
                        for(int i=1; i<= num; i++) 
                        {
                            for(int j=1; j<=i; j++) 
                            {
                                printf("%c ",'a'+ j-1);
                            }
                            printf("\n");
                        }
                        printf("按任意鍵繼續...");
                        getch();
                        system("cls");
                        break;
                    } 
                    case 'B':/*題二*/ 
                    case 'b':
                    {
                        int num1;
                        system("cls");
                        printf("請輸入1到9之間的整數: ");
                        scanf("%d", &num1);
                        while(num1< 1 || num1 > 9) 
                        {
                            system("cls");
                            printf("輸入錯誤\n");
                            printf("請輸入1到9之間的整數:");
                            scanf(" %d", &num1);
                            system("cls");
                        }
                        for(int i=1;i<=num1;++i) 
                        {
                            for(int j=1;j<=num1;++j) 
                            {
                                printf("%d*%d=%d\t",i ,j ,i*j);
                            }
                            printf("\n");
                        }
                        printf("按任意鍵繼續...");
                        getch();
                        system("cls");
                        break;	  	
                    }
                    case 'C':/*題三*/ 
                    case 'c':
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
                    
                }       
            
            }
        }  
            
    }       
    return 0; 
}