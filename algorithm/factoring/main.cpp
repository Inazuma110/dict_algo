#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;

vector<pair<ll, int>> factoring(ll a){
  vector<pair<ll, int>> v;
  for (int i = 2; i <= a; i++) {
    if(a % i == 0){
      int count = 0;
      while(a % i == 0){
        count++;
        a /= i;
      }
      v.push_back({i, count});
    }
  }
  return v;
}

int main(){
  // print(factoring(125));
  // print(factoring(12));
}
