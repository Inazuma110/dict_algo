import numpy as np
fib = np.expand_dims(np.array([0, 1]), 0)
x = np.array([
    [1, 1],
    [1, 2],
])

n = 50
for i in range(n):
    print(fib)
    fib = fib @ x

fib = np.ndarray.flatten(fib)
print(fib[0]) # n * 2 項目
print(fib[1]) # n * 2 + 1 項目rint(fib[1]) # n * 2 + 1 項目
