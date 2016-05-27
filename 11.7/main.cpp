#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void add_family(map<string, vector<string> > &families, const string &family) {
    if (families.find(family) == families.end()) {
        families[family] = vector<string>();
    }
}

void add_child(map<string, vector<string> > &families, const string &family, const string &child) {
    families[family].push_back(child);
}


int main() {
    map<string, vector<string> > families;

    add_family(families, "zhang");
    add_child(families, "zhang", "qiang");
    add_family(families, "wang");
    add_child(families, "wang", "wu");

    for (const auto &f : families) {
        cout << f.first << endl;
        for (const auto &c : f.second) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
