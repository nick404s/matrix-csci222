#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>


using namespace std;

/*
	A template class that represents quadratic matrix.
	Can take numbers as values for the matrix.
*/

template <typename T, int dimension>
class Matrix
{

public:

	/**
	No-args condtructor.
	*/
	Matrix();

	/**
	Constructor that takes dimension and allocates memory on the heap for the matrix.
	*/
	Matrix(int dimension);

	/*
	Destructor
	*/
	~Matrix();

	/**
	 Returns the dimension of the Matrix object
	*/
	int getDimension() const;

	/**
	 Gets an element from this matrix at the i, j position
	*/
	T getElement(int i, int j) const;

	/* 
	Allocates memory on the heap for the matrix.
	Takes int dimension for the matrix as parameter.
	*/
	void allocateMatrix(int inputDimension);

	/**
	Populates this matrix.
	Takes int dimension and ifstream reference as parameters.
	*/
	void fillMatrix(int inputDimension, ifstream& input);

	/**
	Overloads assignment operator.
	Takes another Matrix reference as parameter.
	*/
	Matrix& operator=(Matrix const& other);

	/**
	Overloads addition operator.
	Takes another Matrix reference as parameter.
	*/
	Matrix& operator+(Matrix& other);

	/**
	Overloads subtruction operator.
	Takes another Matrix reference as parameter.
	*/
	Matrix& operator-(Matrix& other);

	/**
	Overloads multiplication operator.
	Takes another Matrix reference as parameter.
	*/
	Matrix& operator*(Matrix& other);

	/*
	Overloads pre-increment operator.
	*/
	Matrix& operator++();

	/**
	Overloads post-increment operator.
	Takes a dummy int number as parameter.
	*/
	Matrix& operator++(int number);

	/**
	Overloads pre-decrement operator.
	*/
	Matrix& operator--();

	/**
	Overloads post-decrement operator.
	*/
	Matrix& operator--(int number);

	/**
	Overloads transpose operator.
	*/
	Matrix& operator~();

	/**
	Overloads exponential operator.
	Takes int exponent as parameter.
	*/
	Matrix& operator^(int exponent);

private:
	// Dimension of the matrix
	int dimension;

	// Pointer to the matrix array
	T* matrixArray;

}; // End of interface


/*
Overloads stream operator overload. Non-member function.
Takes ostream and Matrix references as parameters.
Prints the Matrix.
*/
template <typename T, int dimension>
ostream& operator<<(ostream& outStream, Matrix<T, dimension>& matrix)
{
	for (int i = 0; i < matrix.getDimension(); i++)
	{
		for (int j = 0; j < matrix.getDimension(); j++)
		{
			cout << matrix.getElement(i, j) << " ";
		}
		cout << endl;
	}
	return outStream;
}

template <typename T, int dimension>
Matrix<T,dimension>::Matrix()
	: matrixArray{ nullptr }, dimension{ 0 }
{
}
template <typename T, int dimension>
Matrix<T, dimension>::Matrix(int inputDimension)
{
	allocateMatrix(inputDimension);
}

template <typename T, int dimension>
Matrix<T, dimension>::~Matrix()
{
	delete[] matrixArray;
}

template <typename T, int dimension>
void Matrix<T, dimension>::allocateMatrix(int inputDimension)
{
	if (inputDimension > 0) // check the input dimension
	{
		this->dimension = inputDimension;
		// Allocate memory on the heap
		matrixArray = new int[dimension * dimension];
	}
}

template <typename T, int dimension>
void Matrix<T, dimension>::fillMatrix(int inputDimension, ifstream& inputNumber)
{
	allocateMatrix(inputDimension);
	// Initialize the array with numbers from the file:
	for (int i = 0; i < dimension * dimension; i++)
	{
		inputNumber >> matrixArray[i];
	}
}

template <typename T, int dimension>
int Matrix<T, dimension>::getDimension() const
{
	return dimension;
}

template <typename T, int dimension>
T Matrix<T, dimension>::getElement(int i, int j) const
{
	return matrixArray[i * dimension + j];
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator=(Matrix const& other)
{
	// check if it's a self assignment
	if (this == &other)
	{
		return *this;
	}
	delete[] this->matrixArray; //  delete the old memory

	this->dimension = other.dimension;

	this->matrixArray = new int[dimension * dimension]; // allocate the new array

	for (int i = 0; i < dimension * dimension; i++)
	{
		// assign each element of this array with a value from the other matrix
		this->matrixArray[i] = other.matrixArray[i];
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator+(Matrix& other)
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// Calculate the sum and put the result in this matrix
		matrixArray[i] += other.matrixArray[i];
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator-(Matrix& other)
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// Calculate the subtruction and put the result in this matrix
		matrixArray[i] -= other.matrixArray[i];
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator*(Matrix& other)
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// Calculate the product and put the result in this matrix
		matrixArray[i] *= other.matrixArray[i];
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator++()
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// add 1 to each element in this matrix
		matrixArray[i] += 1;
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator++(int number)
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// add 1 to each element in this matrix
		matrixArray[i] += 1;
	}
	return *this;
}


template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator--()
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// subtruct 1 from each element in this matrix
		matrixArray[i] -= 1;
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator--(int number)
{
	for (int i = 0; i < dimension * dimension; i++)
	{
		// subtruct 1 from each element in this matrix
		matrixArray[i] -= 1;
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator~()
{
	// create a temp matrix to hold data from this matrix
	Matrix tempMatrix(dimension);

	// Point the temp matrix to this matrix
	tempMatrix = *this;

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			// change the rows with columns
			matrixArray[i * dimension + j] = tempMatrix.matrixArray[j * dimension + i];
		}
	}
	return *this;
}

template <typename T, int dimension>
Matrix<T, dimension>& Matrix<T, dimension>::operator^(int exponent)
{
	// create a temp matrix to hold data from this matrix
	Matrix tempMatrix(dimension);

	// Point the temp matrix to this matrix
	tempMatrix = *this;

	for (int i = exponent; i > 1; i--)
	{
		// using multiplication operator overload for the Matrix class
		*this = (*this) * tempMatrix;
	}
	return *this;
}



#endif // MATRIX_H

