//main.cpp
//SuTaNa Math Engine
//
//Created by Tareq Anwar

#include <iostream>
#include "Vector3D.h"
#include "Matrix3D.h"

int main(int argc, const char argv[]) {

	//TESTING VECTOR

	//Initializing two vectors
	Vector3D vector1(1.0f, 2.0f, -3.0f);
	Vector3D vector2(3.0f, -2.0f, 1.0f);

	//Check magnitude
	std::cout << vector1.GetMagnitudeSq() << std::endl;
	std::cout << vector1.GetMagnitude() << std::endl;;

	float dot1 = vector1.Dot(vector2);

	float dot2 = vector1 * vector2;

	std::cout << "dot1 = " << dot1 << " & dot2 = " << dot2 << std::endl;

	//Addition: vector3 = vector1 + vector2
	Vector3D vector3 = vector1 + vector2;

	//Addition: vector1 += vector2
	vector1 += vector2;

	//Subtraction: vector4 = vector1 - vector2
	vector3 = vector1 - vector2;

	//Subtraction: vector1 -= vector2
	vector1 -= vector2;

	const float speed = 3.0f;

	//Multipication: vector4 = vector1 * speed
	vector3 = vector1 * speed;

	//Subtraction: vector1 -= vector2
	vector1 *= speed;

	//Subtraction: vector4 = vector1 / speed
	vector3 = vector1 / speed;

	//Subtraction: vector1 /= speed
	vector1 /= speed;

	//Check Normalization
	vector3.Normalize();

	//TESTING MATRIX


	Vector3D vector4(3.0f, 5.0f, 4.0f);
	Vector3D vector5(2.0f, 3.0f, 2.0f);
	Vector3D vector6(1.0f, 3.0f, 1.0f);

	Matrix3D mtx1(
		7.0f, 6.0f, 3.0f,
		4.0f, 2.0f, 5.0f,
		10.0f, 6.0f, 4.0f
	);

	Matrix3D mtx2(vector4, vector5, vector6);

	//mtx2 = mtx1;

	vector6 = mtx2 * vector4;

	Matrix3D mtx3 = mtx1;
	//mtx1(1,2);

	//vector2 = mtx2[1];

	std::cin.get();

	return 0;
}