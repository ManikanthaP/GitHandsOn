#include <iostream>
// File Name : Matrix2.cpp

using namespace std;

#define ROW 3
#define COL 4

class Matrix{
	int arr[ROW][COL];
public:
	Matrix(){
		for(int i=0; i<ROW; i++)
			for(int j=0; j<COL; j++)
				arr[i][j] = i * COL + j;
	}
	// Kundan
	class Helper{
		Matrix* m_p;
		int rowInd;
	public:
		Helper(Matrix *p, int ri) : m_p(p), rowInd(ri){}
		int& operator [] (int cIndex){
			//cout<<"int Helper::operator [] (int cIndex): cIndex= "<< cIndex <<endl;
			//return 0; 
			return m_p->arr[rowInd][cIndex];
		}
	};
	Helper operator [] (int rIndex) {
		//cout<<"Matrix& Matrix::operator [] (int rIndex): rIndex= "<< rIndex <<endl;
		return Helper(this, rIndex);
	}
	~Matrix(){
		for(int i=0; i<ROW; i++)
			for(int j=0; j<COL; j++)
				cout<<"arr["<< i <<"]["<< j <<"] = " << arr[i][j]<<endl;
	}
	Matrix& operator + (Matrix& rhs){
		cout<<"Matrix operator + (Matrix& rhs)"<<endl;
		// logic
		return *this;
	}
};

void main(){
	Matrix obj;

//	int val = obj[1][2]; // Read-only
	cout<<"val = "<< val <<endl;	
	cout<<"----------------"<<endl;

	obj[2][2] = 60; // Write-only
		
	cout<<"----------------"<<endl;
	
	obj[0][2] = obj[1][1]; // Read-Write

	cout<<"----------------"<<endl;
}