/**
* @file Vector3.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 2 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script para usar Vectores
* Script sacado del repositorio de Ángel Rodríguez de Bitbucket:
* https://bitbucket.org/angel-esne/c-code-examples/src/master/3.%20operadores/Vector3/code/
**/

#include "Vector3.hpp"

namespace Math
{
	Vector3::Vector3(float x, float y, float z)
	{
		vector[0] = x;
		vector[1] = y;
		vector[2] = z;
	}

	Vector3::Vector3(float(&array)[3])
	{
		vector[0] = array[0];
		vector[1] = array[1];
		vector[2] = array[2];
	}

	float Vector3::moduloValue() const
	{
		return sqrt(x() * x() + y() * y() + z() * z());
	}

	float Vector3::length() const
	{
		return moduloValue();
	}

	Vector3 Vector3::normalized() const
	{
		return *this / moduloValue();
	}

	Vector3& Vector3::normalize()
	{
		return *this /= moduloValue();
	}
	
	Vector3& Vector3::operator += (const Vector3& other)
	{
		this->x() += other.x();
		this->y() += other.y();
		this->z() += other.z();
		return *this;
	}

	Vector3& Vector3::operator -= (const Vector3& other)
	{
		this->x() -= other.x();
		this->y() -= other.y();
		this->z() -= other.z();
		return *this;
	}

	Vector3& Vector3::operator *= (const float& other)
	{
		this->x() -= other;
		this->y() -= other;
		this->z() -= other;
		return *this;
	}

	Vector3& Vector3::operator /= (const float& other)
	{
		float inverse = 1.f / other;

		this->x() *= inverse;
		this->y() *= inverse;
		this->z() *= inverse;

		return *this;
	}

	Vector3 Vector3::operator + (const Vector3& other) const
	{
		return { this->x() + other.x(), this->y() + other.y(), this->z() + other.z() };
	}

	Vector3 Vector3::operator - (const Vector3& other) const
	{
		return { this->x() - other.x(), this->y() - other.y(), this->z() - other.z() };
	}

	float Vector3::operator * (const Vector3& other) const
	{
		return this->x() * other.x() + this->y() * other.y() + this->z() * other.z();;
	}

	Vector3 Vector3::operator * (const float other) const
	{
		return { x() * other, y() * other, z() * other };
	}

	Vector3 Vector3::operator / (const float other) const
	{
		return { x() / other, y() / other, z() / other };
	}

	Vector3 Vector3::operator + () const
	{
		return { x(), y(), z() };
	}

	Vector3 Vector3::operator - () const
	{
		return { -x(), -y(), -z() };
	}

	bool Vector3::operator == (const Vector3& other) const
	{
		return this->x() == other.x() && this->y() == other.y() && this->z() == other.z();
	}

	bool Vector3::operator != (const Vector3& other) const
	{
		return not (*this == other);
	}

	bool Vector3::operator < (const Vector3& other) const
	{
		return this->moduloValue() < other.moduloValue();
	}

	bool Vector3::operator <= (const Vector3& other) const
	{
		return this->moduloValue() <= other.moduloValue();
	}

	bool Vector3::operator > (const Vector3& other) const
	{
		return this->moduloValue() > other.moduloValue();
	}

	bool Vector3::operator >= (const Vector3& other) const
	{
		return this->moduloValue() >= other.moduloValue();
	}
}
