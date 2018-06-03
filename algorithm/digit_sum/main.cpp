#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;

ll digitSum(int n)
{
  int tmp = log10(n);
  ll res = 0;
  for (int i = tmp; i > 0; i--)
  {
    res += n / (pow(10, i));
    n -= ((n / int((pow(10, i)))) * pow(10, i));
  }
  res += n;
  return res;
}

int main()
{
  int n;
  cin >> n;
  cout << digitSum(n) << endl;
  return 0;
}
