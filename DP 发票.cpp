#include<bits/stdc++.h>

using namespace std;

/*
允许报销的发票类型包括买ABC，其他类型不允许报销。
每张发票的总额不得超过1000元，超过1000元的发票不报销。
每张发票上，单项物品的价值不得超过600元，超过600元的物品不报销。
【本质是一个处理数据后的0-1背包问题】
*/

vector<double> validInvoices;  // 存储有效发票的总金额

// 动态规划函数，解决0-1背包问题
double knapsack(int numInvoices, double maxAmount) {
    // dp[i]表示容量为i时，背包中能装入的最大总金额
    if (numInvoices == 0) return 0; // 边界条件：没有物品，价值为0

    // 当前物品的价值是validInvoices[numInvoices - 1]
    if (maxAmount >= validInvoices[numInvoices - 1]) {
        // 能装下当前物品，选择是否装入当前物品
        return max(validInvoices[numInvoices - 1] + knapsack(numInvoices - 1, maxAmount - validInvoices[numInvoices - 1]),
                   knapsack(numInvoices - 1, maxAmount));
    } else {
        // 当前物品无法装入背包
        return knapsack(numInvoices - 1, maxAmount);
    }
}

int main() {
    double maxAmount;  // 最大可报销额度
    int numInvoices;   // 发票数量

    while (cin >> maxAmount >> numInvoices) {
        if (numInvoices == 0) break;  // 结束条件：没有发票

        // 处理所有发票
        while (numInvoices--) {
            int numItems;  // 发票中物品的数量
            cin >> numItems;

            double totalAmount = 0;  // 当前发票的总金额
            bool isValidInvoice = true;  // 标记发票是否有效

            while (numItems--) {
                string item;  // 当前物品描述
                cin >> item;

                char itemType = item[0];  // 物品类型（A/B/C）
                string itemPriceStr = item.substr(2);  // 物品价格

                // 判断物品类型是否符合要求
                if (itemType != 'A' && itemType != 'B' && itemType != 'C') {
                    isValidInvoice = false;  // 含有不符合报销的物品，标记为无效发票
                    break;
                }

                stringstream ss(itemPriceStr);
                double itemPrice;
                ss >> itemPrice;  // 将物品价格转换为数字

                // 判断物品价格是否符合报销要求
                if (itemPrice > 600) {
                    isValidInvoice = false;  // 单项物品价格超过600元，标记为无效发票
                    break;
                }

                totalAmount += itemPrice;  // 累加当前物品价格
            }

            // 如果发票有效且符合最大金额限制，则将其加入有效发票列表
            if (totalAmount <= 1000 && isValidInvoice && totalAmount <= maxAmount) {
                validInvoices.push_back(totalAmount);
            }
        }

        // 计算背包问题的结果：最大可报销金额
        double result = knapsack(validInvoices.size(), maxAmount);
        if (validInvoices.size() == 0) result = 0;  // 如果没有有效发票，结果为0

        // 输出结果，保留两位小数
        cout << fixed << setprecision(2) << result << '\n';

        validInvoices.clear();  // 清空有效发票列表，为下次输入做准备
    }

    return 0;
}
