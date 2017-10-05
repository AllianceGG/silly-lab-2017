#include <stdio.h>
#include <time.h>

int ack(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (m > 0 && n == 0)
        return ack(m-1, 1);
    if (m > 0 && n > 0)
        return ack(m-1, ack(m, n-1));
}

int main()
{
    time_t t1 = clock();
    printf("ack(3,9) = %d\n", ack(3, 9));
    printf("time elapsed: %lfs\n", (double)(clock() - t1)/CLOCKS_PER_SEC);
    return 0;
}

