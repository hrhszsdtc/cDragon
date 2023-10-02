// (C) 2022-2023 hrhszsdtc By ZehangZhuStudio 
// std=ISOC++11,coding:UTF-8
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <vector>

using namespace std;

// 程序版本
#define CDRAGON_INFORMATION "cDragon -Level0 Compiler V1.0.0 Alpha"
/* 用于调试时使用，当为1时，是调试模式 */
#define DEBUG 1

/* 用于显示程序运行时间 */
const time_t BegTime = time(NULL);

/* 调试输出 */
template<class T>
void Debug(int line,T info){
	time_t Time = time(NULL);
	if(DEBUG == 1)
		cout<<'['<<Time<<"] Line:"<<line<<':'<<info<<endl;
}

// 使用帮助文档
void HelpDoc(void){
	cout<<CDRAGON_INFORMATION<<endl
		<<"参数错误!"<<endl
		<<"使用方法： cDragon_L1.exe [要编译的文件] -参数1 -参数2 ... -参数n"<<endl;
}

//打印ZZH
void ZZHLogo(){
	cout<<" ______     _                        _______           \n\
|___  /    | |                      |___  / |          \n\
   / /  ___| |__   __ _ _ __   __ _    / /| |__  _   _ \n\
  / /  / _ \\ '_ \\ / _` | '_ \\ / _` |  / / | '_ \\| | | |\n\
./ /__|  __/ | | | (_| | | | | (_| |./ /__| | | | |_| |\n\
\\_____/\\___|_| |_|\\__,_|_| |_|\\__, |\\_____/_| |_|\\__,_|\n\
                               __/ |                   \n\
                              |___/                    "<<endl;
}

void Logo(){
	cout<<"       _____                              \n\
      |  __ \\                             \n\
   ___| |  | |_ __ __ _  __ _  ___  _ __  \n\
  / __| |  | | '__/ _` |/ _` |/ _ \\| '_ \\ \n\
 | (__| |__| | | | (_| | (_| | (_) | | | |\n\
  \\___|_____/|_|  \\__,_|\\__, |\\___/|_| |_|\n\
                         __/ |            \n\
                        |___/             "<<endl;
}
//日志=====================================================================
class Logging{
	private:
		fstream LogFile;	//文件对象
	public:
		//打开文件对象
		void OpenLogFile(string);
		//记录日志
		void Info(string);
		void Warn(string);
		void Error(string);
		void Log(int,string);
};

void Logging::OpenLogFile(string filename){
	LogFile.open(filename.c_str(),ios::app);
}
void Logging::Info(string str){
	
	//获取时间
	time_t Time = time(NULL);
	
	if(LogFile.is_open()){
		LogFile<<'['<<Time<<"] [Info]"<<str<<endl;
	}
	else
		cout<<"未打开日志文件或日志文件打开异常!"<<endl;
}
void Logging::Warn(string str){
	
	//获取时间
	time_t Time = time(NULL);
	
	if(LogFile.is_open()){
		
	}
	else
		cout<<"未打开日志文件或日志文件打开异常!"<<endl;
}
void Logging::Error(string str){
	
	//获取时间
	time_t Time = time(NULL);
	
	if(LogFile.is_open()){
		
	}
	else
		cout<<"未打开日志文件或日志文件打开异常!"<<endl;
}
void Logging::Log(int Lv,string str){
	
	//获取时间
	time_t Time = time(NULL);
	
	if(LogFile.is_open()){
		
	}
	else
		cout<<"未打开日志文件或日志文件打开异常!"<<endl;
}
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
		
		~ProgressBar();
		
};

ProgressBar::~ProgressBar(){
	int j = BarLenth+6,k=0;	// 清除光标位置到行尾的内容
	for(k=0;k<j;k++){
		cout<<'\b';
	}
	int m = BarLenth+6,n=0;	// 清除光标位置到行尾的内容
	for(n=0;n<m;n++){
		cout<<"  ";
	}
	cout<<endl;
}

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
}

void ProgressBar_Test(){
	ProgressBar *bar = new ProgressBar;
	bar -> Install();
	bar -> Set_BarLenth(50);
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
	bar -> Set(100);
	delete bar;
}
// Class ProgressBar END============================================================

class Level0{
	private:
		string flag;
		bool OK = true;
	public:
		string Warn;
		
		//用于解释语言
		string Explain(string ,int);
};
string Level0::Explain(string sentence, int line) {
    string temp1, temp2, temp3;
    int i, j = 0;

    try {
        i = sentence.find('(');
        Debug(__LINE__, i);

        //没有找到"("
        if (i == -1) {
            throw runtime_error("未找到左括号");
        }

        for (j = 0; j <i; j++)
            temp1 += sentence[j];

        Debug(__LINE__, temp1);
		
		fstream file;
		temp1 = "./data/Level0/" + temp1;
		file.open(temp1,ios::in);
		
		/* 检查文件是否打开 */
		if(!file.is_open()){
			string a = "函数：\"";
			a += temp1;
			a += "\" 未定义!";
			throw runtime_error(a.c_str());
		}
		
		/* 获得参数 */
		for(i = (sentence.find('(')+1);i<(sentence.length()-1);i++)
			temp2 += sentence[i];
		Debug(__LINE__,temp2);
		if(temp1.find("定义_") != -1){
			file>>temp3;
			temp3 += temp2;
		}
		else{
			file>>temp3;
			temp3 +='(';
			temp3 += temp2;
			temp3 += ");";
		}
        return temp3;
    }
    catch (const exception& e) {
        cout << "异常：" <<"[行："<<line<<']'<< e.what() << endl;
		OK = false;
    }
	
    return "";
}

/* 主函数 */
int main(int argc,char* argv[]){
	
	/* 返回异常 */
	if (argc != 2){
		ZZHLogo();
		HelpDoc();
		system("pause");
		return 0;
	}
	/*
	//设置变量
	bool DO_NOT_CHECK_SRC = false;
	
	//解析参数
	int m;
	for(m=0;m<argc;m++)
	*/
	
	//打印信息
	Logo();
	cout<<"(C) 2022-2023 hrhszsdtc.ZehangZhuStudio By ZZH"<<endl;
	int i;
	for(i=0;i<63;i++)
		cout<<'-';
	cout<<endl;
	cout<<CDRAGON_INFORMATION<<endl;
	
	Debug(__LINE__,argc);
	Debug(__LINE__,argv[0]);
	//ProgressBar_Test();
	
	//正常运行
	fstream iFile,oFile;	//文件对象
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
		
	sFileName += ".cpp";
	oFile.open(sFileName,ios::app);
	
	/* 翻译 */
	Level0 L0;
	int f = 1;
	string tempL,head;
	
	head = "#include<iostream>\nusing namespace std;\nint main(int argc,char* argv[]){";
	oFile<<head<<endl;
	while(!iFile.eof()){
		iFile>>tempL;
		oFile<<L0.Explain(tempL,f)<<endl;;
	}
	oFile<<"return 0;\n}"<<endl;
	system("pause");
	return 0;
}
