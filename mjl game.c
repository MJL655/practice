#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAXIMUS 15 //�������̴�С

int p[MAXIMUS][MAXIMUS];//�洢�Ծ���Ϣ
char buff[MAXIMUS*2+1][MAXIMUS*4+3];//���������
int Cx,Cy;//��ǰ���λ��  �Լ�ģ����
int Now;//��ǰ���ӵ���ң�1�����ڣ�2������
int wl,wp;//��ǰд�뻺����������������λ��
char* showText;//������������ʾ��������Ϣ
int count;//�غ���


void menu()
{
	printf("\n");
	printf("               ��---���ã���ӭ�������������磡---��\n\n"); 
	printf("           --------------------------------------------\n");
	printf("           �֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n");
    printf("           && * -------- ��  1.������Ϸ ��-------- * &&\n"
		   "           && * -------- ��  2.��Ϸ˵�� ��-------- * &&\n"
	       "           && * -------- ��  3.�˳�     ��-------- * &&\n");
	printf("           �֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n");
	printf("           --------------------------------------------\n\n");
	printf("����1-3��ѡ���Իس���������\n\n");
}
void menu2()
{
	
	system("cls");
	printf("\n\n\n");
	printf("       ������������������������\n");
	printf("       ��                                          ��\n");
    printf("       ��              ллʹ�ã��ټ���            ��\n");
	printf("       ��                                          ��\n");
	printf("       ������������������������\n\n\n");
}
void menu3()
{

	printf("\n\n\n");
	printf("       ������������������������\n");
	printf("       ��                                          ��\n");
    printf("       ��              1������һ��                 ��\n");
	printf("       ��              2���˳�                     ��\n");
	printf("       ������������������������\n\n\n");
	
		
}
void Introduce()
{
	printf("\n");
	printf("                       ��  ��Ϸ˵�� ��           \n\n");
	printf("  ����Ϸ���򣺡�\n\n");
	printf("        �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n");
	printf("      �� ������ר������Ϊ 15��15,�������ݺ��ʮ������ ��\n");	
	printf("      �� ���봹ֱ���� ��ƽ���߹���,��225������� ���� ��\n");
	printf("      �� ����һ��Ϊ'��Ԫ ���ȡ��׺�,����Ԫ(h8)��ʼ    ��\n");
	printf("      �� �໥˳�����ӡ��ڷ��ĵ�һ������Ӧ������Ԫ��,  ��\n");
	printf("      �� �׷���һ������ֻ����������ԪΪ�����ڽ��İ�   ��\n");
	printf("      �� ������,�ڷ��ڶ�������ֻ����������ԪΪ������  ��\n");
	printf("      �� ��5��5����,����ڶ������Ӳ�������,���������� ��\n");
	printf("      �� ����λ�� ���������̺��� ���� б���γ�������  ��\n");
	printf("      �� ��ͬɫ������ӵ�һ��Ϊʤ!                    ��\n");
	printf("      ��                                              ��\n");
	printf("      �� ����Ϸ�����У���ҿ����������Ҽ��������ӣ��� ��\n");
	printf("      �� ������ӡ�                                   ��\n");
	printf("       �� �� �� �� �� �� �� �� �� �� �� ��  �� �� �� �� \n");
	printf("  ����ʾ���� \n\n");
	printf("         ��Ϸ�����У��ɰ�Esc���˳���\n");
	getch();
}
char* Copy(char* strDest,const char* strSrc)//�޸Ĺ����ַ������ƺ����������ĩ�˵�\0
{
  char* strDestCopy = strDest;
  while (*strSrc!='\0')
  {
     *strDest++=*strSrc++;
  }
  return strDestCopy;
}
void Initialize()//��ʼ��һ���Ծֺ���
{
  int i,j;//ѭ������
  showText="";//������ʾ��Ϣ
  count=0;//�غ�������
  for(i=0;i<MAXIMUS;i++)//���öԾ�����
  {
     for(j=0;j<MAXIMUS;j++)
	 {
         p[i][j]=0;
	 }
  }
  Cx=Cy=MAXIMUS/2;//���ù�굽����
  Now=1;//���õ�ǰΪ�ڷ�
} 
char* getStyle(int i,int j)//���������ָ�����꽻��λ�õ��ַ���ͨ���Ʊ���ƴ������
{
   if(p[i][j]==1)//1Ϊ����
     return "��";
   else if(p[i][j]==2)//2Ϊ����
     return "��";
   else if(i==0&&j==0)//����Ϊ��Ե������ʽ
     return "��";
   else if(i==MAXIMUS-1&&j==0)
     return "��";
   else if(i==MAXIMUS-1&&j==MAXIMUS-1)
     return "��";
   else if(i==0&&j==MAXIMUS-1)
     return "��";
   else if(i==0)
     return "��";
   else if(i==MAXIMUS-1)
     return "��";
   else if(j==0)
     return "��";
   else if(j==MAXIMUS-1)
     return "��";
   return "��";//�м�Ŀ�λ
}
char* getCurse(int i,int j)
{
	//���ָ�����꽻��λ�����ϸ����ʽ��ͨ���Ʊ�����ģ�������ʾ
    if(i==Cx)
	{
       if(j==Cy)
          return "��";
       else if (j==Cy+1)
          return "��";
	}
    else if(i==Cx+1)
	{
       if(j==Cy)
          return "��";
       else if (j==Cy+1)
          return "��";
	}
    return "��";//������ڹ�긽����Ϊ��
}
void write(char* c)//�򻺳���д���ַ���
{
	Copy(buff[wl]+wp,c);
    wp+=strlen(c);
}
void ln()//������д��λ������
{
	wl+=1;
    wp=0;
}
void Display()//�������������������Ļ
{
	int i,l=strlen(showText);//ѭ���������м�������Ϣ�ĳ���
    int Offset=MAXIMUS*2+2-l/2;//����м�������Ϣ������ʾ���ڵĺ�����λ��
    if(Offset%2==1)//���λ��Ϊ���������ƶ���ż�����������
	{
        Offset--;
	}
    Copy(buff[MAXIMUS]+Offset,showText);//���м�������Ϣ���Ƶ�������
    if(l%2==1)//����м����ֳ���Ϊ������������Ͽո񣬱������
	{
        *(buff[MAXIMUS]+Offset+l)=0x20;
	}
    system("cls");//������Ļ��׼��д��
    for(i=0;i<MAXIMUS*2+1;i++){//ѭ��д��ÿһ��
        printf("%s",buff[i]);
    if(i<MAXIMUS*2)//д����ÿһ����Ҫ����
        printf("\n");
	}
}
void Print()//������������������浽��������Ȼ�����Display������ʾ����
{
	int i,j;//ѭ������
    wl=0;
    wp=0;
    for(j=0;j<=MAXIMUS;j++)//д����������Ͻǵ��ַ�����Ϊ��Ҫ��ӡ�������½ǣ����Ժ��Ժ��ݸ���һ��ѭ��
	{
        for(i=0;i<=MAXIMUS;i++)
		{
              write(getCurse(i,j));//д�����Ͻ��ַ�
              if(j==0||j==MAXIMUS)//������������̱�Ե��û�����ӵ����ߣ��ÿո����λ��
			  {
                   if(i!=MAXIMUS)
                       write("��");
			  }
              else//����������м��������߳н�����
			  {
                   if(i==0||i==MAXIMUS-1)//���ұ�Ե�����߸���
                       write("��");
                   else if(i!=MAXIMUS)//�м������
                       write("��");
			  }
		}
        if(j==MAXIMUS)//��������һ��ѭ������ֻ��Ҫ�����߲��ַ�������Ҫ��һ��
		{
             break;
		}
        ln();//���п�ʼ��ӡ��������
		write("��");//�ÿ�λ����λ��
        for(i=0;i<MAXIMUS;i++)//��������ѭ�������Ĵ���
		{
             write(getStyle(i,j));//д�뽻���ַ�
             if(i!=MAXIMUS-1)//����������Ҳ��򲹳�һ�����߳н�����
			 {
                  if(j==0||j==MAXIMUS-1)
				  {
                        write("��");//���±�Ե�ĺ��߸���
				  }
                  else
				  {
                        write("��");//�м�ĺ���
				  }
			 }
		 }
         ln();//д��һ�к�����
	}
    Display();//�������������������Ļ
}
int Put()
{
	//�ڵ�ǰ���λ�����ӣ�����ǿգ��򷵻�0��ʾʧ��
	if(p[Cx][Cy]==0)
	{
         p[Cx][Cy]=Now;//�ı��λ������
         return 1;//����1��ʾ�ɹ�
	}
    else
	{
        return 0;
	}
}
int Check()//ʤ����飬���жϵ�ǰ����λ����û���������������
{
	int w=1,x=1,y=1,z=1,i;//�ۼƺ�����б��а�ĸ������������ͬ������Ŀ
    for(i=1;i<5;i++)
		if(Cy+i<MAXIMUS&&p[Cx][Cy+i]==Now)
			w++;
		else break;//���¼��
    for(i=1;i<5;i++)
		if(Cy-i>0&&p[Cx][Cy-i]==Now)
		w++;
		else break;//���ϼ��
    if(w>=5)
		return Now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
    for(i=1;i<5;i++)
		if(Cx+i<MAXIMUS&&p[Cx+i][Cy]==Now)
			x++;
		else break;//���Ҽ��
    for(i=1;i<5;i++)
		if(Cx-i>0&&p[Cx-i][Cy]==Now)
			x++;
		else break;//������
    if(x>=5)
		return Now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
    for(i=1;i<5;i++)
		if(Cx+i<MAXIMUS&&Cy+i<MAXIMUS&&p[Cx+i][Cy+i]==Now)
			y++;
		else break;//�����¼��
    for(i=1;i<5;i++)
		if(Cx-i>0&&Cy-i>0&&p[Cx-i][Cy-i]==Now)
			y++;
		else break;//�����ϼ��
    if(y>=5)
		return Now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
    for(i=1;i<5;i++)
		if(Cx+i<MAXIMUS&&Cy-i>0&&p[Cx+i][Cy-i]==Now)
			z++;
		else break;//�����ϼ��
    for(i=1;i<5;i++)
		if(Cx-i>0&&Cy+i<MAXIMUS&&p[Cx-i][Cy+i]==Now)
			z++;
		else break;//�����¼��
    if(z>=5)
		return Now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
    return 0;//��û�м�鵽�����飬�򷵻�0��ʾ��û����Ҵ��ʤ��
}
int RunGame()//���������Ծ֣�����Ӯ����Ϣ
{
	int input;//�������
    int victor;//Ӯ����Ϣ
    Initialize();//��ʼ���Ծ�
    while(1)
	{//��ʼ���޻غϵ���ѭ����ֱ������ʤ������
    Print();//��ӡ����
    input=getch();//�ȴ����̰���һ���ַ�
    if(input==27)//�����ESC���˳�����
	{
		menu2();
		getch();
        exit(0);
	}
    else if(input==0x20)//����ǿո���ʼ���� 0x20�ǿո�
	{
        if(Put())//������ӳɹ����ж�ʤ��
		{
             victor=Check();
             Now=3-Now;//�ֻ���ǰ�������
             count++;
             if(victor==1)//����ڷ��ﵽʤ������ʾ��ʾ���ֲ��ȴ�һ�ΰ���������ʤ����Ϣ
			 {
                   showText="�ڷ������ʤ����";
                   Print(); 
                   if(getch()==0xE0)
				   {
                       getch();
				   }
                   return Now;
			 }
             else if(victor==2)//����׷��ﵽʤ������ʾ��ʾ���ֲ��ȴ�һ�ΰ���������ʤ����Ϣ
			 {
                   showText="�׷������ʤ����";
                   Display();
                   if(getch()==0xE0)
				   {
                       getch();
				   }
                   return Now;
			 }
			 else if(count==MAXIMUS*MAXIMUS)//����غ����ﵽ�����������������̳�������Ϊƽ��
			 {
                   showText="ƽ�֣�";
                   Display();
                   if(getch()==0xE0)
				   {
                        getch();
				   }
                   return 0;
			 }
		}
	}
    else if(input==0xE0)//������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
	{
         input=getch();//��õڶ���������Ϣ
         switch(input)//�жϷ���������ƶ����λ��
		 {
              case 0x4B://���
                   Cx--;
                   break;
              case 0x48://�¼�
                   Cy--;
                   break;
              case 0x4D://�Ҽ�
                   Cx++;
                   break;
              case 0x50://�ϼ�
                   Cy++;
                   break;
		 }
         if(Cx<0)
			 Cx=MAXIMUS-1;//������λ��Խ�����ƶ����Բ�
         if(Cy<0)
			 Cy=MAXIMUS-1;
         if(Cx>MAXIMUS-1)
			 Cx=0;
         if(Cy>MAXIMUS-1)
			 Cy=0;
	}
	}
}
void main()//������
{
	char x;
	int a=0;
	system("title ���������� �����ϼ�������");//���ñ���
    system("mode con cols=63 lines=32");//���ô��ڴ�С
    system("color A1");//������ɫ
	printf("\n");
	do
	{
		a++;
		menu();
        printf("����������ѡ��");
		if(a==1)
           scanf("%c",&x);
		else
			scanf("\n%c",&x);
		if(x!='1'&&x!='2'&&x!='3')
		{
			printf("�������!");
			return;
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