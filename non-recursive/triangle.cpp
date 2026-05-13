#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int triangle(vector<int> a)
{
    int n = a.size();
    insertionSort(a);
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
    if (n < 3)
        cout << "Cannot be a triangle." << endl;
    else
    {
        cout << "Enter array to check for triplets: ";
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        cout << triangle(a) << "\n";
    }
}