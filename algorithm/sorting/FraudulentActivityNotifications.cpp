#include <bits/stdc++.h>

using namespace std;

#define MAXAMOUNT 200

void BucketSort(vector<int> &currentTransactions) {
    // Bucket sort
    int buckets[MAXAMOUNT];

    // Initialize buckets
    for (int j = 0; j < MAXAMOUNT; j++)
      buckets[j] = 0;

    // Sort into buckets
    for (int j = 0; j < currentTransactions.size(); j++)
      buckets[currentTransactions[j]]++;
    
    // Sort back into currentTransactions
    int j, k, l;
    l = 0;
    for (j = 0; j < MAXAMOUNT; j++)
      for (k = buckets[j]; k > 0; k--)
        currentTransactions[l++] = j; 
}

int activityNotifications(vector <int> expenditure, int d) {
    // If we don't have at least d + 1 days of expenditures,
    // return 0 because there can't be any notifications.
    if (expenditure.size() <= d)
      return 0;

    int count[MAXAMOUNT];


    // For each expenditure starting at d + 1, determine if we've got a notification.
    int notifications = 0;
    int medianItem = (d - 1) / 2;
    bool useOnlyMedianItem = d % 2;
    for (int i = d; i < expenditure.size(); i++) {
//        vector<int> currentTransactions;
//
//        for (int j = 1; j <= d; j++) { 
//          currentTransactions.push_back(expenditure[i-j]);
//        }
//
//        BucketSort(currentTransactions);

        // Counting Sort
        for (int i = 0; i < MAXAMOUNT; i++)
          count[i] = 0;

        for (int j = 1; j <= d; j++) {
          count[(expenditure[i-j])]++;
          cout << "expenditure[i-j]: " << expenditure[i-j] << " count[(expenditure[i-j])]: " << count[(expenditure[i-j])] << endl;
        }

        for (int j = 1; j < MAXAMOUNT; j++)
          count[j] += count[j-1];

        int currentTransactions[d];
        for (int j = 1; j <= d; j++) {
          currentTransactions[count[(expenditure[i-j])] - 1] = expenditure[i-j];
          count[(expenditure[i-j])]--;
        }

        float medianValue = 0;
        if (useOnlyMedianItem) {
          medianValue = currentTransactions[medianItem];
        }
        else {
          float a = currentTransactions[medianItem];
          float b = currentTransactions[medianItem+1];

          medianValue = (a + b) / 2;
        }

        if (expenditure[i] >= (int)(medianValue * 2))
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
