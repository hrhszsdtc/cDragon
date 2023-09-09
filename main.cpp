// (C) 2022-2023 hrhszsdtc By ZehangZhuStudio 
// std=ISOC++11,coding:UTF-8
#include <iostream>
#include <string>
#include "lib_Format.cpp"
#include "lib_SQLite.cpp"

using namespace std;

/* 用于调试时使用，当为1时，是调试模式 */
#define DEBUG 1
void Debug(string info){
	if(DEBUG==1)
		cout<<info<<endl;
}
void iDebug(string ValName,long int Val){
	if(DEBUG==1)
		cout<<"DEBUG- "<<ValName<<":"<<Val<<endl;
}
void dDebug(string ValName,long double Val){
	if(DEBUG==1)
		cout<<"DEBUG- "<<ValName<<":"<<Val<<endl;
}
void sDebug(string ValName,string Val){
	if(DEBUG==1)
		cout<<"DEBUG- "<<ValName<<":"<<Val<<endl;
}
/* 主函数 */
int main(int argc,char* argv[]){
	iDebug("argc",argc);
	sDebug("argv",argv[0]);
	return 0;
}