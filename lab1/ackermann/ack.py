import sys
import time

# "deep" recursion
sys.setrecursionlimit(5000)

def ack(m, n):
    if m == 0:
        return n + 1
    if m > 0 and n == 0:
        return ack(m-1, 1)
    if m > 0 and n > 0:
        return ack(m-1, ack(m, n-1))

t1 = time.time()
print("ack(3, 9) = ", ack(3, 9))
print("time elapsed: ", time.time() - t1, "s")
