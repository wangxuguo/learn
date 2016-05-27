#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    std::cout << "Please input a string: " << std::endl;
//    std::cin >> s;
    std::getline(std::cin, s);

// ʹ�÷�Χfor���ı��ַ����е��ַ�
//    for (auto &c : s)
//        c = tolower(c);

    // ʹ���±�ִ�е���
    for (decltype(s.size()) index = 0; index != s.size(); ++index)
        s[index] = tolower(s[index]);
    std::cout << s << std::endl;

    //    std::string::size_type left = 0, right = s.size();
    bool sign = true;
    std::string::iterator left = s.begin(), right = s.end();
    while (left < right)
        if (!isalnum(*left))
            ++left;
        else if (!isalnum(*right))
            --right;
        else if (*left != *right)
        {
            sign = false;
            break;
        }
        else
        {
            ++left;
            --right;
        }

    if (sign == false)
        std::cout << "false" << std::endl;
    else
        std::cout << "true" << std::endl;
}
