#include <iostream>
using namespace std;

struct Complex{
private:
	int real, imag;
	friend Complex& operator +(int lhs, Complex& rhs);
public:
	Complex(int x=0, int y=0): real(x), imag(y){}
	~Complex() { cout<<"Real: "<< real <<", imag: "<< imag <<endl;}	
	Complex&  operator + (int rhs) ;
	friend ostream& operator << (ostream& os, Complex& rhs){
		os << rhs.real <<" +i "<< rhs.imag<<endl;
		return os;
	}
};

Complex&  Complex::operator + (int rhs) {
		cout<<"Complex&  Complex::operator + (int rhs)"<<endl;
		imag += rhs;
		return *this; // Complex * const this
}

Complex& operator +(int lhs, Complex& rhs){
		cout<<"friend Complex& operator +(int lhs, Complex& rhs)"<<endl;
		rhs.real += lhs;
		return rhs;
}

void main(){
	Complex obj(10, 20);

	//obj + 5 + 3;
	//obj.operator+(5).operator+(3);

	cout<<"-------------------"<<endl;
	4 + obj;
	cout<<"-------------------"<<endl;

	cout << obj;
	cout<<"-------------------"<<endl;

}
