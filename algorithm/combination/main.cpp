#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;

ll comb(int a, int b)
{
  ll res = 1;
  for (int i = a; i > a-b ; i--)
    res *= i;
  for (int i = 1; i <= b; i++)
    res /= i;
  return res;
}

int main()
{
  cout << comb(10,3) << endl;
  return 0;
}
