/*
459、小扇和小船的数字游戏、数字游戏
题目描述
小扇和小船今天又玩起来了数字游戏
小船给小扇一个正整数n(1≤n≤109)，小扇需要找到一个比 n 大的数字 m，使得 m 和 n 对应的二进制中1的个数要相同，如
4对应的二进制为：100，有1个1
8对应的二进制为1000，有1个1
现在求m的最小值

输入描述
输入一个正整数n ( 1 ≤ n ≤ 10^9 )

输出描述
输出一个正整数m

样例1
输入
2
输出
4
说明
2的二进制10，4的二进制位100，
1的个数相同，且4是满足条件的最小数

样例2
输入
7
输出
11
说明
7的二进制111
11的二进制位1011
1的个数相同，且11是满足条件的最小数

找到1个数一样的稍大值，则从后往前寻找第一对01改变为10，并将其后的所有1放在最后。
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;  // 输入一个整数 n
    vector<int> w;

    // 将整数 n 转换为二进制表示，存储到向量 w 中
    while (n) {
        w.push_back(n % 2);
        n /= 2;
    }

    w.push_back(0);  // 在向量末尾添加一个前导0

    int m = w.size();  // 获取向量长度

    // 遍历向量，找到第一个01子串，进行交换操作
    for (int i = 0; i < m; i++) {
        if (i + 1 < m && w[i] == 1 && w[i + 1] == 0) {
            swap(w[i], w[i + 1]);  // 使用 swap 函数交换向量中的元素
            int l = 0, r = i - 1;

            // 将低位中的1全部移动到最低位，0移动到最高位，以保证结果尽可能小
            while (l < r) {
                while (l < r && w[l]) {
                    l++;
                }

                while (l < r && w[r] == 0) {
                    r--;
                }

                if (l < r) {
                    swap(w[l], w[r]);  // 使用 swap 函数交换向量中的元素
                    l++;
                    r--;
                }
            }

            break;  // 跳出循环
        }
    }

    int res = 0;

    // 将二进制向量转换为十进制数
    for (int i = 0; i < m; i++) {
        if (w[i]) {
            res += 1 << i;
        }
    }

    cout << res << endl;  // 输出结果
    return 0;
}


