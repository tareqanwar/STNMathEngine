#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D()
	:
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

Vector3D::Vector3D(float init_x, float init_y, float init_z)
	:
	x(init_x),
	y(init_y),
	z(init_z)
{
}

Vector3D::~Vector3D()
{
}

Vector3D::Vector3D(const Vector3D& v)
	:
	x(v.x),
	y(v.y),
	z(v.z)
{
}

Vector3D& Vector3D::operator=(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

Vector3D Vector3D::operator+(Vector3D& rhs) const
{
	return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3D& Vector3D::operator+=(Vector3D& rhs)
{
	return *this = *this + rhs;
}

Vector3D Vector3D::operator-(Vector3D& rhs) const
{
	return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3D& Vector3D::operator-=(Vector3D& rhs)
{
	return *this = *this - rhs;
}

Vector3D Vector3D::operator*(float rhs) const
{
	return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D& Vector3D::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vector3D Vector3D::operator/(float rhs) const
{
	rhs = 1.0f / rhs;
	return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D & Vector3D::operator/=(float rhs)
{
	return *this = *this / rhs;
}

float Vector3D::GetMagnitude() const
{
	return sqrt(GetMagnitudeSq());
}

float Vector3D::Dot(const Vector3D& v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

float Vector3D::operator*(const Vector3D& v) const
{
	return Dot(v);
}

float Vector3D::GetMagnitudeSq() const
{
	return (x * x , y * y, z * z);
}

Vector3D & Vector3D::Normalize()
{
	return *this = GetNormalized();
}

Vector3D Vector3D::GetNormalized() const
{
	const float magnitude = GetMagnitude();

	if (magnitude != 0.0f) {
		return *this / magnitude;
	}

	return *this;
}

float Vector3D::GetX() const
{
	return x;
}

float Vector3D::GetY() const
{
	return y;
}

float Vector3D::GetZ() const
{
	return z;
}
