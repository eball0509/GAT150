#pragma once
#include <math.h>
using namespace std;

namespace Math
{
	constexpr float HalfPi = 1.57079632679f;
	constexpr float Pi = 3.14159265359f;
	constexpr float TwoPi = 6.28318530718f;

	constexpr float RadToDeg(float radians) { return radians * (180 / Pi); }
	constexpr float DegToRad(float degrees) { return degrees * (Pi / 180); }

	inline float Sin(float radians)
	{
		return sinf(radians);
	}
	inline float Cos(float radians)
	{
		return cosf(radians);
	}

	inline float Sqrt(float value)
	{
		return sqrtf(value);
	}

	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}


	template<typename T>
	T Max(T a, T b) { return (a > b) ? a : b; }

	template<typename T>
	T Min(T a, T b) { return (a < b) ? a : b; }

	template<typename T>
	T abs(T val) { return (val < 0) ? -val : val; }

	template<typename T>
	T Clamp(T value, T min, T max) { return (value > max) ? max : (value < min) ? min : value; }

	inline int Wrap(int value, int max)
	{
		return value % max + ((value < 0) ? max : 0);
	}

	inline float Wrap(float value, float max)
	{
		return fmodf(value, max) + ((value < 0) ? max : 0);
	}

}
