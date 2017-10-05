import time
a = []
b = []
c = []
X = 80
Y = 90
Z = 100

with open("a_raw", 'r') as f:
    for l in f:
        a.append(list(map(int, l.split())))

with open("b_raw", 'r') as f:
    for l in f:
        b.append(list(map(int, l.split())))

for x in range(X):
    c.append([0] * Z)

t1 = time.time()
for x in range(X):
    for z in range(Z):
        for y in range(Y):
            c[x][z] += a[x][y] * b[y][z];
print("time elapsed: ", time.time() - t1, "s")
