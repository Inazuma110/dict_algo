#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

vector<vector<int>> dp(4000, vector<int>(4000, 0));
// 左上1、左2、上3
vector<vector<int>> from(4000, vector<int>(4000, 0));


int lcs_size(string s1, string s2){
  int n1 = int(s1.size());
  int n2 = int(s2.size());
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if(s1[i-1] == s2[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
        from[i][j] = 1;
        continue;
      }
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      from[i][j] = (dp[i][j] == dp[i-1][j]) ? 3 : 2;
    }
  }
  return dp[n1][n2];
}


string lcs(string s1, string s2){
  string res = "";
  int n1 = int(s1.size());
  int n2 = int(s2.size());
  int x = lcs_size(s1, s2);
  while(x > 0){
    if(from[n1][n2] == 1){
      res += s1[n1-1];
      n1--; n2--; x--;
    }else if(from[n1][n2] == 2) n2--;
    else n1--;
  }

  reverse(res.begin(), res.end());
  return res;
}

int main(){
  string s, t;
  cin >> s >> t;
  cout << lcs(s, t) << endl;
}
