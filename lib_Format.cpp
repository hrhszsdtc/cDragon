// (C) 2022-2023 hrhszsdtc By ZehangZhuStudio 
// std=ISOC++11,coding:UTF-8
#include <iostream>
#include <string>

using namespace std;

string Format(string str){
	/* 初始化变量 */
	int i,j;
	string temp1,temp2;
	
	/* 变量赋值 */
	j = str.length() - 1;
	
	/* 格式化字符串 */
	for(i=0;i<j;i++){
		temp1 = str[i];
		if(temp1 == "\"")
			temp2 += "\\\"";
		else if(temp1 == "\'")
			temp2 += "\\\'";
		else if(temp1 == "\\")
			temp2 += "\\";
		else
			temp2 += temp1;
	}
	/* 返回格式化的字符串 */
	return temp2;
}