#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // 构造函数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 获取实部和虚部
    double getReal() const { return real; }
    double getImag() const { return imag; }

    friend Complex operator+(const Complex &b, const Complex &a)
    {
        return Complex(a.real + b.real, a.imag + b.imag);
    }

    friend Complex operator-(const Complex &a, const Complex &b)
    {
        return Complex(a.real - b.real, a.imag - b.imag);
    }

    // 复数加法
    Complex add(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // 复数减法
    Complex sub(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    friend Complex operator*(const Complex &a, const Complex &b)
    {
        return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
    }

    // 复数乘法
    Complex mul(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    friend istream &operator>>(istream &is, Complex &c)
    {
        is >> c.real >> c.imag;
        return is;
    }

    friend ostream &operator<<(ostream &is, Complex &c)
    {
        is << c.real << " + " << c.imag << "i";
        return is;
    }

    // 输入
    void input()
    {
        cin >> real >> imag;
    }

    // 输出
    void output()
    {
        cout << real << " + " << imag << "i";
    }
};

int main()
{
    Complex c1, c2, c3, c4;


    c1.input();
    c2.input();


    c3 = c1 + c2;
    cout << "Sum: ";
    c3.output();
    cout << endl;

    c3 = c1 - c2;
    cout << "Difference: ";
    c3.output();
    cout << endl;

    c3 = c1 * c2;
    cout << "Product: ";
    c3.output();
    cout << endl;

    cin >> c4;
    cout << c4;
    return 0;
}

