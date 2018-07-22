#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn long long

typedef long long ll;
typedef pair<ll,ll> p;

bool checkInt(string s)
{
  for(int i = 0; i < int(s.size()); i++)
    if(!isdigit(s[i])) return false;
  return true;
}

int main()
{
//  cout << checkInt("23a4") << endl;
}
