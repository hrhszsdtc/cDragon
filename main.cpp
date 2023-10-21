// (C) 2022-2023 hrhszsdtc By ZehangZhuStudio
// std=ISOC++11,coding:GBK
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "cDragon.h"

#define CONS_NEWLINE cout<<endl;

using namespace std;

bool SET_EXPLAIN = false;	//解释代码?
bool SET_COMPILE = false;	//编译代码?
bool SET_OUTPUT = false;	//程序显示详细信息
bool SET_DONNOT_CHECK = false;	//不检查代码
string SET_DUMPFILE_ROOT = "./";//缓存文件存放目录
string SET_OFILE_NAME = "";		//生成文件名称
string OBJ_FILE = "";		//处理对象 

void Analysis(int,char**);

/* 主函数 */
int main(int argc,char* argv[]) {
	ThanksDoc(); 
	
	ProgressBar_Test();
	CONS_NEWLINE;
	
	/* 返回异常 */
	if (argc == 1) {
		ZZHLogo();
		HelpDoc();
		system("pause");
		return 0;
	}
	// 解析命令 
	else{
		if(argv[2] == "set"){
			//TODO
		}
		
		if(argv[2] == "help"){
			HelpDoc();
			
		}
		int i;
		string p;
		OBJ_FILE = argv[2];
		for(i=2;i<(argc-1);i++){
			p = argv[i];
			if(p == "-e")
				SET_EXPLAIN = true;
			
			if(p == "-c")
				SET_COMPILE = true;
				
			if(p == "-nc")
				SET_DONNOT_CHECK = true;
		}
	}
	

	//打印信息
	Logo();
	cout<<"(C) 2022-2023 hrhszsdtc.ZehangZhuStudio By ZZH"<<endl;
	int i;
	for(i=0; i<63; i++)
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
	if(! iFile.is_open()) {
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

	head = "#include<stdio.h>\nusing namespace std;\nint main(int argc,char* argv[]){";
	oFile<<head<<endl;
	while(!iFile.eof()) {
		iFile>>tempL;
		oFile<<L0.Explain(tempL,f)<<endl;;
	}
	oFile<<"return 0;\n}"<<endl;
	system("pause");
	return 0;
}

