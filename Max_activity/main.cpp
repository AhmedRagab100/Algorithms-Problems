#include <bits/stdc++.h>
using namespace std;

// A struct for activity that include info.
struct Activitiy
{
    int start, finish;
};

//function that sort activities according to finish time
bool sort_activity(Activitiy a1, Activitiy a2)
{
    return (a1.finish < a2.finish);
}

// Returns maximum number of activities that can be done
void MaxnumberofActivity(Activitiy arr[], int n)
{
    //sort array of activities
    sort(arr, arr+n,sort_activity);

    cout << "Following activities are selected: ";

    // The first activity always gets selected with lowest finish
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

    for (int j = 1; j < n; j++)
    {
      //select activity that has start time less than finish time of previous one.
      if (arr[j].start >= arr[i].finish)
      {
          cout << "(" << arr[j].start << ", "
              << arr[j].finish << "), ";
          i = j;
      }
    }
}


int main()
{
    Activitiy arr[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};

    int n = sizeof(arr)/sizeof(arr[0]);

    MaxnumberofActivity(arr, n);
    return 0;
}
