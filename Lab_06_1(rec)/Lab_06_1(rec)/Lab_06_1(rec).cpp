#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* p, const int size, const int Low, const int High, int i)
{
    p[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(p, size, Low, High, i + 1);
}

void Print(int* p, const int size, int i)
{
    cout << setw(4) << p[i];
    if (i < size - 1)
        Print(p, size, i + 1);
    else
        cout << endl;
}

int Count(int* p, const int size, int i, int k)
{
    if (!(p[i] % 2 == 0 && i % 13 == 0))
        k++;
    if (i < size - 1)
        return Count(p, size, i + 1, k);
    else
        return k;
}

int Sum(int* p, const int size, int i, int S)
{
    if (!(p[i] % 2 == 0 && i % 13 == 0))
        S += p[i];
    if (i < size - 1)
        return Sum(p, size, i + 1, S);
    else
        return S;
}

void Zero(int* p, const int size, int i)
{
    if (!(p[i] % 2 == 0 && i % 13 == 0))
        p[i] = 0;
    if (i < size - 1)
        Zero(p, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));    

    const int n = 25;               
    int p[n];

    int Low = 15;                   
    int High = 94;

    Create(p, n, Low, High, 0);
    Print(p, n, 0);

    cout << "Count = " << Count(p, n, 0, 0) << endl;
    cout << "Sum   = " << Sum(p, n, 0, 0) << endl;

    Zero(p, n, 0);
    Print(p, n, 0);

    return 0;
}