#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangle(vector<int> a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] + a[i + 1] > a[i + 2])
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    cout << "Enter array to check for triplets: ";
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    cout << triangle(a) << "\n";
}