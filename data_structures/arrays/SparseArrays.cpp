#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int numStrings;
    cin >> numStrings;

    map<string, int> stringMap;
    for (int i = 0; i < numStrings; i++) {
        string s;
        cin >> s;
        stringMap[s]++;
    }

    int numQueries;
    cin >> numQueries;

    for (int i = 0; i < numQueries; i++) {
        string s;
        cin >> s;
        cout << stringMap[s] << endl;
    }

    return 0;
}
