#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>
#define MAX 50
/*定义结构体*/
typedef struct train
{
    char Origin[20];
    char Destination[20];
    char Number[10];
    int Seat[3];		//【0】商务座 【1】一等座 【2】二等座
    float Price[3];
    struct train *next;
} Train;
typedef struct
{
    Train *Ticket[MAX];
    int Quantity[MAX][3];
    int Mark[MAX][3];
    int N, count;
} User;
/*全局变量*/
Train *flag_add[MAX], *flag_num[MAX];
User MJL;   	 //用户（默认为孟嘉霖）
/*子函数*/
void Input(Train **H);
void Output(Train *H);
void Menu(Train *H);
int Search_Add(Train *H);
int Search_Num(Train *H);
void Fun_Sell(Train *H);
void Fun_Refund(Train *H);
void Fun_Inquire(Train *H);
void Use_System_Buy(Train *p, int seat, int quan);
void Use_System_Refund(int num, int seat, int quan);
void Use_System_Print();
int main()
{
    system("color F2");		//改变背景与字体颜色
    Train *Head;
    Head = (Train *)malloc(sizeof(Train));	//建立头结点
    Head->next = NULL;
    Input(&Head);	//通过文件读取信息
    Menu(Head);		//进入菜单选项
    return 0;
}
void Input(Train **H)
{
    FILE *fp1;
    if((fp1 = fopen("d:\\Test.txt", "r")) == NULL)
    {
        printf("Can't open file!\n");
        getch();
    }
    Train *p, *s;
    s = p = (*H);
    while(1)
    {
        s = (Train *)malloc(sizeof(Train));
        if(fscanf(fp1, "%s %s %s %d %d %d %f %f %f", s->Origin, s->Destination, s->Number,
                  &s->Seat[0], &s->Seat[1], &s->Seat[2], &s->Price[0], &s->Price[1], &s->Price[2]) == EOF)
            break;
        s->next = NULL;
        p->next = s;
        p = s;//尾插法
    }
}
void Output(Train *H)
{
    Train *p;
    p = H->next;
    printf("起始地\t\t终点\t\t车次\t商务座\t\t一等座\t\t二等座（票价/余票）\n\n");
    while(p != NULL)
    {
        printf("%s\t\t%s\t\t%s\t%.1f/%-4d\t%.1f/%-4d\t%.1f/%-4d\n",
               p->Origin, p->Destination, p->Number, p->Price[0], p->Seat[0],
               p->Price[1], p->Seat[1], p->Price[2], p->Seat[2]);
        p = p->next;
     }
}
void Save(Train *H)//保存
{ 
	Train *p;
    p = H->next;
    FILE *fp;
    char filename[]=("e:\\Test.txt");;
    fp=fopen(filename,"w");
    while(p != NULL)
    {
        fprintf(fp,"%s\t%s\t%s\t%d\t%d\t%d\t%.1f\t%.1f\t%.1f", p->Origin,p->Destination, p->Number,
        p->Seat[0], p->Seat[1], p->Seat[2], p->Price[0], p->Price[1], p->Price[2]);
		fprintf(fp,"\n");
		p=p->next;
	}
      fclose(fp);
      printf("数据已保存成功!\n");
}
void Menu(Train *H)
{ 
	char menu[]=("\n★---您好，欢迎来到西安高铁售票系统！---★\n\n\
	                            ------------------------------------------------\n\
	≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n\
      && * -------- ☆  1.售票         ☆-------- * &&\n\
	&& * -------- ☆  2.退票         ☆-------- * &&\n\
	&& * -------- ☆  3.剩余车票查询 ☆-------- * &&\n\
	&& * -------- ☆  0.退出         ☆-------- * &&\n\
	≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n\
	                            ------------------------------------------------\n\n");
  
      initgraph(962, 648);     
	IMAGE img;   //  定义  IMAGE  对象    
	loadimage(&img, "C:\\Users\\DELL\\Desktop\\timg25.jpg"); 
 //  读取图片到  img  对象中    
	 putimage(0, 0, &img);  //  在坐标  (0, 0)  位置显示   IMAGE  对象    
       getch();     
	 closegraph(); 
int sel;
      do
      {
         printf("%s", menu);
Loop:
         printf("\n请在0-3中选择：");
         while(scanf("%d", &sel) != 1)
         {
            printf("输入错误！请重新输入！\n");
            printf("请在0-3中选择：");
            getchar();
         }
         switch(sel)
         {
        case 1:
            system("CLS");
            Fun_Sell(H);
			 Save(H);
            getch();
            system("CLS");
            break;
        case 2:
            system("CLS");
            Fun_Refund(H);
			 Save(H);
            getch();
            system("CLS");
            break;
         case 3:
             system("CLS");
             Fun_Inquire(H);
             getch();
             system("CLS");
             break;
          case 0:
             break;
          default:
             printf("输入错误！请重新输入！\n");
             goto Loop;
         }
     }
     while(sel != 0);
}
int Search_Add(Train *H)
{
    int i = 0;
    char s[20];
    printf("请输入始发地：");
    scanf("%s", s);
    Train *p;
    p = H->next;
    while(p != NULL)
        if(!strcmp(s, p->Origin))
        {
            flag_add[i++] = p;
            p = p->next;
        }
        else
            p = p->next;
    return i;
}
int Search_Num(Train *H)
{
    int i = 0;
    char s[20];
    printf("请输入车次信息：");
    scanf("%s", s);
    Train *p;
    p = H->next;
    while(p != NULL)
        if( !strcmp(s, p->Number) )
        {
            flag_num[i++] = p;
            p = p->next;
        }
        else
            p = p->next;
    return i;
}
void Fun_Sell(Train *H)
{
    char menu[] = {"\n            * * * * * * * * * * *\n\
                                  *        售票       *\n\
                                  *     1、起始地     *\n\
                                  *     2、车次       *\n\
                                  *     0、退出       *\n\
                                  * * * * * * * * * * *\n"
                  };
    int i, n_Add, n_Num;
    int num, seat, quan;
    int sel;
    do
    {
        printf("%s", menu);
Loop3:
        printf("请在0-2中选择：");
        while(scanf("%d", &sel) != 1)
        {
            printf("输入错误！请重新输入！\n");
            printf("请在0-3中选择：");
            getchar();
        }
        switch(sel)
        {
        case 1:
            n_Add = Search_Add(H);
            if(n_Add == 0)
            {
                printf("无此趟列车，请重新选择。\n");
                goto Loop3;
            }
            printf("     起始地\t\t终点\t\t车次\t商务座\t\t一等座\t\t二等座（票价/余票）\n");
            for(i=0; i<n_Add; i++)
                printf("【%d】%s\t\t%s\t\t%s\t%.1f/%-4d\t%.1f/%-4d\t%.1f/%-4d\n", i+1,
                       flag_add[i]->Origin, flag_add[i]->Destination, flag_add[i]->Number,
                       flag_add[i]->Price[0], flag_add[i]->Seat[0],
                       flag_add[i]->Price[1], flag_add[i]->Seat[1],
                       flag_add[i]->Price[2], flag_add[i]->Seat[2]);
Loop1:
            printf("请选择编号：");
            scanf("%d", &num);
            while(num<1 || num>n_Add)
            {
                printf("请重新选择编号：");
                scanf("%d", &num);
            }
            printf("【%d】%s\t\t%s\t\t%s\t%.1f/%-4d\t%.1f/%-4d\t%.1f/%-4d\n", num,
                   flag_add[num-1]->Origin, flag_add[num-1]->Destination, flag_add[num-1]->Number,
                   flag_add[num-1]->Price[0], flag_add[num-1]->Seat[0],
                   flag_add[num-1]->Price[1], flag_add[num-1]->Seat[1],
                   flag_add[num-1]->Price[2], flag_add[num-1]->Seat[2]);
            printf("请选择座位（1为商务座，2为一等座，3为二等座）：");
            scanf("%d", &seat);
            while(seat<1 || seat>3)
            {
                printf("请重新选择座位：");
                scanf("%d", &seat);
            }
            printf("请选择票数：");
            scanf("%d", &quan);
            if(quan > flag_add[num-1]->Seat[seat-1])
            {
                printf("数量不足，请重新选择。\n");
                goto Loop1;
            }
            else
            {
                Use_System_Buy(flag_add[num-1], seat, quan);    //进入用户系统
                flag_add[num-1]->Seat[seat-1] -= quan;
                printf("预订成功！请跳转至支付页面支付...\n");
            }
            getch();
            system("CLS");
            break;
        case 2:
            n_Num = Search_Num(H);
            if(n_Num == 0)
            {
                printf("无此趟列车，请重新选择。\n");
                goto Loop3;
            }
            printf("     起始地\t\t终点\t\t车次\t商务座\t\t一等座\t\t二等座（票价/余票）\n");
            for(i=0; i<n_Num; i++)
                printf(
【%d】%s\t\t%s\t\t%s\t%.1f/%-4d\t%.1f/%-4d\t%.1f/%-4d\n", i+1,             flag_num[i]->Origin,flag_num[i]->Destination,flag_num[i]->Number,
                       flag_num[i]->Price[0], flag_num[i]->Seat[0],
                       flag_num[i]->Price[1], flag_num[i]->Seat[1],
                       flag_num[i]->Price[2], flag_num[i]->Seat[2]);
Loop2:
            printf("请选择编号：");
            scanf("%d", &num);
            while(num<1 || num>n_Num)
            {
                printf("请重新选择编号：");
                scanf("%d", &num);
            }
            printf("【%d】%s\t\t%s\t\t%s\t%.1f/%-4d\t%.1f/%-4d\t%.1f/%-4d\n", num,
                   flag_num[num-1]->Origin, flag_num[num-1]->Destination, flag_num[num-1]->Number,
                   flag_num[num-1]->Price[0], flag_num[num-1]->Seat[0],
                   flag_num[num-1]->Price[1], flag_num[num-1]->Seat[1],
                   flag_num[num-1]->Price[2], flag_num[num-1]->Seat[2]);
            printf("请选择座位（1为商务座，2为一等座，3为二等座）：");
            scanf("%d", &seat);
            while(seat<1 || seat>3)
            {
                printf("请重新选择座位：");
                scanf("%d", &seat);
            }
            printf("请选择票数：");
            scanf("%d", &quan);
            if(quan > flag_num[num-1]->Seat[seat-1])
            {
                printf("数量不足，请重新选择。\n");
                goto Loop2;
            }
            else
            {
                Use_System_Buy(flag_num[num-1], seat, quan);    //进入用户系统
                flag_num[num-1]->Seat[seat-1] -= quan;
                printf("预订成功！请跳转至支付页面支付...\n");
            }
            getch();
            system("CLS");
            break;
        case 0:
            printf("请按任意键继续...");
            break;
        default:
            printf("输入错误！请重新输入！\n");
            goto Loop3;
        }
    }
    while(sel != 0);
}
void Fun_Refund(Train *H)
{
    int num, seat, quan;
    printf("-------------------退票--------------------\n");
    if(MJL.count == 0)
    {
        printf("您暂无车票！\n");
    }
    else
    {
        Use_System_Print();
Loop4:
        printf("请选择编号：");
        scanf("%d", &num);
        while(num<1 || num>MJL.N)
        {
            printf("请重新选择编号：");
            scanf("%d", &num);
        }
        printf("【%d】%s\t\t%s\t\t%s\t%d张\t%d张\t%d张\n", num,
               MJL.Ticket[num-1]->Origin, MJL.Ticket[num-1]->Destination, MJL.Ticket[num-1]->Number,
               MJL.Quantity[num-1][0], MJL.Quantity[num-1][1], MJL.Quantity[num-1][2]);
        printf("请选择座位（1为商务座，2为一等座，3为二等座）：");
        scanf("%d", &seat);
        while(seat<1 || seat>3)
        {
            printf("输入错误！请重新选择座位：");
            scanf("%d", &seat);
        }
        if(MJL.Mark[num-1][seat-1] != 1)
        {
            printf("此车票非车站售出或者尚未售出，不可退换！\n");
            goto Loop4;
        }
        printf("请选择票数：");
        scanf("%d", &quan);
        while(quan<1 || quan>MJL.Quantity[num-1][seat-1])
        {
            printf("输入错误！请重新选择票数：\n");
            scanf("%d", &quan);
        }
        Use_System_Refund(num, seat, quan);
        MJL.Ticket[num-1]->Seat[seat-1] += quan;
        printf("退订成功！欢迎下次使用...\n");
    }
}
void Fun_Inquire(Train *H)
{
    char menu[] = {"\n         *  *  *  *  *  *  *  *  *  *\n\
                               *       剩余车票查询       *\n\
                               *       1、全部车票        *\n\
                               *       2、已购得车票      *\n\
                               *       0、退出            *\n\
                               *  *  *  *  *  *  *  *  *  *\n"
                  };

    int sel;		//定义菜单选择变量
    do
    {
        printf("%s", menu);
Loop5:
        printf("\n请在0-2中选择：");
        while(scanf("%d", &sel) != 1)
        {
            printf("输入错误！请重新输入！\n");
            printf("请在0-2中选择：");
            getchar();
        }
        switch(sel)
        {
        case 1:
            system("CLS");
            Output(H);
            getch();
            system("CLS");
            break;
        case 2:
            system("CLS");
            Use_System_Print();
            getch();
            system("CLS");
            break;
        case 0:
            printf("请按任意键继续...");
            break;
        default:
            printf("输入错误！请重新输入！\n");
            goto Loop5;
        }
    }
    while(sel != 0);
}
void Use_System_Buy(Train *p, int seat, int quan)
{
    int i, flag = 0;
    MJL.count += quan;
    for(i=0; i<MJL.N; i++)
        if(p == MJL.Ticket[i])
        {
            flag = 1;
            break;
        }
    if( !flag )
    {
        MJL.Ticket[MJL.N] = p;
        MJL.Quantity[MJL.N][seat-1] += quan;
        MJL.Mark[MJL.N][seat-1] = 1;
        MJL.N++;
    }
    else
        MJL.Quantity[i][seat-1] += quan;
}
void Use_System_Refund(int num, int seat, int quan)
{
    int i;
    MJL.count -= quan;
    MJL.Quantity[num-1][seat-1] -= quan;
    if(!MJL.Quantity[num-1][0] && !MJL.Quantity[num-1][1] && !MJL.Quantity[num-1][2])
    {
        if(num == MJL.N)
            MJL.N--;
        else
        {
            for(i=num-1; i<MJL.N; i++)
            {
                MJL.Ticket[num-1] = MJL.Ticket[num];
                MJL.Quantity[num-1][0] = MJL.Quantity[num][0];
                MJL.Quantity[num-1][1] = MJL.Quantity[num][1];
                MJL.Quantity[num-1][2] = MJL.Quantity[num][2];
            }
            MJL.N--;
        }
     }
}
void Use_System_Print()
{
    int i;
    printf("您一共拥有%d趟列车的共%d张票，分别是：\n", MJL.N, MJL.count);
    printf("     起始地\t\t终点\t\t车次\t商务座\t一等座\t二等座\n");
    for(i=0; i<MJL.N; i++)
        printf("【%d】%s\t\t%s\t\t%s\t%d张\t%d张\t%d张\n",
               i+1, MJL.Ticket[i]->Origin, MJL.Ticket[i]->Destination, MJL.Ticket[i]->Number,
               MJL.Quantity[i][0], MJL.Quantity[i][1], MJL.Quantity[i][2]);
}
2. 电视大赛观众投票及排名系统（排序应用）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define N 9 //假设选手人数不超过9
typedef struct node  //定义结构体
{
    int number; //编号
    char name[20]; //姓名
    int sum; //票数
	int tax;//名次
}mjl[N];
mjl*p;
int numbers=0;//总共的选手人数
void shuru()  //定义shuru函数，输入选手信息
{
	int i=1,n;
	system("cls");
  p=(mjl*)malloc(sizeof(mjl));   //用malloc函数分配动态内存
  while(1)
	{
		printf("请输入选手的数量:\n");
		scanf("%d",&n);
		getchar();  //输入选手数，放入缓冲区
		numbers=n;//总共的选手数就为n
		if((n<=0)||(n>9))
		{
			printf("输入错误！\n");
		}
		else
			break;
	}
	printf("请输入%d名选手的编号和姓名:\n",n);
    while(n--)   //while循环输入选手信息并存储
    {
        scanf("%d%s",&p[i]->number,p[i]->name);
        getchar();
		     p[i]->sum=0;
        i++;
    }
    printf("输入完成!\n");
    printf("选手信息如下:\n");  //在运行界面显示选手信息
    printf("编号\t姓名\n");
    for(i=1;i<=numbers;i++)
    {
		printf("%d\t%s\n",p[i]->number ,p[i]->name);
	}
}
void toupiao()  //定义toupiao函数
{
	    int i,n;//定义整型i为选手编号、n为投票数
	for(i=1;i<=numbers;i++)
       p[i]->sum =0;//将每一位选手的投票数初值计0
    printf("投票开始啦!\n");
    printf("请观众通过按键进行投票，按'1'为1号选手投票");
    printf("按'2'为2号选手投票，以此类推，以按'0'作为投票结束标记\n");
    printf("投票现在正式开始:\n");
    while(1)   //为选手投票
    {
         scanf("%d",&n);
         getchar();
         if(n==0)  //当投票为0，投票随即结束
            break;
          while(n<1||n>numbers)  //若某一位投票数小于1或大于选手总数视为投票失败，要重新输入投票数
            {
                printf("不存在此号码，请重新输入:");
                scanf("%d",&n);
            }
            p[n]->sum ++;  //将每一位选手的投票数计数
        }
    printf("投票完成!\n");
}
void shellinsert(mjl *R,int n,int dk)//希尔排序
{
    int i,j;
    for(i=dk+1;i<=n;i++)
    {
        if(R[i]->sum >R[i-dk]->sum )
        {    //小于时，需R[i]将插入有序表
            *R[0] =*R[i]; //存储待插入的记录
            for(j=i-dk;j>0&&R[j]->sum <R[0]->sum ;j=j-dk)
            *R[j+dk]=*R[j]; //记录后移
            *R[j+dk]=*R[0]; //插入到正确位置
        }
    }
}
void shellsort(mjl *R,int n)
{
	int nn;
    int i;
	int mm=1;
    int t[10]={21,19,17,13,11,7,5,3,2,1}; 
//步长因子中除1外没有公因子，且最后一个步长因子必须为1，第一趟排序间隔为21
    nn=numbers;
    for(i=0;i<10;i++)
        shellinsert(R,n,t[i]);//调用每个步长因子
    printf("最终排名如下:\n");
    printf("名次\t编号\t姓名\t票数\n");
    for(i=1;i<=numbers;i++)  //for循环输出显示最后结果
    {
        if(i>=2&&p[i]->sum<p[i-1]->sum )
        mm++;     printf("%d\t%d\t%s\t%d\n",mm,p[i]->number ,p[i]->name ,p[i]->sum );
    }
	if(nn<=1)
	{
		printf("冠军是%d号%s\n",p[1]->number ,p[1]->name);
	
	}
	 if(nn>1&&nn<3)
	{
		printf("冠军是%d号%s\n",p[1]->number ,p[1]->name);
		printf("亚军是%d号%s\n",p[2]->number ,p[2]->name);
	 }
	else if(nn>=3)
	{
		printf("冠军是%d号%s\n",p[1]->number ,p[1]->name);
		printf("亚军是%d号%s\n",p[2]->number ,p[2]->name);
		printf("季军是%d号%s\n",p[3]->number ,p[3]->name);
	}
}
void main()  //主函数
{
    int n=1;
	system("color f5");  
    do
    {
		printf("\n");
	 	printf(" *************************************************************************\n");
    printf(" ********************欢迎来到电视大赛观众投票及排名系
统*******************");
   	printf("\n");
    printf(" |                    ★★★  1: 输入选手信息   ★★★                    |\n");
    printf(" |                    ★★★  2: 投票           ★★★                    |\n");
	  printf(" |                    ★★★  3: 排序及结果     ★★★                    |\n");
	  printf(" |                    ★★★  4: 退出           ★★★                    |\n");
		 printf("\n");
	printf(" *****************************************************************   ********\n");
	    printf("\n请选择(0-3):☆☆☆");
        scanf("%d",&n);
        getchar();
        if(n<1||n>4)   //若输入超过总操作数4或小于1则要重新输入
        {
            printf("输入有误，请重新输入:");
            scanf("%d",&n);
            getchar();
        }
        switch(n)//多分支结构，实现操作数对应函数执行，n-48保证与操作数数据类型一致
        {
            case 1: shuru();
				break;
            case 2: toupiao();
				break;
            case 3: shellsort(p,numbers);
				break;
            case 4: printf("谢谢使用，再见!");
				break;
        }
    }while(n!=4);//判断结束         
}
