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
  ll node_num;
  ll edge_num;
  ll diameter = -1;
  ll far_index = -1;
  vector<vector<ll>> to;
  vector<bool> visited;
  vector<int> depth;

  Tree(ll nn) : node_num(nn){
    edge_num = node_num - 1;
    to = vector<vector<ll>> (node_num);
    visited = vector<bool> (node_num, false);
    depth = vector<int> (node_num);
  }


  pair<ll, ll> get_far(ll from, ll d){
    visited[from] = true;
    for(auto a : to[from]){
      if(!visited[a]){
        get_far(a, d+1);
      }
    }
    if(diameter < d){
      diameter = d;
      far_index = from;
    }
    return {far_index, diameter};
  }

  ll get_diameter(ll from){
    pair<ll, ll> i_and_d = get_far(0, 0);
    init();
    diameter = get_far(i_and_d.first, 0).second;
    init();
    return diameter;
  }

  void init(){
    visited = vector<bool> (node_num, false);
  }

  int set_depth(int from, int d){
    visited[from] = true;
    for(auto a : to[from]){
      if(!visited[a]) set_depth(a, d+1);
    }
    return depth[from] = d;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  Tree t(n);
  for (int i = 0; i < n-1; i++) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    t.to[from].push_back(to);
    t.to[to].push_back(from);
  }
  t.get_diameter(0);
  cout << t.diameter << endl;
}
