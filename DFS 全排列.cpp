#include <iostream>
#include <vector>
using namespace std;

int main() {
    int totalNumbers;  // 总的读出数字数量
    cin >> totalNumbers;

    vector<int> numbers(totalNumbers);  // 存储塔雅读出的数字
    for (int i = 0; i < totalNumbers; i++) {
        cin >> numbers[i];
    }

    int stairCount = 1;  // 楼梯的数量，初始化为1，因为至少有一个楼梯
    vector<int> stairSteps;  // 存储每个楼梯的台阶数

    // 遍历数字数组，判断楼梯的分界点
    for (int i = 1; i < totalNumbers; i++) {
        // 如果当前数字小于或等于前一个数字，说明是新楼梯的开始
        if (numbers[i] <= numbers[i - 1]) {
            stairCount++;
            stairSteps.push_back(numbers[i - 1]);  // 记录上一个楼梯的台阶数
        }
    }

    // 最后一个楼梯的台阶数是最后一个数字
    stairSteps.push_back(numbers[totalNumbers - 1]);

    // 输出楼梯的总数量
    cout << stairCount << endl;

    // 输出每个楼梯的台阶数
    for (int steps : stairSteps) {
        cout << steps << " ";
    }

    return 0;
}
