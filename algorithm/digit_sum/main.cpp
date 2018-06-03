#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;


int main()
{
  int n;
  cin >> n;
  int tmp = log10(n);
  int res = 0;
  for (int i = tmp; i > 0; i--)
  {
    res += n / (pow(10, i));
    n -= ((n / int((pow(10, i)))) * pow(10, i));
  }
  res += n;
  cout << res << endl;
  return 0;
}
