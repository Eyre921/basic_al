#include <iostream>
using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
    // ���캯��
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
 
    // ��ȡʵ�����鲿
    double getReal() const { return real; }
    double getImag() const { return imag; }
 
    // �����ӷ� 
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
 
    // �������� 
    Complex sub(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
 
    // �����˷�
    Complex mul(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
 
    // ����
    void input() {
        cin >> real >> imag;
    }
 
    // ���
   void output() {
        cout << real << " + " << imag << "i";
   }
};
 
int main() {
    Complex c1, c2, c3;
 
   c1.input();
   c2.input(); 
 
    
    c3 = c1.add(c2);
    cout << "Sum: " ;
    c3.output();
    cout<<endl;
 
    c3 = c1.sub(c2);
    cout << "Difference: " ;
    c3.output();
    cout<<endl;
    
    c3 = c1.mul(c2);
    cout << "Product: ";
    c3.output();
    cout<<endl;
    
    return 0;
}

