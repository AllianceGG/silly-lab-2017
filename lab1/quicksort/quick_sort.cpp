#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

int partition(int* lst, int left, int right)
{
    int pivot = lst[right];
    int wall = left;
    // for every num expect the pivot itself
    for (int cur = left; cur < right; ++cur)
        // if the num < pivot
        if (lst[cur] < pivot)
        {
            // swap with "wall"
            int tmp = lst[wall];
            lst[wall] = lst[cur];
            lst[cur] = tmp;
            ++wall;
        }
    // finally put "wall" in the middle
    lst[right] = lst[wall];
    lst[wall] = pivot;
    return wall;
}

void quicksort(int* lst, int left, int right)
{
    if (left < right)
    {
        int wall = partition(lst, left, right);
        quicksort(lst, left, wall - 1);
        quicksort(lst, wall + 1, right);
    }
}

int lst[1500000];
int main()
{
    ifstream infile("raw_data");
    int i = 0;
    while (infile >> lst[i++]);
    --i; // redundant addition in the last round of EOF

    time_t t1 = clock();
    quicksort(lst, 0, i-1);
    cout << "time elapsed: " << (double)(clock() - t1)/CLOCKS_PER_SEC << "s" << endl;

    //output sorted array
    //for (int ii = 0; ii < i; ++ii) cout << lst[ii] << endl;

    infile.close();
    return 0;
}

