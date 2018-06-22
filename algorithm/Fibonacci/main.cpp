#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int
typedef long long ll;
typedef pair<ll,ll> p;
vector<ll> dp(10000, -1);

ll fib(int n)
{
  if(n == 0) return dp[0];
  else if(n == 1) return dp[1];
  else if(dp[n] != -1) return dp[n];
  else return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
  dp[0] = 0;
  dp[1] = 1;
  int n;
  cin >> n;
  cout << fib(n) << endl;
}
