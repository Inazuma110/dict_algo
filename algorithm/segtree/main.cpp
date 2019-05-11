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

int num;
const int SEG_MAXN = 131072;
int dat[SEG_MAXN * 2 - 1];


void seg_init(){
  for (int i = 0; i < 2 * num - 1; i++) {
    dat[i] = INT_MAX;
  }
}

// i番目の値をxに変更
void update(int i, int x){
  // 葉のノードの番号
  i += num - 1;
  dat[i] = x;
  // 登りながら更新
  while(i > 0) {
    dat[i] = min(dat[i * 2  + 1], dat[i * 2 + 2]);
  }
}

// [a, b)の最小値、l, rにはノードkに対応づく区間を与える
int query(int a, int b, int k, int l, int r){
  // 交差するなら
  if(r <= a || b <= l) return INT_MAX;
  // 完全に含むなら
  if(a <= l && r <= b) return dat[k];
  else{
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    return min(vl, vr);
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
}
