/**
* @file Vector3.hpp
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

#pragma once
#include <cmath>
#include <ostream>

namespace Math
{
    class Vector3
    {

    public:
        float vector[3];

        Vector3() = default;
        ~Vector3() = default;
        Vector3(const Vector3&) = default;

        Vector3(float, float, float);

        Vector3(float(&array)[3]);

    public:

        float&  x() { return vector[0]; }
        float   x() const { return vector[0]; }
        float&  y() { return vector[1]; }
        float   y() const { return vector[1]; }
        float&  z() { return vector[2]; }
        float   z() const { return vector[2]; }

    public:


        float moduloValue() const;

        float length() const;

        Vector3 normalized() const;

        Vector3& normalize();


    public:

        Vector3& operator  =    (const Vector3&) = default;

        Vector3& operator +=    (const Vector3&);

        Vector3& operator -=    (const Vector3&);

        Vector3& operator *=    (const float&);

        Vector3& operator /=    (const float&);

        Vector3 operator +      (const Vector3&) const;

        Vector3 operator -      (const Vector3&) const;

        float   operator *      (const Vector3&) const;

        Vector3 operator *      (const float) const;

        Vector3 operator /      (const float) const;

        Vector3 operator +      () const;

        Vector3 operator -      () const;

    public:

        bool operator == (const Vector3&) const;

        bool operator != (const Vector3&) const;

        bool operator <  (const Vector3&) const;
        bool operator <= (const Vector3&) const;
        bool operator >  (const Vector3&) const;
        bool operator >= (const Vector3&) const;
    };
}


