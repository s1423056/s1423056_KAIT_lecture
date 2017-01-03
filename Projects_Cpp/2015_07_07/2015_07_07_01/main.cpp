// ��1�@2�����Z�q�̃I�[�o�[���[�h

#include <iostream>
using namespace std;

class Complex {
	double real; // ������
	double imag; // ������
public:
	Complex(double x=0, double y=0) { real = x; imag = y; }
	double getReal() { return real; } // �g�p���Ȃ�
	double getImag() { return imag; } // �g�p���Ȃ�
	void show(char *str) {
		cout << str << "(" << real << ", " << imag << ")\n";
	}
	Complex operator+(Complex o);
	Complex operator-(Complex o);
	Complex operator*(Complex o);
	Complex operator/(Complex o);
};
// ================================================================
// Complex�̉��Z
// ================================================================
Complex Complex::operator+(Complex o)
{
	Complex temp;
	temp.real = real + o.real;
	temp.imag = imag + o.imag;
	return temp;
}

// ================================================================
// Complex�̌��Z
// ================================================================
Complex Complex::operator-(Complex o)
{
	Complex temp;
	temp.real = real - o.real;
	temp.imag = imag - o.imag;
	return temp;
}

// ================================================================
// Complex�̏�Z
// ================================================================
Complex Complex::operator*(Complex o)
{
	Complex temp;
	temp.real = (real * o.real) - (imag * o.imag);
	temp.imag = (o.real * imag) + (real * o.imag);
	return temp;
}

// ================================================================
// Complex�̏��Z
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

// ================================================================
// ���C���֐�
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
	return 0;
}