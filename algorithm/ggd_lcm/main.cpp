#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int
typedef long long ll;
typedef pair<ll,ll> p;

ll ggd(ll number1, ll number2){
  ll m = number1;
  ll n = number2;
  
  if(number2 > number1){
    m = number2;
    n = number1;
  }
  
  while(m != n){
    if(m < n)
    {
      ll x = m;
      m = n;
      n =x;
    }
    ll temp = n;
    n = m - n;
    m = temp;
  }
  
  return m;
}

ll lcm(ll number1, ll number2){
  return number1 * number2 / ggd(number1,number2);	
}

int main(){
  int a, b;
  cin >> a >> b;
  cout << ggd(a, b) << endl;
  cout << lcm(a, b) << endl;
}
