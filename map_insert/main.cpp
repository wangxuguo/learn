#include <iostream>
#include <map>

int main() {
    std::map<char, int> mymap;

    mymap.insert(std::pair<char, int>('a', 100));
    mymap.insert(std::pair<char, int>('z', 200));

    std::pair<std::map<char, int>::iterator, bool> ret;
    ret = mymap.insert(std::pair<char, int>('z', 500));

    // 如果已经存在，不会覆盖
    if (ret.second == false) {
        std::cout << "a" << "already" << std::endl;
        std::cout << ret.first->second << std::endl;
    }

    return 0;
}
