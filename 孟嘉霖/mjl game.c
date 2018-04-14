#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAXIMUS 15 

int p[MAXIMUS][MAXIMUS];
char buff[MAXIMUS*2+1][MAXIMUS*4+3];
int Cx,Cy;
int Now;
int wl,wp;
char* showText;
int count;

void menu()
{
	printf("\n");
	printf("               ★---您好，欢迎来到五子棋世界！---★\n\n"); 
	printf("           --------------------------------------------\n");
	printf("           ≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n");
    printf("           && * -------- ☆  1.进入游戏 ☆-------- * &&\n"
		   "           && * -------- ☆  2.游戏说明 ☆-------- * &&\n"
	       "           && * -------- ☆  3.退出     ☆-------- * &&\n");
	printf("           ≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n");
	printf("           --------------------------------------------\n\n");
	printf("请在1-3中选择以回车键结束：\n\n");
}
void menu2()
{
	
	system("cls");
	printf("\n\n\n");
	printf("       ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("       ☆                                          ☆\n");
        printf("       ☆              谢谢使用，再见！            ☆\n");
	printf("       ☆                                          ☆\n");
	printf("        ☆                                          ☆\n");
	printf("         ☆                            by Kristin    ☆\n");
	printf("          ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
}
void menu3()
{

	printf("\n\n\n");
	printf("       ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("       ☆                                          ☆\n");
    printf("       ☆              1、再来一局                 ☆\n");
	printf("       ☆              2、退出                     ☆\n");
	printf("       ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
	
		
}
void Introduce()
{
	printf("\n");
	printf("                       ※  游戏说明 ※           \n\n");
	printf("  【游戏规则：】\n\n");
	printf("        → → → → → → → → → → → → → → → → \n");
	printf("      ↑ 五子棋专用棋盘为 15×15,盘面有纵横各十五条等 ↓\n");	
	printf("      ↑ 距离垂直交叉 的平行线构成,共225个交叉点 盘面 ↓\n");
	printf("      ↑ 正中一点为'天元 黑先、白后,从天元(h8)开始    ↓\n");
	printf("      ↑ 相互顺序落子。黑方的第一个棋子应下在天元上,  ↓\n");
	printf("      ↑ 白方第一个棋子只能下在与天元为中心邻近的八   ↓\n");
	printf("      ↑ 个点上,黑方第二个棋子只能下在与天元为中心邻  ↓\n");
	printf("      ↑ 近5×5点上,白棋第二个棋子不受限制,可下在棋盘 ↓\n");
	printf("      ↑ 任意位置 最先在棋盘横向 竖向 斜向形成连续的  ↓\n");
	printf("      ↑ 相同色五个棋子的一方为胜!                    ↓\n");
	printf("      ↑                                              ↓\n");
	printf("      ↑ 在游戏过程中，玩家可用上下左右键控制棋子，空 ↓\n");
	printf("      ↑ 格键落子。                                   ↓\n");
	printf("       ← ← ← ← ← ← ← ← ← ← ← ←  ← ← ← ← \n");
	printf("  【提示：】 \n\n");
	printf("         游戏过程中，可按Esc键退出！\n");
	getch();
}
char* Copy(char* strDest,const char* strSrc)
{
  char* strDestCopy = strDest;
  while (*strSrc!='\0')
  {
     *strDest++=*strSrc++;
  }
  return strDestCopy;
}
void Initialize()
{
  int i,j;
  showText="";
  count=0;
  for(i=0;i<MAXIMUS;i++)
  {
     for(j=0;j<MAXIMUS;j++)
	 {
         p[i][j]=0;
	 }
  }
  Cx=Cy=MAXIMUS/2;
  Now=1;
} 
char* getStyle(int i,int j)
{
   if(p[i][j]==1)
     return "●";
   else if(p[i][j]==2)
     return "○";
   else if(i==0&&j==0)
     return "┏";
   else if(i==MAXIMUS-1&&j==0)
     return "┓";
   else if(i==MAXIMUS-1&&j==MAXIMUS-1)
     return "┛";
   else if(i==0&&j==MAXIMUS-1)
     return "┗";
   else if(i==0)
     return "┠";
   else if(i==MAXIMUS-1)
     return "┨";
   else if(j==0)
     return "┯";
   else if(j==MAXIMUS-1)
     return "┷";
   return "┼";//中间的空位
}
char* getCurse(int i,int j)
{
	
    if(i==Cx)
	{
       if(j==Cy)
          return "┏";
       else if (j==Cy+1)
          return "┗";
	}
    else if(i==Cx+1)
	{
       if(j==Cy)
          return "┓";
       else if (j==Cy+1)
          return "┛";
	}
    return "　";
}
void write(char* c)
{
	Copy(buff[wl]+wp,c);
    wp+=strlen(c);
}
void ln()
{
	wl+=1;
    wp=0;
}
void Display()
{
	int i,l=strlen(showText);
    int Offset=MAXIMUS*2+2-l/2;
    if(Offset%2==1)
	{
        Offset--;
	}
    Copy(buff[MAXIMUS]+Offset,showText);
    if(l%2==1)
	{
        *(buff[MAXIMUS]+Offset+l)=0x20;
	}
    system("cls");
    for(i=0;i<MAXIMUS*2+1;i++){
        printf("%s",buff[i]);
    if(i<MAXIMUS*2)
        printf("\n");
	}
}
void Print()
{
	int i,j;
    wl=0;
    wp=0;
    for(j=0;j<=MAXIMUS;j++)
	{
        for(i=0;i<=MAXIMUS;i++)
		{
              write(getCurse(i,j));
              if(j==0||j==MAXIMUS)
			  {
                   if(i!=MAXIMUS)
                       write("　");
			  }
              else
			  {
                   if(i==0||i==MAXIMUS-1)
                       write("┃");
                   else if(i!=MAXIMUS)
                       write("│");
			  }
		}
        if(j==MAXIMUS)
		{
             break;
		}
        ln();
		write("　");
        for(i=0;i<MAXIMUS;i++)
		{
             write(getStyle(i,j));
             if(i!=MAXIMUS-1)
			 {
                  if(j==0||j==MAXIMUS-1)
				  {
                        write("━");
				  }
                  else
				  {
                        write("—");
				  }
			 }
		 }
         ln();
	}
    Display();
}
int Put()
{
	
	if(p[Cx][Cy]==0)
	{
         p[Cx][Cy]=Now;
         return 1;
	}
    else
	{
        return 0;
	}
}
int Check()
{
	int w=1,x=1,y=1,z=1,i;
    for(i=1;i<5;i++)
		if(Cy+i<MAXIMUS&&p[Cx][Cy+i]==Now)
			w++;
		else break;
    for(i=1;i<5;i++)
		if(Cy-i>0&&p[Cx][Cy-i]==Now)
		w++;
		else break;
    if(w>=5)
		return Now;
    for(i=1;i<5;i++)
		if(Cx+i<MAXIMUS&&p[Cx+i][Cy]==Now)
			x++;
		else break;
    for(i=1;i<5;i++)
		if(Cx-i>0&&p[Cx-i][Cy]==Now)
			x++;
		else break;
    if(x>=5)
		return Now;
    for(i=1;i<5;i++)
		if(Cx+i<MAXIMUS&&Cy+i<MAXIMUS&&p[Cx+i][Cy+i]==Now)
			y++;
		else break;
    for(i=1;i<5;i++)
		if(Cx-i>0&&Cy-i>0&&p[Cx-i][Cy-i]==Now)
			y++;
		else break;
    if(y>=5)
		return Now;
    for(i=1;i<5;i++)
		if(Cx+i<MAXIMUS&&Cy-i>0&&p[Cx+i][Cy-i]==Now)
			z++;
		else break;
    for(i=1;i<5;i++)
		if(Cx-i>0&&Cy+i<MAXIMUS&&p[Cx-i][Cy+i]==Now)
			z++;
		else break;
    if(z>=5)
		return Now;
    return 0;
}
int RunGame()
{
	int input;
    int victor;
    Initialize();
    while(1)
	{
    Print();
    input=getch();
    if(input==27)
	{
		menu2();
		getch();
        exit(0);
	}
    else if(input==0x20)
	{
        if(Put())
		{
             victor=Check();
             Now=3-Now;
             count++;
             if(victor==1)	 {
                   showText="黑方获得了胜利！";
                   Print(); 
                   if(getch()==0xE0)
				   {
                       getch();
				   }
                   return Now;
			 }
             else if(victor==2)

			 {
                   showText="白方获得了胜利！";
                   Display();
                   if(getch()==0xE0)
				   {
                       getch();
				   }
                   return Now;
			 }
			 else if(count==MAXIMUS*MAXIMUS)
			 {
                   showText="平局！";
                   Display();
                   if(getch()==0xE0)
				   {
                        getch();
				   }
                   return 0;
			 }
		}
	}
    else if(input==0xE0)
	{
         input=getch();
         switch(input)
		 {
              case 0x4B:
                   Cx--;
                   break;
              case 0x48:
                   Cy--;
                   break;
              case 0x4D:
                   Cx++;
                   break;
              case 0x50:
                   Cy++;
                   break;
		 }
         if(Cx<0)
			 Cx=MAXIMUS-1;
         if(Cy<0)
			 Cy=MAXIMUS-1;
         if(Cx>MAXIMUS-1)
			 Cx=0;
         if(Cy>MAXIMUS-1)
			 Cy=0;
	}
	}
}
void main()
{
	char x;
	int a=0;
	system("title 简易五子棋 ——孟嘉霖制作");
    system("mode con cols=63 lines=32");
    system("color A1");
	printf("\n");
	do
	{
		a++;
		menu();
        printf("请输入您的选择：");
		if(a==1)
           scanf("%s",&x);
		else
			scanf("\n%s",&x);
		if(x!='1'&&x!='2'&&x!='3')
		{
			printf("输入错误!请重新输入!");
			getch();
			system("cls");
			
		}
		else
		{
		    switch(x)
			{
	            case '1':RunGame();
					system("cls");
	                break;
	            case '2':system("cls");
			         Introduce();
					 system("cls");
					 break;
			}
              

			    
		}
		
	}while(x!='3');
	menu2();
	

}  