#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;

const int h = 1, w = 1;
vector<vector<int>> dp(h+1,vector<int>(w+1, 0));

// その地点からゴールまでたどるルートｈいくつあるか
int dfs(int nh, int nw)
{
  if(nh > h || nw > w) return 0;
  if(nh == h && nw == w) return 1;
  if(dp[nh][nw] != 0) return dp[nh][nw];
  else return dp[nh][nw] = dfs(nh+1, nw) + dfs(nh, nw+1);
}

int main()
{
  cout << dfs(0, 0) << endl;
  return 0;
}
