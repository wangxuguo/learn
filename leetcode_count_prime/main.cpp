#include <iostream>
#include <vector>

using namespace std;

// �����Ĵ���淶û��Ҫ�м�ӿո� main()
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

    // ��4��ʼ��2������
    for (int i = 4; i < n; i += 2) {
        Del[i] = false;
    }

    // �����Ѿ�ɸѡ�����е�ż���������������ʹ�� i += 2
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
