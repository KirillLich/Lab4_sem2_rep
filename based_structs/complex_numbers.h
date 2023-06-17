#ifndef COMPLEX_NUMBERS
#define COMPLEX_NUMBERS
#include <math.h>

template<typename T>
class complex
{
	T a, b;
public:
	complex(T A, T B) :a(A), b(B) {};
	complex<T> operator+ (complex<T> A)
	{
		return complex(A.a + a, A.b + b);
	}
	complex<T> operator*(complex<T> A)
	{
		return complex(a * A.a - b * A.b, a * A.b + b * A.a);
	}
	complex<T> sqrtc()
	{
		return complex(sqrt((sqrt(a * a + b * b) + a) / 2), (b / abs(b)) * sqrt((sqrt(a * a + b * b) - a) / 2));
	}
};

#endif