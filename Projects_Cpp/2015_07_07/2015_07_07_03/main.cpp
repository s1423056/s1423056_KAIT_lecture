// –â3@‰‰ZqƒI[ƒo[ƒ[ƒh‚ÌŠg’£2

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
// Complex‚ÌŒ¸Z
// ================================================================
Complex Complex::operator-( Complex o )
{
	Complex temp;
	temp.real = real - o.real;
	temp.imag = imag - o.imag;
	return temp;
}

// Complex‚Ædouble‚Ì‰‰Z
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
Complex Complex::operator*( Complex o )
{
	Complex temp;
	temp.real = (real * o.real) - (imag * o.imag);
	temp.imag = (o.real * imag) + (real * o.imag);
	return temp;
}

// Complex‚Ædouble‚Ì‰‰Z
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
// Complex‚ÌœZ	ix1x2+y1y2j+iy1x2-x1y2j
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

// Complex‚Ædouble‚Ì‰‰Z
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