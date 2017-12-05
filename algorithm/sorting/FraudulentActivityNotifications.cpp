#include <bits/stdc++.h>

using namespace std;

#define MAXEXPAMOUNT 200

int activityNotifications(vector <int> expenditure, int d) {
    // If we don't have at least d + 1 days of expenditures,
    // return 0 because there can't be any notifications.
    if (expenditure.size() <= d)
      return 0;

    // For each expenditure starting at d + 1, determine if we've got a notification.
    int notifications = 0;
    int medianItem = d / 2;
    bool useOnlyMedianItem = d % 2;
    int dPriorDays[MAXEXPAMOUNT];

    // Count Sort Step #0 -- Initialize
    for (int i = 0; i < MAXEXPAMOUNT; i++)
      dPriorDays[i] = 0;

    // Count Sort Step #1 -- Track Items
    for (int i = 0; i < d; i++)
      dPriorDays[expenditure[i]]++;

    int oldIndex = 0;
    for (int i = d; i < expenditure.size(); i++) {
        float medianValue = 0;
        int currentValue = expenditure[i];

        // Count Sort Step #2 -- Compute Index
        int indexArray[MAXEXPAMOUNT];
        int sum = 0;
        for (int j = 0; j < MAXEXPAMOUNT; j++) {
          sum += dPriorDays[j];
          indexArray[j] = sum;
        }

        
        if (useOnlyMedianItem) {
          for (int j = 0; j < MAXEXPAMOUNT; j++) {
            if (indexArray[j] > medianItem) {
              medianValue = j;
              break;
            }
          }
        }
        else {
          float a = -1,
                b = -1;

          for (int j = 0; j < MAXEXPAMOUNT; j++) {
            if (indexArray[j] > medianItem - 1) {
              a = j;
              break;
            }
          }

          for (int j = 0; j < MAXEXPAMOUNT; j++) {
            if (indexArray[j] > medianItem) {
              b = j;
              break;
            }
          }

          medianValue = (a + b) / 2;
        }

        if (currentValue >= (int)(medianValue * 2))
          notifications++;
       
        // Count Sort Step #1.5 -- Update the days we're keeping track of 
        int oldValue = expenditure[oldIndex++];
        dPriorDays[oldValue]--;
        dPriorDays[currentValue]++;
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
