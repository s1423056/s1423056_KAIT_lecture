// 問2　演算子オーバーロードの拡張

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
	Complex operator+(double d);
	Complex operator-(double d);
	Complex operator*(double d);
	Complex operator/(double d);
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
Complex Complex::operator+(double d)
{
	Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}

// ================================================================
// Complexの減算
// ================================================================
Complex Complex::operator-(Complex o)
{
	Complex temp;
	temp.real = real - o.real;
	temp.imag = imag - o.imag;
	return temp;
}

// Complexとdoubleの演算
Complex Complex::operator-(double d)
{
	Complex temp;
	temp.real = real - d;
	temp.imag = imag;
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
Complex Complex::operator*(Complex o)
{
	Complex temp;
	temp.real = (real * o.real) - (imag * o.imag);
	temp.imag = (o.real * imag) + (real * o.imag);
	return temp;
}

// Complexとdoubleの演算
Complex Complex::operator*(double d)
{
	Complex temp;
	temp.real = real * d;
	temp.imag = d * imag;
	return temp;
}

// ================================================================
// Complexの除算
// ================================================================
Complex Complex::operator/(Complex o)
{
	Complex temp;
	if(o.real == 0 && o.imag == 0)
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
Complex Complex::operator/(double d)
{
	Complex temp;
	if(d == 0)
	{
		temp.real = 0;
		temp.imag = 0;
		return temp;
	}
	temp.real = real / d;
	temp.imag = imag / d;
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
	return 0;
}
