#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        string display;
        cin >> display;

        // 如果显示的里程表数字为0，真实里程也是0
        if (display == "0")
        {
            cout << "0\n";
            continue;
        }

        long long realMileage = 0; // 真实行驶里程

        for (char c: display)
        {
            int mapped_digit;
            // 根据显示数字进行映射
            if (c >= '0' && c <= '9')
            {
                if (c >= '0' && c <= '2')
                {
                    mapped_digit = c - '0'; // 0,1,2 映射为 0,1,2
                } else if (c >= '4' && c <= '7')
                {
                    mapped_digit = (c - '0') - 1; // 4,5,6,7 映射为 3,4,5,6
                } else if (c == '9')
                {
                    mapped_digit = 7; // 9 映射为7
                } else
                {
                    // 里程表上不会出现数字3和8，根据题目描述，这里可以忽略或处理为错误
                    // 这里假设输入一定不包含3和8
                    mapped_digit = 0;
                }
            } else
            {
                // 非法字符处理，根据题目描述不需要
                mapped_digit = 0;
            }

            // 将当前位的数字映射到真实里程
            realMileage = realMileage * 8 + mapped_digit;
        }

        cout << realMileage << '\n';
    }
    return 0;
}
