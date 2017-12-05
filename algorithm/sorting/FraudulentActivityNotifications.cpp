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

    cout << "d: " << d << endl;

    int count[MAXAMOUNT];
    int currentTransactions[d];

    // Initial / i == d case.
    for (int i = 0; i < MAXAMOUNT; i++)
      count[i] = 0;

    for (int j = 1; j <= d; j++)
      count[(expenditure[d-j])]++;

    for (int j = 1; j < MAXAMOUNT; j++)
      count[j] += count[j-1];

    for (int i = 0; i < 10; i++)
      cout << "count[" << i << "]: " << count[i] << endl;

    //for (int j = 1; j <= d; j++) {
      //currentTransactions[count[(expenditure[d-j])] - 1] = expenditure[d-j];
      //count[(expenditure[d-j])]--;
    //}

    // For each expenditure starting at d + 1, determine if we've got a notification.
    int notifications = 0;
    int medianItem;
    bool useOnlyMedianItem = d % 2;
    if (useOnlyMedianItem)
      medianItem = d / 2 + 1;
    else
      medianItem = d / 2; 

    cout << "medianItem: " << medianItem << endl;
    for (int i = d; i < expenditure.size(); i++) {
//        vector<int> currentTransactions;
//
//        for (int j = 1; j <= d; j++) { 
//          currentTransactions.push_back(expenditure[i-j]);
//        }
//
//        BucketSort(currentTransactions);

        // Counting Sort
        if (i != d) {
           // Suggestion is to remove the old value from count and add the new value.
           count[expenditure[i - d - 1]]--;
           count[expenditure[i]]++;          

           for (int i = 0; i < 10; i++)
             cout << "count[" << i << "]: " << count[i] << endl;

           // Can we just remove the old value and put expenditure[i - 1] in the right place?
           //for (int j = 1; j <= d; j++) {
              //currentTransactions[count[(expenditure[i-j])] - 1] = expenditure[i-j];
              //count[(expenditure[i-j])]--;
           //}
        }

        float medianValue = 0;
        if (useOnlyMedianItem) {
          for (int i = 0; i < MAXAMOUNT; i++) {
            if (count[i] > medianItem) {
              medianValue = i;
              break;
            }
          }
          cout << "medianValue: " << medianValue << endl;
        }
        else {
          float a, b;

          a = b = -1;

          for (int i = 0; i < MAXAMOUNT; i++) {
            if ((count[i] > medianItem) && (a == -1))
              a = i;
            else if (count[i] > (medianItem + 1))
              b = i;
            
            if (a != -1 && b != -1)
              break;
          }

          medianValue = (a + b) / 2;
          cout << "medianValue: " << medianValue << endl;
        }

        if (expenditure[i] >= (int)(medianValue * 2)) {
          cout << "Incremented Notifications" << endl;
          notifications++;
        }
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
