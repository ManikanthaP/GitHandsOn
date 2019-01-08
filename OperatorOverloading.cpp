#include <iostream>
using namespace std;

struct Complex{
private:
	int real, imag;
public:
	void setReal(int val) { real = val; }
	int getReal() { return real; }
	int getImag() { return imag; }
	void setImag(int val) { imag = val; }
	Complex(int x=0, int y=0): real(x), imag(y){}
	~Complex() { cout<<"Real: "<< real <<", imag: "<< imag <<endl;}	
};

Complex&  operator + (Complex& lhs, int rhs){
	cout<<"void operator + (Complex& lhs, int rhs): rhs= "<< rhs <<endl;

	lhs.setImag( lhs.getImag() + rhs);
	return lhs;
}

Complex& operator + (int lhs, Complex& rhs){
	cout<<"void operator + (int lhs, Complex& rhs)"<<endl;
	rhs.setReal( rhs.getReal() + lhs);
	return rhs;
}

void main(){
	Complex obj(10, 20);

//	obj + 5;
	//operator+(obj, 5);
	/*
		push 5 // rhs
		push &obj // lhs
		call ::operator+(Complex&, int)
	*/

	cout<<"-------------------"<<endl;

	//4 + obj;
	
	//obj + 5 + 3;
	// ( operator+(obj, 5))  => obj
	// obj + 3

	operator+(operator+(obj, 5), 3);
	cout<<"-------------------"<<endl;

}
