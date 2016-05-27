#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        auto len = s.size();
        decltype(s.size()) k = 0;
        decltype(s.size()) inter1 = (numRows << 1) - 2;

        string res(len, ' ');

        for (decltype(s.size()) j = 0; j < len; j += inter1)
            res[k++] = s[j];

        for (int i = 1; i < numRows - 1; ++i)
        {
            decltype(s.size()) inter2 = (i << 1);
            for (decltype(s.size()) j = i; j < len; j += inter2)
            {
                res[k++] = s[j];
                inter2 = inter1 - inter2;
            }
        }

        for (decltype(s.size()) j = numRows - 1; j < len; j += inter1)
            res[k++] = s[j];

        return res;
    }
};

int main()
{
    std::string s;
    std::cout << "Please input a string: " << std::endl;
    std::getline(std::cin, s);

    int nRows;
    std::cout << "Please input nRows: " << std::endl;
    std::cin >> nRows;

    Solution solution;
    std::cout << solution.convert(s, nRows) << std::endl;

    // �д�0��ʼ
    // ��һ�к����һ�е��±�������interval = 2 * nRows - 2
    // �м��е��±����������Եģ���i�е��±�����interval - 2 * i, 2 * i
    if (nRows == 1)
    {
        std::cout << s << std::endl;
        return 0;
    }

    int len = s.size(), k = 0, interval = (nRows << 1) - 2;
    std::string res(len, ' ');

    // �����һ��
    for (int i = 0; i < len; i += interval)
        res[k++] = s[i];

    // �����м����
    for (int j = 1; j < nRows - 1; ++j)
    {
        int inter = (j << 1);
        for (int i = j; i < len; i += inter)
        {
            res[k++] = s[i];
            // ��ֵ�����Ա仯
            inter = interval - inter;
        }
    }

    // �������һ��
    for (int i = nRows - 1; i < len; i += interval)
    {
        res[k++] = s[i];
    }

    std::cout << res << std::endl;

    return 0;

}
