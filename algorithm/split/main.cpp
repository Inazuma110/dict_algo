#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn long long

typedef long long ll;
typedef pair<ll,ll> p;

vector<string> split(string s, string sep)
{
  vector<string> v;
  int strNum = int(sep.size());
  int sepIndex;
  // findで見つからなかった場合string::nposが返る。
  while(sepIndex != int(string::npos))
  {
    sepIndex = s.find(sep);
    v.push_back(s.substr(0, sepIndex));
    s = s.substr(sepIndex + strNum);
  }
  return v;
}

int main()
{
  // string s = "I am Inazuma";
  // vector<string> v = split(s, "am");
  // for(string s : v) cout << s << endl;
}
