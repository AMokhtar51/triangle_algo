#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangle(const vector<int>& a,int i)
{
    if(i >= a.size() - 2)
        return 0;

    if(a[i] + a[i+1] > a[i+2])
        return 1;

    return triangle(a, i + 1);
}

int main()
{
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    if(n<3){
        cout << "cannot be a triangle";
    }else{
    cout << "Enter array to check for triplets: ";
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> b = a;
    sort(b.begin(), b.end());
    cout << triangle(b,0) << "\n";
    }
}
