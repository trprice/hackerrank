#include <bits/stdc++.h>

using namespace std;

int activityNotifications(vector <int> expenditure, int d) {
    // If we don't have at least d + 1 days of expenditures,
    // return 0 because there can't be any notifications.
    if (expenditure.size() <= d)
      return 0;

    // For each expenditure starting at d + 1, determine if we've got a notification.
    int notifications = 0;
    int medianItem = (expenditure.size() - 1) / 2;
    bool useOnlyMedianItem = d % 2;
    for (int i = d; i < expenditure.size(); d++) {
        multiset<int> currentTransactions;
        
        for (int j = 1; j <= d; j++) { 
          currentTransactions.emplace(expenditure[i-j]);
        }

        int medianValue = 0;
        multiset<int>::iterator it = currentTransactions.begin();

        for (int j = 0; j < medianItem; j++) {
          it++;
        }
        if (useOnlyMedianItem) {
          ++it;
          medianValue = *it;
        }
        else {
          medianValue += *it;

          ++it;
          medianValue += *it;

          medianValue /= 2;
        }

        if (expenditure[i] >= (medianValue * 2))
          notifications++;
    }

    return notifications;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
       cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}
