#include<iostream>

using namespace std;

class matrixClass{
	protected: 
		int numRows; // number of rows 
		int numCols; // number of columns
		int** mat; // 2D dynamic array to store matrix 

	public: 
		matrixClass(); // default constructor
		matrixClass(int r, int c); // non default constructor
		void display(); // display
		void setValue(int i, int j, int val); // to set the value at location i, j
		int getValue(int i, int j); // return val at i, j
		int getNumRows(); // Adi, "Write a function that returns numRows.""		
		int getNumCols(); // getter for numCols
		matrixClass* multiply(matrixClass* multiplier); // multiply method
};

//setValue member function
void matrixClass :: setValue(int i, int j, int val)
{
	mat[i][j] = val;
}

//getValue member function
int matrixClass :: getValue(int i, int j) {
	return mat[i][j];

}

//getNumRows member function
int matrixClass :: getNumRows() {
	return numRows;
}

//getNumCols member function
int matrixClass :: getNumCols() {
	return numCols;
}

//function matrixClass
matrixClass :: matrixClass(int r, int c) {
	numRows = r;
	numCols = c;

	mat = new int* [numRows];

// For each row, create an array of integers
	for (int i = 0; i < numRows; i++) {
		mat[i] = new int[numCols];

// Set all values to 0.
		for (int j = 0; j < numCols; j++) {
			mat[i][j] = 0;
		}
	}

}

//display member function
void matrixClass :: display() {
	for (int row = 0; row < numRows ; row++)
		{for (int col = 0; col < numCols; col++)
		    {cout << mat[row][col] << " ";
		}
             cout << "\n";

	}

}

// multiply member function
matrixClass* matrixClass :: multiply(matrixClass* multiplier)
{matrixClass* Result = new matrixClass(numRows, multiplier->getNumCols());
int i, j, k;
    for (i = 0; i < numRows; i++){
        for (j = 0; j < numCols; j++){
            for (k = 0; k < numCols; k++)
                {int number = Result->getValue(i,j);
                    number += getValue(i,k) * multiplier->getValue(k,j);   
                        Result->setValue(i,j,number);
            }
        }
    }
           return Result;
}




//main function
int main()
{
	int numRows, numCols, numNonZero;

//read in all the numRows, numCols and numNonZero values from redirected input for matrix A
	cin >> numRows >> numCols >> numNonZero;

//declare object for matrix A
matrixClass A (numRows, numCols);

//read in the values and use setValue to set the values read in for A
//use the setValue method to put the values in the mat of A
int i, r, c, v;
for (i = 0 ; i < numNonZero ; i++)
    {cin >> r >> c >> v;
        A.setValue (r, c, v);}

//display matrix A
	cout << "A: " << endl;
    A.display();

//read in all the numRows, numCols and numNonZero values from redirected input for matrix B
cin >> numRows >> numCols >> numNonZero;

//declare object for matrix B
matrixClass B (numRows, numCols);
	// read in the values and use setValue to set the values read in for B
	// use the setValue method to put the values in the mat of B
int a, b, d, e;
for (a = 0 ; a < numNonZero ; a++)
    {cin >> b >> d >> e;
        B.setValue (b, d, e);}

//display matrix B
cout << "B: " << endl;
B.display();


	
//display resultant matrix
cout << "RESULT: " << endl;

//declare resultant matrix to store A * B
matrixClass* Result = A.multiply(&B);
    Result->display();

return 0; 
}