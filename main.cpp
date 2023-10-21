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

bool SET_EXPLAIN = false;	//���ʹ���?
bool SET_COMPILE = false;	//�������?
bool SET_OUTPUT = false;	//������ʾ��ϸ��Ϣ
bool SET_DONNOT_CHECK = false;	//��������
string SET_DUMPFILE_ROOT = "./";//�����ļ����Ŀ¼
string SET_OFILE_NAME = "";		//�����ļ�����
string OBJ_FILE = "";		//������� 

void Analysis(int,char**);

/* ������ */
int main(int argc,char* argv[]) {
	ThanksDoc(); 
	
	ProgressBar_Test();
	CONS_NEWLINE;
	
	/* �����쳣 */
	if (argc == 1) {
		ZZHLogo();
		HelpDoc();
		system("pause");
		return 0;
	}
	// �������� 
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
	

	//��ӡ��Ϣ
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

	//��������
	fstream iFile,oFile;	//�ļ�����
	string sFileName;	//�ļ�λ��

	//����ļ�λ��
	sFileName = argv[1];

	//���ļ�
	iFile.open(sFileName,ios::in);


	//����ļ��Ƿ��
	if(! iFile.is_open()) {
		cout<<"ָ���ļ�"<<sFileName<<"������!"<<endl;
		Debug(__LINE__,"return 2");
		return 2;
	}

	sFileName += ".cpp";
	oFile.open(sFileName,ios::app);

	/* ���� */
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

