// (C) 2022-2023 hrhszsdtc By ZehangZhuStudio 
// std=ISOC++11,coding:UTF-8
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// 程序版本
#define CDRAGON_INFORMATION "cDragon -Level0 Compiler V1.0.0 Alpha"
/* 用于调试时使用，当为1时，是调试模式 */
#define DEBUG 1

/* 用于显示程序运行时间 */
const time_t BegTime = time(NULL);

#ifdef _WIN32

#elif __linux__

#elif __APPLE__

#endif


/* 调试输出 */
template<class T>
void Debug(int line,T info){
	time_t Time = time(NULL);
	if(DEBUG == 1)
		cout<<'['<<Time<<"] Line:"<<line<<':'<<info<<endl;
}

// 使用帮助文档
void HelpDoc(void);
//日志
class Logging{
	
};

//进度条===================================================================
class ProgressBar{
	private:
		//进度条长度
		unsigned int BarLenth;
		
		//未完成进度填充符号
		char UndoBar_Filling;
		
		//完成进度填充符号
		char DoBar_Filling;
		
		//显示标记
		bool ShowFlag = false;
		
	public:
		//初始化
		void Install();
		//显示进度条
		void Show();
		
		//设置进度条长度
		void Set_BarLenth(unsigned int);
		//设置未完成进度填充符号
		void Set_UndoBar(char);
		//设置完成进度填充符号
		void Set_DoBar(char);
		//设置完成进度
		void Set(double);
		
};

void  ProgressBar::Install(){
	//初始化数据
	BarLenth = 25;
	UndoBar_Filling = '-';
	DoBar_Filling = '=';
}

void ProgressBar::Set_BarLenth(unsigned int lenth){
	BarLenth = lenth;
}

void ProgressBar::Set_UndoBar(char mark){
	UndoBar_Filling = mark;
}

void ProgressBar::Set_DoBar(char mark){
	DoBar_Filling = mark;
}

void ProgressBar::Show(){
	cout<<'|';
	int i = 0;
	for(i=0;i<BarLenth;i++)
		cout<<UndoBar_Filling;
	cout<<"| 0%";
}

void ProgressBar::Set(double persent){
    //清除上一行
	int j = BarLenth+6,k=0;	// 清除光标位置到行尾的内容
	for(k=0;k<j;k++)
		cout<<'\b';
	
	//计算并重新打印
	int Do,Undo,temp;
	
	temp = (persent/100) * BarLenth;
	Do = temp-(temp%1);
	
	Undo = BarLenth - Do;
	
	//打印
	int i=0;
	cout<<'|';
	for(temp=0;i<Do;i++)
		cout<<DoBar_Filling;
	for(temp=0;i<BarLenth;i++)
		cout<<UndoBar_Filling;
	cout<<'|'<<persent<<'%';
	
	if(persent >= 100)
		cout<<endl;
}

void ProgressBar_Test(){
/*
	ProgressBar *bar = new ProgressBar;
	bar -> Install();
	bar -> Show();
	Sleep(1000);
	bar -> Set(10);
	Sleep(1000);
	bar -> Set(25);
	Sleep(1000);
	bar -> Set(50);
	Sleep(1000);
	bar -> Set(75);
	Sleep(1000);
	bar -> Set(100);*/
}
// Class ProgressBar END============================================================

class Level0{
	private:
		string flag;
	public:
		string Warn;
		
		//用于解释语言
		string Explain(string sentence,int line){
			string filename,temp1,temp2;	//对照文件位置
			int i,j;	//迭代计数
			fstream file;	//对照文件
			
			// 获得函数名
			i = 0;	//初始化
			j = sentence.length() -1;	//初始化
			
			//迭代
			while(1){
				temp2 = sentence[i];
				if(i = '(')
					break;
				else
					temp1 += temp2;
			}
			Debug(__LINE__,temp1);
			filename = "./data/Level0/" + temp1;
			file.open(filename,ios::in);
			if(!file.is_open()){
				Warn += "[Error] Line:";
				Warn += line;
				Warn += " ";
				Warn += sentence;
				Warn += " -未定义";
				Warn += temp1;
				Warn += '\n';
				Debug(__LINE__,filename);
		}
		
		return temp2;
	}
};

class Explainer{
    private:
        int color;
    public:
        void Install();
        void Set_color();
};
void Explainer::Install(){
    cout<<"";
}

/* 主函数 */
int main(int argc,char* argv[]){
	
	/* 返回异常 */
	if (argc == 1){
        Explainer Obj;
        Obj.Install();
    }
	Debug(__LINE__,argc);
	Debug(__LINE__,argv[0]);
	ProgressBar_Test();
	//正常运行
	fstream iFile;	//文件对象
	string sFileName;	//文件位置
	
	//获得文件位置
	sFileName = argv[1];
	
	//打开文件
	iFile.open(sFileName,ios::in);
	
	//检查文件是否打开
	if(! iFile.is_open()){
		cout<<"指定文件"<<sFileName<<"不存在!"<<endl;
		Debug(__LINE__,"return 2");
		return 2;
	}
	
	/* 翻译 */
	Level0 L0;
	L0.Explain("nihao()",1);
	system("pause");
	return 0;
}

void HelpDoc(){
	cout<<CDRAGON_INFORMATION<<endl
		<<"参数错误!"<<endl
		<<"使用方法： cDragon_L1.exe [要编译的文件]"<<endl;
}
