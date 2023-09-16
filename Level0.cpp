// (C) 2022-2023 hrhszsdtc By ZehangZhuStudio 
// std=ISOC++11,coding:UTF-8
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

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
void HelpDoc(void);
class Level0{
	private:
		string flag;
	public:
		string Warn;
		
		//用于解释语言
		bool Explain(string sentence,int line){
			string filename,temp1,temp2;	//对照文件位置
			int i,j;	//迭代计数
			fstream file;	//对照文件
			
			//初始化
			i = 0;
			j = sentence.length -1;
			
			//迭代
			while(1){
				temp2 = sentence[i];
				if(i = '(')
					break;
				temp1 += temp2;
			}
			Debug(__LINE__,temp1);
			filename = "./data/Level0/" + temp1;
			file.open(filename,ios::in);
			if(!file.is_open()){
				Warn += "[Error] Line:" + line + " " +sentence + " -未定义" + temp1 + '\n';
		}
};

/* 主函数 */
int main(int argc,char* argv[]){
	Debug(__LINE__,argc);
	Debug(__LINE__,argv[0]);
	
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
	
	return 0;
}

void HelpDoc(){
	cout<<CDRAGON_INFORMATION<<endl
		<<"参数错误!"<<endl
		<<"使用方法： cDragon_L1.exe [要编译的文件]"<<endl;
}