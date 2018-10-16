#include "Matrix3D.h"

Matrix3D::Matrix3D()
{
	m[0][0] = 1.0f; m[1][0] = 0.0f; m[2][0] = 0.0f;
	m[0][1] = 0.0f; m[1][1] = 1.0f; m[2][1] = 0.0f;
	m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = 1.0f;
}

Matrix3D::Matrix3D(float m00, float m10, float m20,	float m01, float m11, float m21, float m02, float m12, float m22)
{
	m[0][0] = m00; m[1][0] = m10; m[2][0] = m20;
	m[0][1] = m01; m[1][1] = m11; m[2][1] = m21;
	m[0][2] = m02; m[1][2] = m12; m[2][2] = m22;
}

Matrix3D::Matrix3D(Vector3D& v1, Vector3D& v2, Vector3D& v3)
{
	m[0][0] = v1.GetX(); m[1][0] = v2.GetX(); m[2][0] = v3.GetX();
	m[0][1] = v1.GetY(); m[1][1] = v2.GetY(); m[2][1] = v3.GetY();
	m[0][2] = v1.GetZ(); m[1][2] = v2.GetZ(); m[2][2] = v3.GetZ();
}

Matrix3D::~Matrix3D()
{
}

Matrix3D::Matrix3D(const Matrix3D& mtx)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = mtx(i, j);
		}
	}
}

Matrix3D& Matrix3D::operator=(const Matrix3D& mtx)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = mtx(i, j);
		}
	}

	return *this;
}

float& Matrix3D::operator()(int i, int j)
{
	return m[i][j];
}

const float & Matrix3D::operator()(int i, int j) const
{
	return m[i][j];
}

Vector3D& Matrix3D::operator[](int i)
{
	return (*reinterpret_cast<Vector3D *>(m[i]));
}

const Vector3D& Matrix3D::operator[](int i) const
{
	return (*reinterpret_cast<const Vector3D *>(m[i]));
}

Matrix3D Matrix3D::operator*(const Matrix3D& mtx) const
{
	return Matrix3D(
		m[0][0] * mtx(0, 0) + m[1][0] * mtx(0, 1) + m[2][0] * mtx(0, 2),
		m[0][0] * mtx(1, 0) + m[1][0] * mtx(1, 1) + m[2][0] * mtx(1, 2),
		m[0][0] * mtx(2, 0) + m[1][0] * mtx(2, 1) + m[2][0] * mtx(2, 2),
		m[0][1] * mtx(0, 0) + m[1][1] * mtx(0, 1) + m[2][1] * mtx(0, 2),
		m[0][1] * mtx(1, 0) + m[1][1] * mtx(1, 1) + m[2][1] * mtx(1, 2),
		m[0][1] * mtx(2, 0) + m[1][1] * mtx(2, 1) + m[2][1] * mtx(2, 2),
		m[0][2] * mtx(0, 0) + m[1][2] * mtx(0, 1) + m[2][2] * mtx(0, 2),
		m[0][2] * mtx(1, 0) + m[1][2] * mtx(1, 1) + m[2][2] * mtx(1, 2),
		m[0][2] * mtx(2, 0) + m[1][2] * mtx(2, 1) + m[2][2] * mtx(2, 2)
	);
}

const Matrix3D& Matrix3D::operator*=(const Matrix3D& mtx)
{
	return  *this = *this * mtx;
}

Vector3D Matrix3D::operator*(const Vector3D& rhs) const
{
	return Vector3D(
		m[0][0] * rhs.GetX() + m[1][0] * rhs.GetY() + m[2][0] * rhs.GetZ(),
		m[0][1] * rhs.GetX() + m[1][1] * rhs.GetY() + m[2][1] * rhs.GetZ(),
		m[0][2] * rhs.GetX() + m[1][2] * rhs.GetY() + m[2][2] * rhs.GetZ()
	);
}
