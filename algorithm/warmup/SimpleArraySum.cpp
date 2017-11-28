#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(int n, vector <int> ar) {
    int sum = 0,
        i = 0;
    for (std::vector<int>::iterator it = ar.begin(); i < n && it != ar.end(); ++i, ++it) {
        sum += *it;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = simpleArraySum(n, ar);
    cout << result << endl;
    return 0;
}
