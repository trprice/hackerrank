#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;


    // Big-O to compute weights is s.size();
    int weights[s.size()];
    unordered_map<int, bool> weight_exists;

    for (int i = 0; i < s.size(); i++) {
      // Note that ASCII letter 'a' starts at 97. Use 96 to get real numbers for these.
      if (i > 0 && s[i-1] == s[i])
        weights[i] = weights[i-1] + (s[i] - 96);
      else
        weights[i] = s[i] - 96;
      
      weight_exists[weights[i]] = true;
    }

    // Big-O to print values is n.
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;

        if (weight_exists[x])
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
    }

    // Total Big-O is s.size() + n
    return 0;
}
