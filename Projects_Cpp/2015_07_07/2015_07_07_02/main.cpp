// –â2@‰‰ZqƒI[ƒo[ƒ[ƒh‚ÌŠg’£

#include <iostream>
using namespace std;

class Complex {
	double real; // À”•”
	double imag; // ‹•”•”
public:
	Complex(double x=0, double y=0) { real = x; imag = y; }
	double getReal() { return real; } // g—p‚µ‚È‚¢
	double getImag() { return imag; } // g—p‚µ‚È‚¢
	void show(char *str) {
		cout << str << "(" << real << ", " << imag << ")\n";
	}
	// Complex‚Ç‚¤‚µ‚Ì‰‰Z
	Complex operator+(Complex o);
	Complex operator-(Complex o);
	Complex operator*(Complex o);
	Complex operator/(Complex o);

	// Complex‚Ædouble‚Ì‰‰Z
	Complex operator+(double d);
	Complex operator-(double d);
	Complex operator*(double d);
	Complex operator/(double d);
	Complex operator-();
};
// ================================================================
// Complex‚Ì‰ÁZ
// ================================================================
Complex Complex::operator+(Complex o)
{
	Complex temp;
	temp.real = real + o.real;
	temp.imag = imag + o.imag;
	return temp;
}

// Complex‚Ædouble‚Ì‰‰Z
Complex Complex::operator+(double d)
{
	Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}

// ================================================================
// Complex‚ÌŒ¸Z
// ================================================================
Complex Complex::operator-(Complex o)
{
	Complex temp;
	temp.real = real - o.real;
	temp.imag = imag - o.imag;
	return temp;
}

// Complex‚Ædouble‚Ì‰‰Z
Complex Complex::operator-(double d)
{
	Complex temp;
	temp.real = real - d;
	temp.imag = imag;
	return temp;
}

// ’P€‰‰Zq
Complex Complex::operator-()
{
	Complex temp;
	temp.real = -real;
	temp.imag = -imag;
	return temp;
}

// ================================================================
// Complex‚ÌæZ
// ================================================================
Complex Complex::operator*(Complex o)
{
	Complex temp;
	temp.real = (real * o.real) - (imag * o.imag);
	temp.imag = (o.real * imag) + (real * o.imag);
	return temp;
}

// Complex‚Ædouble‚Ì‰‰Z
Complex Complex::operator*(double d)
{
	Complex temp;
	temp.real = real * d;
	temp.imag = d * imag;
	return temp;
}

// ================================================================
// Complex‚ÌœZ
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

// Complex‚Ædouble‚Ì‰‰Z
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
// ƒƒCƒ“ŠÖ”
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
