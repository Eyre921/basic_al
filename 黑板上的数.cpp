#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    // 计算总和并将每个字符转换为数字存入数组
    vector<int> eachnum;
    int sum = 0;
    for (char ch : s) {
        int digit = ch - '0';
        eachnum.push_back(digit);
        sum += digit;
    }

    // 如果总和已经满足条件，直接输出 0
    if (sum >= k) {//important
        cout << 0;
        return 0;
    }

    // 否则，按升序排序每个数字，进行最小修改
    sort(eachnum.begin(), eachnum.end());

    int changes = 0;
    k -= sum;  // 减去已有的和

    // 从最小的数字开始修改，直到和 >= k
    for (int i = 0; i < eachnum.size() && k > 0; ++i) {
        k -= (9 - eachnum[i]);  // 每次将该数字变为 9
        changes++;
    }

    cout << changes;
    return 0;
}
