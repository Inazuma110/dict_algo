#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;

long double logn(int base, int tv)
{
  return log(tv) / log(base);
}


int main()
{
  cout << logn(2, 17) << endl;
}
