#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // int nums_1[] = {2, 7, 4, 5, 7, 1, 5};
    int nums_1[] = {3, 2, 4};
    int target = 6;

    // 使用数组初始化vector对象
    vector<int> nums_2(begin(nums_1), end(nums_1));

    sort(nums_2.begin(), nums_2.end());

    // 思路来自快排
    // 当你第一次使用变量时再定义它
    int l = 0, r = nums_2.size() - 1;
    while (l < r)
    {
        if (nums_2[l] + nums_2[r] == target)
            break;
        else if (nums_2[l] + nums_2[r] > target)
            --r;
        else
            ++l;
    }

    vector<int> index;
    for (int i = 0, n = 2; i < nums_2.size(); ++i)
        if (nums_2[l] == nums_1[i] || nums_2[r] == nums_1[i])
        {
            index.push_back(i);
            if (--n == 0)
                break;
        }

    cout << index[0] << " " << index[1] << endl;

    return 0;
}
