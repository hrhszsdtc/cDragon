#ifndef STDEXCPTION_H
#define STDEXCPTION
using namespace std;

namespace Excp {
//	����ʱ�쳣 
	class eCompiler {
		public:
			eCompiler(string str,long line) {
				cout<<"[��:"<<line<<"] "<<str<<endl;
			}
	};

//	���Ų�ƥ���쳣 
	class eDo_Not_Match_Mark {
		public:
			eDo_Not_Match_Mark(long line) {
				cout<<"[��:"<<line<<"] "<<"���Ż�����޷����"<<endl;
			}
	};
	
//	δ�����쳣 
	class eUndefine {
		public:
			eUndefine(string str,long line) {
				cout<<"[��:"<<line<<"] "<<str<<"δ����"<<endl;
			}
	};
}

#endif
