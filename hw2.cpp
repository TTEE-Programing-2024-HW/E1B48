#include<stdio.h>
#include<stdlib.h>
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











    return 0; 
}