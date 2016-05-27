#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Please input a number: " << endl;
    cin >> x;

//    if (x == 0)
//    {
//        cout << x << endl;
//        return 0;
//    }
    long long x1 = x;
    bool sign = x1 > 0 ? false : true;
    x1 = x1 > 0 ? x1 : -x1;

    long long ret = 0;
    while (x1 != 0)
    {
        ret = ret * 10 + x1 % 10;
        x1 /= 10;
    }

    if (ret > 2147483647 || (sign == true && ret > 2147483648))
        return 0;
    else
    {
        if (sign == true)
            cout << -ret << endl;
        else
            cout << ret << endl;
    }

    cout << sizeof(int) << endl;

    return 0;
}
