//Anshu Dhaka
//25/DA/014
#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, finish;
};

bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

int main()
{
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[20];

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].finish;

    sort(a, a + n, compare);

    cout << "Selected activities:\n";

    int lastFinish = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i].start >= lastFinish)
        {
            cout << "(" << a[i].start << ", " << a[i].finish << ")\n";
            lastFinish = a[i].finish;
        }
    }

    return 0;
}