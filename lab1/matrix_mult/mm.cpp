#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    const int X = 80, Y = 90, Z = 100;
    int a[X][Y], b[Y][Z], c[X][Z] = {};
    ifstream ain("a_raw"), bin("b_raw");
    for (int x = 0; x < X; ++x)
        for (int y = 0; y < Y; ++y)
            ain >> a[x][y];

    for (int y = 0; y < Y; ++y)
        for (int z = 0; z < Z; ++z)
            bin >> b[y][z];

    time_t t1 = clock();
    for (int x = 0; x < X; ++x)
        for (int z = 0; z < Z; ++z)
            for (int y = 0; y < Y; ++y)
                c[x][z] += a[x][y] * b[y][z];
    cout << "time elapsed: " << (double)(clock() - t1)/CLOCKS_PER_SEC << "s" << endl;

    /* output result
    for (int x = 0; x < X; ++x)
    {
        for (int z = 0; z < Z; ++z)
            cout << c[x][z] << " ";
        cout << endl;
    }
    */
    ain.close();
    bin.close();

    return 0;
}

