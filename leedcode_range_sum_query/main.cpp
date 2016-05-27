#include <iostream>
#include <vector>

//using namespace std;

class NumArray {
public:
    std::vector<int> nums_;
    NumArray(std::vector<int> &num) {
        nums_.push_back(0);
        for (auto it = num.begin(); it != num.end(); ++it) {
            nums_.push_back(nums_.back() + *it);
        }
    }
};
int main() {
    std::vector<int> num1 = {1, 2, 3, 4, 5};
    NumArray numarray(num1);
    for(auto it = numarray.nums_.begin(); it != numarray.nums_.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
