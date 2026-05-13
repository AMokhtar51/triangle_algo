#include <iostream>
#include <vector>
using namespace std;

void mergee(vector<int> &A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        mergeSort(A, p, q);

        mergeSort(A, q + 1, r);

        mergee(A, p, q, r);
    }
}

int triangle(const vector<int> &A, int i)
{
    if (i >= A.size() - 2)
        return 0;

    if (A[i] + A[i + 1] > A[i + 2])
        return 1;

    return triangle(A, i + 1);
}

int main()
{
    int n;
    cout << "Enter size of the array: " << endl;
    cin >> n;
    if (n < 3)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << "Enter array to check for triplets: " << endl;

    vector<int> A(n);

    for (int &x : A)
        cin >> x;

    vector<int> B = A;

    mergeSort(B, 0, n - 1);

    cout << triangle(B, 0) << endl;

    return 0;
}
