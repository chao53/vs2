#include <iostream>
//#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int myFunc(int* p, int n) {
    int a[50000] = { 0 };
    for (int i = 0;i < n;i++) {
        a[p[i]]++;
    }
    int i3 = 0;
    for (int i1 = 0;i1 < 50000;i1++) {
        if (a[i1] > 0) {
            for (int i2 = 0;i2 < a[i1];i2++, i3++) {
                p[i3] = i1;
            }
        }
    }

    return *p;
}

int main()
{
    int n = 0;
    cin >> n;
    int* p = new int[n];
    int* p2 = new int[n];

    unsigned seed;
    seed = time(0);
    srand(seed);
    for (int i = 0;i < n;i++) {
        p[i] = rand() % 50000;
    }

    for (int i = 0;i < n;i++) {
        cout << p[i] << "\t";
    }

    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    *p2 = myFunc(p, n);

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

    cout << "\n******************************************\n";



    for (int i = 0;i < n;i++) {
        cout << p[i] << "\t";
    }

    cout << "\ntime = " << time << endl;  //输出时间（单位：ｓ）

}
