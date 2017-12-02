#include <iostream>
#include "rcMatrix.h"

using namespace std;

int main()
{
	try
	{
		cout << endl;
		/*
		CMatrix A1(2,4,1.0);
		//0 					matrix A1 2X5
		//1	 [	1.0  0.0  0.0  0.0
		//2			0.0  1.0  0.0  0.0  ]
		cout <<"A1: \n"<< A1 << endl<< endl;

		CMatrix A2(4,3,0.0,6);
		//0			matrix A2 5X3
		//1		[	0  6  6
		//2			6  0  6
		//3			6  6  0
		//4			6  6  6  ]
		cout <<"A2: \n"<< A2 << endl << endl;
		*/

		CMatrix A1(2,5,1.0);
		//Create matrix A1 = [	1.0  0.0  0.0  0.0  0.0
		//			0.0  1.0  0.0  0.0  0.0  ]
		cout << "A1: \n"<< A1 << endl<< endl;

		CMatrix A2(5,3,0.0,6.3);
		//Create matrix A1 = [	0.0  6.3  6.3
		//			6.3  0.0  6.3
		//			6.3  6.3  0.0
		//			6.3  6.3  6.3
		//			6.3  6.3  6.3  ]
		cout <<"A2: \n"<< A2 << endl<< endl;

		CMatrix S = A1 * A2;
		cout <<"Matrix S:"<<endl<< S << endl << endl;

		fstream f1;
		f1.open("matrix.dat", fstream::in);
		CMatrix B(f1);
		f1.close();
		cout <<"File Matrix:\n"<< B << endl << endl;

		S = B;						//Assign B to S
		S[0][0] = 1.4;					//Modify S
		cout << "S[0][0]=" << S[0][0] <<endl;		//Verify S
		cout << "B[0][0]=" << B[0][0] <<endl;		//Verify B
	}
	catch(IndexOutOfRange&)
	{
		cout << "Index Out of Range" << endl;
	}
	catch(WrongDim&)
	{
		cout << "Wrong Matrix Dimensions" << endl;
	}
	catch(bad_alloc)
	{
		cout << "Out of Memory" << endl;
	}
};
