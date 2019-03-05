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

long mod_pow(ll a, int p){
  if(p == 0) return 1;
  if(p % 2 == 0){
    int half_p = p / 2;
    long half = mod_pow(a, half_p);
    return half * half % MOD;
  }else{
    return a * mod_pow(a, p-1) % MOD;
  }
}


int main(){
  cout << mod_pow(2, 10) << endl;
}
