#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> p;

ll res = 1;

ll factorial(int n){
  res *= n;
  if (n > 1) {
    factorial(n-1);
  }else{
    return res;
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  cout << factorial(n) << endl;
  return 0;
}
