#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A"};

    int grade;
    cout << "Please input your number: " << endl;
    cin >> grade;

    // 如果成绩小于60，对应的字母是F；否则计算其下标
    string letterGrade;
//    if (grade < 60)
//        letterGrade = scores[0];
//    else
//    {
//        if (grade != 100)               // 单独考虑100的成绩
//        {
//            letterGrade = scores[(grade - 50) / 10];
//            if (grade % 10 > 7)
//                letterGrade += '+';     // 末尾是8和9的成绩添加一个加号
//            else if (grade % 10 < 3)
//                letterGrade += '-';     // 末尾是0,1和2的成绩添加一个减号
//        }
//        else
//            letterGrade = "A++";
//    }

    if (grade < 60) {
      letterGrade = scores[0];
    } else {
      if (grade != 100){
        letterGrade = scores[(grade - 50) / 10];
        if (grade % 10 > 7) {
          letterGrade += '+';
        } else if (grade % 10 < 3) {
          letterGrade -= '-';
        }
      } else {
        letterGrade = "A++";
      }
    }

    cout << letterGrade << endl;
    return 0;
}
