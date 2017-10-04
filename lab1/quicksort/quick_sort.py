import time

def partition(lst, left, right):
    pivot = lst[right]
    wall = left
    for cur in range(left, right):
        if lst[cur] < pivot:
            lst[wall], lst[cur] = lst[cur], lst[wall]
            wall += 1
    lst[wall], lst[right] = pivot, lst[wall]
    return wall

def quicksort(lst, left, right):
    if (left < right):
        wall = partition(lst, left, right)
        quicksort(lst, left, wall - 1)
        quicksort(lst, wall + 1, right)

lst = []
with open("raw_data", 'r') as f:
    for n in f:
        lst.append(int(n))
t1 = time.time()
quicksort(lst, 0, len(lst)-1)
print("time elapsed: ", time.time() - t1, "s")
#print(lst)
