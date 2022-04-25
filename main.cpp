#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Matrix.h"

using namespace std;

/*
  Reads matrices from a text file.
  Makes matrices calculations.
  Displays result to the console.
  Takes a string reference with filename as parameter.
*/
void testMatrixOperatorOverload(string& fileName);

int main()
{
	// create vector of filenames
	vector<string> fileNames{ "input1.txt", "input2.txt" , "input3.txt", "input4.txt",
								"input5.txt", "input6.txt", "input7.txt" };

	for (string fileName : fileNames)
	{
		// feed the test function with the files from a vector
		testMatrixOperatorOverload(fileName);
		cout << "==================================" << endl;
	}

	return 0;
}

void testMatrixOperatorOverload(string& fileName)
{
	// Variables to hold data from the input file
	int dimension{ 0 };
	int exponent{ 0 };
	string operation{ "empty" };

	// create Matrix objects to hold data from the input file
	Matrix<int, 0> aMatrix;
	Matrix<int, 0> otherMatrix;
	Matrix<int, 0> resultMatrix;

	// create an ifstream object to read the input file
	ifstream inputFile;

	// open the file
	inputFile.open(fileName);

	// check if it doesn't exists
	if (!inputFile)
	{
		cerr << "Problem opening file" << endl;
		return;
	}
	else
	{
		// read a file till the eof
		while (!inputFile.eof())
		{
			// read the dimension
			inputFile >> dimension;

			// fill first matrix
			aMatrix.fillMatrix(dimension, inputFile);

			// consumming a line
			inputFile.get();

			// get the operation string
			getline(inputFile, operation);

			// print it to console
			cout << operation << endl;

			if (operation == "op 1") // addition
			{
				otherMatrix.fillMatrix(dimension, inputFile);
				
				resultMatrix.allocateMatrix(dimension);

				cout << "The result of addition two matrices is: " << endl;

				resultMatrix = aMatrix + otherMatrix;

				cout << resultMatrix << endl;

			}
			else if (operation == "op 2") // subtruction
			{
				otherMatrix.fillMatrix(dimension, inputFile);
				
				resultMatrix.allocateMatrix(dimension);

				cout << "The result of subtruction two matrices is: " << endl;

				resultMatrix = aMatrix - otherMatrix;

				cout << resultMatrix << endl;
			}
			else if (operation == "op 3") //  multiplication
			{
				otherMatrix.fillMatrix(dimension, inputFile);
				
				resultMatrix.allocateMatrix(dimension);

				cout << "The result of multiplication two matrices is: " << endl;

				resultMatrix = aMatrix * otherMatrix;

				cout << resultMatrix << endl;
			}
			else if (operation == "op 4") //  postincrement
			{
				aMatrix++;

				cout << "The result of a matrix postincrement is: " << endl;

				cout << aMatrix << endl;
			}
			else if (operation == "op 5") //  predecrement
			{
				--aMatrix;

				cout << "The result of a matrix predecrement is: " << endl;

				cout << aMatrix << endl;
			}
			else if (operation == "op 6") //  transpose
			{
				~aMatrix;

				cout << "The result of a matrix transpose is: " << endl;

				cout << aMatrix << endl;
			}
			else if (operation == "op 7") // raise to power
			{
				// read the exponent
				inputFile >> exponent;

				aMatrix ^ (exponent);

				cout << "The result of a matrix to power is: " << endl;

				cout << aMatrix << endl;
			}
		}
	}
	inputFile.close();
}

