#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;

// 現在地までの着方を計算。数学と同じ感じの計算
const int h = 5, w = 4;
vector<vector<int>> dp(h+1,vector<int>(w+1, 0));

void calc(int nh, int nw) {
  dp[0][0] = 1;
  for (int i = 0; i < h+1; i++)
  {
    for (int j = 0; j < w+1; j++)
    {
      if(i != 0) dp[i][j] += dp[i-1][j];
      if(j != 0) dp[i][j] += dp[i][j-1];
    }
  }

}

int main()
{
  calc(0, 0);
  cout << dp[h][w] << endl;
  return 0;
}
