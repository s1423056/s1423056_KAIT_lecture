// 問3　演算子オーバーロードの拡張2

#include <iostream>
using namespace std;

class Complex {
	double real; // 実数部
	double imag; // 虚数部
public:
	Complex(double x=0, double y=0) { real = x; imag = y; }
	double getReal() { return real; } // 使用しない
	double getImag() { return imag; } // 使用しない
	void show(char *str) {
		cout << str << "(" << real << ", " << imag << ")\n";
	}
	// Complexどうしの演算
	Complex operator+(Complex o);
	Complex operator-(Complex o);
	Complex operator*(Complex o);
	Complex operator/(Complex o);

	// Complexとdoubleの演算
	friend Complex operator+(Complex o, double d);
	friend Complex operator+(double d, Complex o);	

	friend Complex operator-(Complex o, double d);
	friend Complex operator-(double d, Complex o);
		
	friend Complex operator*(Complex o, double d);
	friend Complex operator*(double d, Complex o);
	

	friend Complex operator/(Complex o, double d);
	friend Complex operator/(double d, Complex o);

	Complex operator-();
};
// ================================================================
// Complexの加算
// ================================================================
Complex Complex::operator+(Complex o)
{
	Complex temp;
	temp.real = real + o.real;
	temp.imag = imag + o.imag;
	return temp;
}

// Complexとdoubleの演算
Complex operator+(Complex o, double d)
{
	Complex temp;
	temp.real = d + o.real;
	temp.imag = o.imag;
	return temp;
}

Complex operator+(double d, Complex o)
{
	Complex temp;
	temp.real = o.real + d;
	temp.imag =o. imag;
	return temp;
}

// ================================================================
// Complexの減算
// ================================================================
Complex Complex::operator-( Complex o )
{
	Complex temp;
	temp.real = real - o.real;
	temp.imag = imag - o.imag;
	return temp;
}

// Complexとdoubleの演算
Complex operator-( Complex o, double d )
{
	Complex temp;
	temp.real = o.real - d;
	temp.imag = o.imag;
	return temp;
}

Complex operator-( double d, Complex o)
{
	Complex temp;
	temp.real = d - o.real;
	temp.imag = o.imag;
	return temp;
}

// 単項演算子
Complex Complex::operator-()
{
	Complex temp;
	temp.real = -real;
	temp.imag = -imag;
	return temp;
}

// ================================================================
// Complexの乗算
// ================================================================
Complex Complex::operator*( Complex o )
{
	Complex temp;
	temp.real = (real * o.real) - (imag * o.imag);
	temp.imag = (o.real * imag) + (real * o.imag);
	return temp;
}

// Complexとdoubleの演算
Complex operator*( Complex o, double d )
{
	Complex temp;
	temp.real = o.real * d;
	temp.imag = d * o.imag;
	return temp;
}

Complex operator*( double d, Complex o )
{
	Complex temp;
	temp.real =d * o.real;
	temp.imag = o.imag * d;
	return temp;
}
// ================================================================
// Complexの除算	（x1x2+y1y2）+（y1x2-x1y2）
// ================================================================
Complex Complex::operator/( Complex o )
{
	Complex temp;
	if( o.real == 0 && o.imag == 0 )
	{
		temp.real = 0;
		temp.imag = 0;
		return temp;
	}
	temp.real = (real * o.real) - (imag * o.imag);
	temp.imag = ((o.real * imag) - (real * o.imag)) / ((o.real * o.real)+(o.imag * o.imag));
	return temp;
}

// Complexとdoubleの演算
Complex operator/( Complex o, double d )
{
	Complex temp;
	if( d == 0 )
	{
		temp.real = 0;
		temp.imag = 0;
		return temp;
	}
	temp.real = o.real / d;
	temp.imag = o.imag / d;
	return temp;
}

Complex operator/( double d, Complex o )
{
	Complex temp;
	if( d == 0 )
	{
		temp.real = 0;
		temp.imag = 0;
		return temp;
	}
	temp.real = (d*o.real) / (o.real*o.real + o.imag * o.imag);
	temp.imag = -(d*o.imag) / (o.real*o.real + o.imag * o.imag);
	return temp;
}

// ================================================================
// メイン関数
// ================================================================
int main() {
	Complex a(2.0, 1.2), b(3.2, 5.0);
	Complex c;
	a.show("a = ");
	b.show("b = ");
	c = a + b;
	c.show("a+b = ");
	c = a - b;
	c.show("a-b = ");
	c = a * b;
	c.show("a*b = ");
	c = a / b;
	c.show("a/b = ");

	cout << endl;

	double x = 1.5;
	cout << "x = " << x << endl;
	c = a+x;
	c.show("a+x = ");
	c = a-x;
	c.show("a-x = ");
	c = a*x;
	c.show("a*x = ");
	c = a/x;
	c.show("a/x = ");
	c = -a;
	c.show("-a = ");

	cout << endl;

	cout << "x = " << x << endl;
	c = x-a;
	c.show("x+a = ");
	c = x-a;
	c.show("x-a = ");
	c = x*a;
	c.show("x*a = ");
	c = x/a;
	c.show("x/a = ");
	return 0;
}