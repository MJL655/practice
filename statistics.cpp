
#include <iostream>
#include <fstream>
#pragma warning(disable:4786)     
#include <string>  
#include <map>  
using namespace std;
struct name{
	char name1[20];
	int num3[130];
};

int main() {
	int k=0;
	struct name na;
	for(k=1;k<=120;k++)
	{
		int i=0,counter = 0,sum=0;
		float pinlv;
		ifstream readfile;
		char filename[100] = {'\0'};  
		sprintf(filename, "C:\\MyDownloads\\Download\\Art_split\\120章节\\%04d.txt", k);
		char text[60]="宝玉",ch;
		readfile.open(filename);
		if(readfile.is_open == false) {
			cout << "没有找到文件:" << filename << endl;
			return 1;
		}
		while(readfile >> ch) {
			//  sum++;
			if(ch == text[i]) {
				for(++i; text[i] && (readfile >> ch); ++i)
					if(text[i] != ch) break;
					if(text[i] == '\0') ++counter;
					if(ch == text[0]) i = 1;
					else i = 0;
			}
		}
		cout << counter;
		string s="";
		ifstream infile(filename);  
		map<string,int>wordcount;  
		unsigned char temp[2];  
		while(true)//国标2312  
		{  
			infile>>temp[0];  
			if(infile.eof()) break;  
			if (temp[0]>=0xB0)//GB2312下的汉字，最小是0XB0  
			{ 
				infile>>temp[1];  
				sum++;
			}  
			
		}  
		cout<<" "<<sum<<"  "<<(float)counter/(float)sum<<endl;
	}
    return 0;
}
