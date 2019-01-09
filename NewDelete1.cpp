#include <iostream>
using namespace std;

class cA{
	int m_i;
public:
	cA(int x=0):m_i(x){
		cout<<"cA Cons"<<endl; 
	}
	~cA(){
		cout<<"cA Des"<<endl;
	}
};

/*
static void* operator new(size_t size){
	cout<<"static void* operator new(size_t size)"<<endl;
	return malloc(size);
}
*/

/*
void* ::operator new (size_t size){
	void* temp = malloc(size);
	if(temp)
		return temp;
	throw bad_alloc();
}

void* ::operator new (size_t size, Nothrow& nt){
	void* temp = malloc(size);
	return temp;	
}

void* operator new (size_t size, void* p){ // Placement new
 return p;
}

void operator delete(void* vp){
	free(vp);
}

void* operator new [] (size_t size){
}
*/

void main(){
	cA *ap = new cA[4];
	/*
		push 4 * sizeof(cA) // size
		cA* temp = (cA*) call operator new [] 

		temp[0].cA()
		temp[1].cA()
		temp[2].cA()
		temp[3].cA()
	*/
	cout<<"--------------"<<endl;
	//delete ap;
	/*
		ap->~cA();
		operator delete(ap); // free(ap)
	*/
	delete [] ap;
	/*
	 * deallocating the memory 
		ap[3]->~cA();
		ap[2]->~cA();
		ap[1]->~cA();
		ap[0]->~cA();
		operator delete [] (ap); // free(ap)
	*/
}



void main6(){
	char chunk[100];

	// used chunk
	cA *ap = new(chunk) cA();  // Placement new
	//creating the dynamic memory
	cA *ap1 = new(chunk + sizeof(cA) ) cA();  // Placement new
	cA *ap2 = new(chunk + 2 * sizeof(cA) ) cA();  // Placement new
	cA *ap3 = new(chunk  + 3 *sizeof(cA) ) cA();  // Placement new

	ap3->~cA();
	ap2->~cA();
	ap1->~cA();
	ap->~cA();
}









struct Dummy {}dummy;

void* operator new(size_t size, Dummy& d){
	cout<<"void* operator new(size_t size, Dummy& d)"<<endl;
	return malloc(size);
}

void main4(){
	cA *ap = new(dummy) cA();
}



void main3(){
	cA *ap = new(nothrow) cA();

	if(NULL == ap){
		cout<<"Low mmeory"<<endl;
	}
	// use ap object
	delete ap;
}

void main2(){
	cA *ap ;
	
	try {
		ap = new cA(10);
	}catch(bad_alloc& ba){
		cout<<"Low mem"<<endl;
	}
	/*
		push sizeof(cA) // size
		void* tp = call ::operator new(size_t)

		push 0 // x
		push (cA*) tp // this
		call cA::cA(int)

		ap = (cA*) tp
	*/

	cout<<" ------------------"<<endl;

	delete ap;
	/*
	ap->~cA();
	::operator delete(ap)
	*/
}
