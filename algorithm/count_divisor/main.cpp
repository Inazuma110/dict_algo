#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

// O(root(n))
int count_divisor(int n){
  int root = pow(n, 0.5);
  int res = 0;
  for (int i = 1; i <= root+1; i++)
  {
    if(n % i == 0 && n != i) res+=2;
    else if(n % i == 0) res++;
  }
  return res;
}

// map<int, int> mp;
//
// // O(root(n))
// void count_divisor(int n){
//   for (int i = 2; n > 1;)
//   {
//     if(n % i == 0){
//       mp[i]++;
//       n /= i;
//     } else i++;
//   }
// }


int main(){

}
