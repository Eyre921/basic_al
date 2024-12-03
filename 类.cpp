//有理数类的定义与实现，模拟表示分数对象
#include <iostream>
using namespace std;

//类的定义
class Rational {
	private:
		int fz;
		int fm;
	public:
		void show();
		void set();
		Rational();
};

//类的方法定义
void Rational::show() {
	cout << fz << '/' << fm << endl;
}
void Rational::set() {
	cin >> fz >> fm;
}
Rational::Rational()
{
	fm = 1, fz = 0;
}

//创建对象，测试功能
int main() {
	Rational r; //声明有理数对象，自动调用无参构造函数
	r.set();
	r.show();  	//调用该对象的public方法


	return 0;
}