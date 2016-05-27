#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 给定子串，计算部分匹配表
vector<int> next(const string &pattern) {
    vector<int> lps(pattern.size());
    int index = 0;
    lps[index] = 0;
    for(int i = 1; i < pattern.size();) {
        if (pattern[index] == pattern[i]) {
            lps[i] = index + 1;
            ++index;
            ++i;
        } else {
            if (index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

bool KMP(const string &text, const string &pattern) {
    vector<int> lps = next(pattern);
    int i = 0, j = 0;
    while (i < text.length() && j < pattern.length()) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    if (j == pattern.size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
//    const string pattern = "aabaabaaa";
    const string pattern = "abcdabca"; // 模式串
//    vector<int> lps = next(pattern);
//    vector<int>::const_iterator it = lps.cbegin();
//    while (it != lps.cend()) {
//        cout << *it++ << endl;
//    }
    cout << KMP("abcdabca", "da") << endl;

    return 0;
}
