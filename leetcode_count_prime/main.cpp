#include <iostream>
#include <vector>

using namespace std;

// 函数的代码规范没必要中间加空格 main()
int main() {
    int n;
    cout << "Please input a number: " << endl;
    cin >> n;

    int count = 0;
    if (n == 0 || n == 1 || n == 2) {
        cout << count << endl;
        return 0;
    }

    vector<bool> Del(n, true);

    // 从4开始，2是质数
    for (int i = 4; i < n; i += 2) {
        Del[i] = false;
    }

    // 上面已经筛选了所有的偶数，所以下面可以使用 i += 2
    for (int i = 3; i < n; i += 2) {
        if (Del[i]) {
            if (i * i > n)
                break;
            for (int j = 3; i * j < n; j += 2)
                Del[i * j] = false;
        }
    }

    for (int i = 2; i < n; ++i) {
        if (Del[i]) {
            ++count;
            cout << i << endl;
        }
    }

    cout << count << endl;

    return 0;
}
