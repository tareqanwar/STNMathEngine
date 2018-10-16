#pragma once
#include "Vector3D.h"

/**
 * Defines a 3 x 3 floating point matrix.
 *
* Vectors are treated as columns, resulting in a matrix that is represented as follows
*
* 1  0  0
* 0  1  0
* 0  0  1
*
 */
class Matrix3D
{
public:
	/**
	 * Constructs a new 3x3 matrix initialized to the identity matrix.
	 */
	Matrix3D();

	/**
	 * Constructs a matrix initialized to the specified value.
	 *
	 * @param m00 The first element of the first column.
	 * @param m01 The second element of the first column.
	 * @param m02 The third element of the first column.
	 * @param m10 The first element of the second column.
	 * @param m11 The second element of the second column.
	 * @param m12 The third element of the second column.
	 * @param m20 The first element of the third column.
	 * @param m21 The second element of the third column.
	 * @param m22 The third element of the third column.
	 */
	Matrix3D(
		float m00, float m10, float m20,
		float m01, float m11, float m21,
		float m02, float m12, float m22
	);

	/**
	 * Constructs a matrix initialized to the specified vectors.
	 *
	 * @param v1 The first column of the matrix.
	 * @param v2 The second column of the matrix.
	 * @param v3 The third column of the matrix.
	 */
	Matrix3D( Vector3D& v1, Vector3D& v2, Vector3D& v3);

	/*
	* Destructors
	*/
	~Matrix3D();

	/**
	* Constructs a new matrix by copying the values from the specified matrix.
	*
	* @param mtx The matrix to copy.
	*/
	Matrix3D(const Matrix3D& mtx);

	/**
	 * Copies the right hand side matrix to the left hand side matrix.
	 *
	 * @param mtx The matrix to copy.
	 */
	Matrix3D& operator =(const Matrix3D& mtx);

	//Operator overloading

	/**
	 * Returns the value of (i,j) position of the matrix
	 *
	 * @param i The ith index.
	 * @param j The jth index.
	 * @return (i, j) position of the matrix.
	 */
	float& operator ()(int i, int j);
	const float& operator ()(int i, int j) const;


	/**
	 * Returns the vector of ith column
	 *
	 * @param i The ith column.
	 * @return vector of column i.
	 */
	Vector3D& operator [] (int i);
	const Vector3D& operator [] (int i) const;

	/**
	 * Calculates the multipication of this matrix with the given matrix.
	 *
	 * Note: this does not modify this matrix.
	 *
	 * @param mtx The other matrix to multiply.
	 * @return The new matrix after multipication occures.
	 */
	Matrix3D operator *(const Matrix3D& mtx) const;

	/**
	 * Construct a matrix with the multipication of this matrix and a given matrix.
	 *
	 * @param mtx The other matrix to multiply.
	 * @return this matrix after multipication occures.
	 */
	const Matrix3D& operator *=(const Matrix3D& mtx);

	/**
	 * Calculates the multipication of this matrix with the given vector.
	 *
	 * Note: this does not modify this matrix.
	 *
	 * @param rhs The vector.
	 * @return The new vector after multipication occures.
	 */
	Vector3D operator *(const Vector3D& rhs) const;

private:
	/*
	* Stores the values of the specific positions of this 3x3 matrix.
	*/
	float m[3][3];
};
