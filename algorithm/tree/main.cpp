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

struct Tree {
  int node_num;
  int edgeNum;
  vector<vector<int>> cost;

  void init(){
    return;
  }

};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  Tree t;
  t.edgeNum = n;
  for (int i = 0; i < n; i++) {
    int from, to;
    cin >> from >> to;

  }

}
