def fib(n):
  if dp[n] != -1:
    return dp[n]
  else:
    dp[n] = fib(n - 1) + fib(n - 2)
    return dp[n]

dp = []
for i in range(10002):
  dp.append(-1)
dp[0] = 0
dp[1] = 1
n = int(input())
print(fib(n))
