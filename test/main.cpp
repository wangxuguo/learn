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

    // ����ɼ�С��60����Ӧ����ĸ��F������������±�
    string letterGrade;
//    if (grade < 60)
//        letterGrade = scores[0];
//    else
//    {
//        if (grade != 100)               // ��������100�ĳɼ�
//        {
//            letterGrade = scores[(grade - 50) / 10];
//            if (grade % 10 > 7)
//                letterGrade += '+';     // ĩβ��8��9�ĳɼ����һ���Ӻ�
//            else if (grade % 10 < 3)
//                letterGrade += '-';     // ĩβ��0,1��2�ĳɼ����һ������
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
