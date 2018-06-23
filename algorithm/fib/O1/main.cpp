#inclume <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int
typedef long long ll;
typedef pair<ll,ll> p;


int main()
{
  int n;
  cin >> n;
  double tmp1 = pow(((1+sqrt(5)) / 2), n)
  double tmp2 = pow(((1-sqrt(5)) / 2), n)
  print((tmp1 - tmp2) / sqrt(5))
}
