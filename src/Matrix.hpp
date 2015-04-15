#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"

	// TODO: Finish Implementing Matrix Class

struct Matrix
{
	float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;

	//////////////////
	// Constructors //
	//////////////////
	Matrix();
	Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);

	//////////////////////
	// Static Instances //
	//////////////////////
	static Matrix Identity;

	//////////////////////
	// Member Functions //
	//////////////////////
	float  Determinant();
	float* ToArray();

	///////////////
	// Operators //
	///////////////
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix operator/(const Matrix& m);
	Matrix operator/(const float& f);
	bool   operator==(const Matrix& m);

	//////////////////////
	// Static Functions //
	//////////////////////
	static Matrix Add(Matrix& m1, Matrix& m2);
	static Matrix Subtract(Matrix& m1, Matrix& m2);
private:
	/// <summary>
	/// Returns the determinant of a 3x3 matrix
	/// </summary>
	float DeterminantHelper(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
};

#endif