#include <bits/stdc++.h> // 全部使えるようになるやつ

using namespace std;

int gcd(int a, int b)
{
  while(a != 0)
  {
    int big = max(a, b);
    int small = min(a, b);
    a = big % small;
    b = small;
  }
  return b;
}


int main(){
  cout << gcd(780, 300) << endl;
}
