#ifndef STDEXCPTION_H
#define STDEXCPTION
using namespace std;

namespace Excp {
//	编译时异常 
	class eCompiler {
		public:
			eCompiler(string str,long line) {
				cout<<"[行:"<<line<<"] "<<str<<endl;
			}
	};

//	符号不匹配异常 
	class eDo_Not_Match_Mark {
		public:
			eDo_Not_Match_Mark(long line) {
				cout<<"[行:"<<line<<"] "<<"括号或符号无法配对"<<endl;
			}
	};
	
//	未定义异常 
	class eUndefine {
		public:
			eUndefine(string str,long line) {
				cout<<"[行:"<<line<<"] "<<str<<"未定义"<<endl;
			}
	};
}

#endif
