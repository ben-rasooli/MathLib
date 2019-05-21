#include "pch.h"
#include "Vector2.h"
#include <cmath>
#include <cassert>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::magnitude()
{
	return sqrtf((x * x) + (y * y));
}

float Vector2::magnitudeSqr()
{
	return (x * x) + (y * y);
}

float Vector2::distance(Vector2 other)
{
	Vector2 diff = Vector2(x, y) - other;
	return diff.magnitude();
}

void Vector2::normalise()
{
	float mag = magnitude();

	assert(mag != 0 && "normalise: divide by zero");
	if (mag != 0)
	{
		x /= mag;
		y /= mag;
	}
}

Vector2 Vector2::normalised()
{
	Vector2 result(x, y);
	result.normalise();
	return result;
}

float Vector2::dot(Vector2& other)
{
	return (x * other.x) + (y * other.y);
}

Vector2 Vector2::right()
{
	return Vector2(-y, x);
}

Vector2 Vector2::left()
{
	return Vector2(y, -x);
}

Vector2 Vector2::lerp(Vector2 startPoint, Vector2 endPoint, float percent)
{
	Vector2 offset = percent * (endPoint - startPoint);
	return startPoint + offset;
}

Vector2 Vector2::zero()
{
	return Vector2(0, 0);
}

Vector2 Vector2::operator+(Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float multiplier)
{
	return Vector2(x * multiplier, y * multiplier);
}

Vector2 operator*(float multiplier, Vector2 vector2)
{
	return vector2 * multiplier;
}

Vector2 Vector2::operator/(float divider)
{
	return Vector2(x / divider, y / divider);
}

Vector2& Vector2::operator+=(const Vector2 & other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2 & other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

float& Vector2::operator[](int index)
{
	switch (index)
	{
	default:
	case 0: return x;
	case 1: return y;
	}
}

Vector2::operator float*()
{
	return (float*)this;
}
