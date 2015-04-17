#include "Matrix.hpp"

Matrix::Matrix():
m11(0), m12(0), m13(0), m14(0),
m21(0), m22(0), m23(0), m24(0),
m31(0), m32(0), m33(0), m34(0),
m41(0), m42(0), m43(0), m44(0)
{}

Matrix::Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44):
m11(m11), m12(m12), m13(m13), m14(m14), 
m21(m21), m22(m22), m23(m23), m24(m24),
m31(m31), m32(m32), m33(m33), m34(m34), 
m41(m41), m42(m42), m43(m43), m44(m44)
{}

// TODO: Fix method to work properly
float* Matrix::ToArray() { float arr[16] = { m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 };	return arr; }
float Matrix::Determinant()
{
	return m11 * DeterminantHelper(m22, m23, m24, m32, m33, m34, m42, m43, m44) - 
	m12 * DeterminantHelper(m21, m23, m24, m31, m33, m34, m41, m43, m44) +
	m13 * DeterminantHelper(m21, m22, m24, m31, m32, m34, m41, m42, m44) -
	m14 * DeterminantHelper(m21, m22, m23, m31, m32, m33, m41, m42, m43);
}

Matrix Matrix::operator+(const Matrix& m)
{ 
	return Matrix(m11 + m.m11, m12 + m.m12, m13 + m.m13, m14 + m.m14, 
		m21 + m.m21, m22 + m.m22, m23 + m.m23, m24 + m.m24, 
		m31 + m.m31, m32 + m.m32, m33 + m.m33, m34 + m.m34, 
		m41 + m.m41, m42 + m.m42, m43 + m.m43, m44 + m.m44);
}

Matrix Matrix::operator-(const Matrix& m)
{ 
	return Matrix(m11 - m.m11, m12 - m.m12, m13 - m.m13, m14 - m.m14, 
		21 - m.m21, m22 - m.m22, m23 - m.m23, m24 - m.m24, 
		m31 - m.m31, m32 - m.m32, m33 - m.m33, m34 - m.m34,
		m41 - m.m41, m42 - m.m42, m43 - m.m43, m44 - m.m44);
}

Matrix Matrix::operator*(const Matrix& m)
{
	return Matrix(
		((m11 * m.m11) + (m12 * m.m21) + (m13 * m.m31) + (m14 * m.m41)),
		((m11 * m.m12) + (m12 * m.m22) + (m13 * m.m32) + (m14 * m.m42)),
		((m11 * m.m13) + (m12 * m.m23) + (m13 * m.m33) + (m14 * m.m43)),
		((m11 * m.m14) + (m12 * m.m24) + (m13 * m.m34) + (m14 * m.m44)),

		((m21 * m.m11) + (m22 * m.m21) + (m23 * m.m31) + (m24 * m.m41)),
		((m21 * m.m12) + (m22 * m.m22) + (m23 * m.m32) + (m24 * m.m42)),
		((m21 * m.m13) + (m22 * m.m23) + (m23 * m.m33) + (m24 * m.m43)),
		((m21 * m.m14) + (m22 * m.m24) + (m23 * m.m34) + (m24 * m.m44)),

		((m31 * m.m11) + (m32 * m.m21) + (m33 * m.m31) + (m34 * m.m41)),
		((m31 * m.m12) + (m32 * m.m22) + (m33 * m.m32) + (m34 * m.m42)),
		((m31 * m.m13) + (m32 * m.m23) + (m33 * m.m33) + (m34 * m.m43)),
		((m31 * m.m14) + (m32 * m.m24) + (m33 * m.m34) + (m34 * m.m44)),

		((m41 * m.m11) + (m42 * m.m21) + (m43 * m.m31) + (m44 * m.m41)),
		((m41 * m.m12) + (m42 * m.m22) + (m43 * m.m32) + (m44 * m.m42)),
		((m41 * m.m13) + (m42 * m.m23) + (m43 * m.m33) + (m44 * m.m43)),
		((m41 * m.m14) + (m42 * m.m24) + (m43 * m.m34) + (m44 * m.m44))
		);
}

Matrix Matrix::operator/(const Matrix& m)
{
	return Matrix(
		m11 / m.m11, m12 / m.m12, m13 / m.m13, m14 / m.m14,
		m21 / m.m21, m22 / m.m22, m23 / m.m23, m24 / m.m24,
		m31 / m.m31, m32 / m.m32, m33 / m.m33, m34 / m.m34,
		m41 / m.m41, m42 / m.m42, m43 / m.m43, m44 / m.m44
		);
}

Matrix Matrix::operator/(const float& f)
{
	return Matrix(
		m11 / f, m12 / f, m13 / f, m14 / f,
		m21 / f, m22 / f, m23 / f, m24 / f,
		m31 / f, m32 / f, m33 / f, m34 / f,
		m41 / f, m42 / f, m43 / f, m44 / f
		);
}

bool Matrix::operator==(const Matrix& m)
{
	return				  
		(m11 == m.m11) && (m12 == m.m12) && (m13 == m.m13) && (m14 == m.m14) &&
		(m21 == m.m21) && (m22 == m.m22) && (m23 == m.m23) && (m24 == m.m24) &&
		(m31 == m.m31) && (m32 == m.m32) && (m33 == m.m33) && (m34 == m.m34) &&
		(m41 == m.m41) && (m42 == m.m42) && (m43 == m.m43) && (m44 == m.m44);
}

Matrix operator*(const Matrix& m, float s)
{ 
	return Matrix(
		m.m11 / s, m.m12 / s, m.m13 / s, m.m14 / s,
		m.m21 / s, m.m22 / s, m.m23 / s, m.m24 / s,
		m.m31 / s, m.m32 / s, m.m33 / s, m.m34 / s,
		m.m41 / s, m.m42 / s, m.m43 / s, m.m44 / s
		);
}

Matrix operator*(float s, Matrix& m)
{
	return Matrix(
		m.m11 / s, m.m12 / s, m.m13 / s, m.m14 / s,
		m.m21 / s, m.m22 / s, m.m23 / s, m.m24 / s,
		m.m31 / s, m.m32 / s, m.m33 / s, m.m34 / s,
		m.m41 / s, m.m42 / s, m.m43 / s, m.m44 / s
		);
}

float Matrix::DeterminantHelper(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
{
	float d11 = m22*m33 - m23*m32;
	float d12 = m21*m33 - m23*m31;
	float d13 = m21*m32 - m22*m31;

	return m11*d11 - m12*d12 + m13*d13;
}