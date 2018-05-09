#include <stdio.h>  
#include <iostream>  
#include <math.h>  
#include <string.h>  
#include <algorithm>  
using namespace std; 

int a[100][100];

void Table(int k)
{
	int n = 1;
	int i;
	for(i = 1; i <= k; i++)
		n *= 2;
	for(i = 1; i <= n; i++)
		a[1][i] = i;
	int m = 1;
	for(int s = 1; s <= k; s++)
	{
		n /= 2;
		for(int t = 1; t <= n; t++)
			for(i = m + 1; i <= 2 * m; i++)
				for(int j = m+1; j <= 2 * m; j++)
				{
					a[i][j + (t - 1) * m * 2] = a[i - m][j + (t - 1) * m * 2 - m];
					a[i][j + (t - 1) * m * 2 - m] = a[i - m][j + (t - 1) * m * 2];
				}
		m *= 2;
	}
}

void main()
{
	int n = 4;
	Table(n);
	for(int i = 1; i <= n; i++)  
	{  
		for(int j = 1; j <=n; j++)  
			printf("%2d ",a[i][j]);  
		printf("\n");  
	}  
}
 

  
/*void solve(int k,int n)  
{  
    int m = 1;///m用来控制每一次填充表格时i和j的起始填充位置  
      
    for(int i = 1; i <= n; i++)///对日程表第一行进行初始化  
        maps[1][i] = i;  
      
    for(int s = 1; s <= k; s++)///控制复制次数  
    {  
        n /= 2;  
        for(int t = 1; t <= n; t++)///控制复制对角块的次数  
        {  
            for(int i = m + 1; i <= 2 * m; i++)  
            {  
                for(int j = m + 1; j <= 2 * m; j++)  
                {  
                    maps[i][j + (t - 1) * m * 2] = maps[i-m][j + (t - 1) * m * 2 - m];///左上角的值复制给右下角  
                    maps[i][j + (t - 1) * m * 2 - m] = maps[i-m][j + (t - 1) * m * 2];///右上角的值复制给左下角  
                }  
            }  
        }  
        m *= 2;  
    }  
}  
  
int main()  
{  
    int k;  
    while(~scanf("%d",&k))  
    {  
        int num, n = 1;  
        for(int i = 1; i <= k; i++)  
            n *= 2;  
        num = n;  
        solve(k, n);  
        for(int i = 1; i <= num; i++)  
        {  
            for(int j = 1; j <= num; j++)  
                printf("%2d ",maps[i][j]);  
            printf("\n");  
        }  
    }  
    return 0;  
}  */