#include <iostream>
#include <cstring>
using namespace std;

class String{
	char* m_p;
public:
	String() : m_p(NULL) {}
	String(char* p) : m_p( new char[strlen(p) + 1]) {
		strcpy(m_p, p);
	}
	String(String& sr) :m_p(sr.m_p){}
	~String() {
		if(m_p) {
			cout<<" Delete string is: "<< m_p<<endl;
			delete [] m_p;
		}
		else
			cout<<" --- empty string ---"<<endl;
	}
};

void main(){
	String myStr1;
	String str2 = "Hello ";
	String str3 = str2;



	cout<<"----------------"<<endl;
}