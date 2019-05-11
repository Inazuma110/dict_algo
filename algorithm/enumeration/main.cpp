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

vector<int> enumeration(ll n){
  vector<int> result;
  for (int i = 1; i <= pow(n, 0.5)+1; i++) {
    if(n % i == 0) result.push_back(i);
  }
  result.push_back(n);
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  print(enumeration(125));
  print(enumeration(12));
}
