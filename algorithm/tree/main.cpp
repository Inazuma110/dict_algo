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
  int edge_num;
  int diameter = -1;
  int leaf_node;
  int far_index = -1;
  vector<vector<int>> cost;
  vector<bool> visited;

  Tree(int nn) : node_num(nn){
    edge_num = node_num - 1;
    cost = vector<vector<int>> (node_num);
    visited = vector<bool> (node_num, false);
  }


  pair<int, int> get_far(int from, int d){
    visited[from] = true;
    for(auto a : cost[from]){
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

  int get_diameter(int from){
    pair<int, int> i_and_d = get_far(0, 0);
    init();
    return diameter = get_far(i_and_d.first, 0).second;
  }

  void init(){
    visited = vector<bool> (node_num, false);
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
    t.cost[from].push_back(to);
    t.cost[to].push_back(from);
  }
  t.get_diameter(0);
  cout << t.diameter << endl;
}
