#pragma once

/*
* Defines a 3 - element floating point vector.
*/
class Vector3D
{
public:
	/**
	 * Constructs a new vector initialized to all zeros.
	 */
	Vector3D();

	/**
	 * Constructs a new vector initialized to the specified values.
	 *
	 * @param x The x coordinate.
	 * @param y The y coordinate.
	 * @param z The z coordinate.
	 */
	Vector3D(float x, float y, float z);

	/**
	 * Destructor.
	 */
	~Vector3D();

	/**
	 * Constructs a new vector that is a copy of the specified vector.
	 *
	 * @param v The vector to copy.
	 */
	Vector3D(const Vector3D& v);

	/**
	 * Copies the right hand side vector to the left hand side vector.
	 *
	 * @param v The vector to copy.
	 */
	Vector3D& operator=(const Vector3D& v);

	//Operator overloading

	/**
	 * Calculates the sum of this vector with the given vector.
	 *
	 * Note: this does not modify this vector.
	 *
	 * @param rhs The vector to add.
	 * @return The vector sum.
	 */
	Vector3D operator +(Vector3D& rhs) const;

	/**
	 * Adds the given vector to this vector.
	 *
	 * @param rhs The vector to add.
	 * @return This vector, after the addition occurs.
	 */
	Vector3D& operator +=(Vector3D& rhs);

	/**
	 * Calculates the difference of this vector with the given vector.
	 *
	 * Note: this does not modify this vector.
	 *
	 * @param rhs The vector to substract.
	 * @return The vector difference.
	 */
	Vector3D operator -(Vector3D& rhs) const;

	/**
	 * Subtracts the given vector from this vector.
	 *
	 * @param rhs The vector to subtract.
	 * @return This vector, after the subtraction occurs.
	 */
	Vector3D& operator -=(Vector3D& rhs);

	/**
	 * Calculates the scalar product of this vector with the given value.
	 *
	 * Note: this does not modify this vector.
	 *
	 * @param rhs The value to scale by.
	 * @return The scaled vector.
	 */
	Vector3D operator *(float rhs) const;

	/**
	 * Scales this vector by the given value.
	 *
	 * @param rhs The value to scale by.
	 * @return This vector, after the scale occurs.
	 */
	Vector3D& operator *=(float rhs);

	/**
	 * Returns the components of this vector divided by the given constant
	 *
	 * Note: this does not modify this vector.
	 *
	 * @param rhs the constant to divide this vector with
	 * @return a smaller vector
	 */
	Vector3D operator /(float rhs) const;

	/**
	 * Divides the components of this vector by the given constant
	 *
	 * @param rhs the constant to divide this vector with
	 * @return This vector, after the divition occurs.
	 */
	Vector3D& operator /=(float rhs);

	/**
	 * Computes the magnitude of this vector.
	 *
	 * @return The magnitude of the vector.
	 *
	 * @see GetMagnitudeSq
	 */
	float GetMagnitude() const;

	/**
	 * Returns the squared magnitude of this vector.
	 *
	 * When it is not necessary to get the exact magnitude of a
	 * vector (for example, when simply comparing the magnitude of
	 * different vectors), it is advised to use this method
	 * instead of GetMagnitude.
	 *
	 * @return The squared magnitude of the vector.
	 *
	 * @see GetMagnitude
	 */
	float GetMagnitudeSq() const; 

	/**
	 * Normalizes this vector.
	 *
	 * This method normalizes this Vector3D so that it is of
	 * unit magnitude (in other words, the magnitude of the vector
	 * after calling this method will be 1.0f). If the magnitude
	 * of the vector is zero, this method simply returns this vector.
	 *
	 * @return This vector, after the normalization occurs.
	 *
	 * @see GetNormalized
	 *
	 */
	Vector3D& Normalize();

	/**
	 * Calculates the normalization of this vector.
	 *
	 * Note: this does not modify this vector.
	 *
	 * This method calculates the normalization of this Vector3D. If the magnitude
	 * of the vector is zero, this method simply returns this vector.
	 *
	 * @return a normalized vector of this vector.
	 *
	 * @see Normalize
	 *
	 */
	Vector3D GetNormalized() const;

	/**
	 * Returns value of x, y & z cordinates respectively
	 */
	float GetX() const;
	float GetY() const;
	float GetZ() const;

private:
	/**
	 * x, y and z coordinate
	 */
	float x;
	float y;
	float z;
};
