#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;


int main()
{
  map<string, int> mp;
  mp["aaa"] = 3;
  mp["as"] = 2;
  cout << mp["aaa"] << endl;

  for(auto i : mp) cout << i.first << endl;
  return 0;
}
