#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

vector<ll> enumeration(ll n){
  vector<ll> result;
  for (ll i = 1; i*i <= n; i++) {
    if(n % i == 0){
      result.push_back(i);
      result.push_back(n / i);
    }
  }
  sort(ALL(result));
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  print(enumeration(125));
  print(enumeration(12));
}
