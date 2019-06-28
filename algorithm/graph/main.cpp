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

struct Graph {
  vector<vector<p>> cost;
  vector<bool> visited;
  vector<int> min_cost;
  int node_num, edge_num;

  Graph(int nn, int en) : node_num(nn), edge_num(en){
    min_cost = vector<int> (node_num, INT_MAX);
    cost = vector<vector<p>> (node_num, vector<p>());
  }


  void dijkstra(int start){
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    min_cost[start] = 0;

    while(!pq.empty()) {
      int now_cost = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(min_cost[now] < now_cost) continue;

      for(auto e : cost[now]){
        if(min_cost[e.first] > now_cost + e.second){
          min_cost[e.first] = now_cost + e.second;
          pq.push({min_cost[e.first], e.first});
        }
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int node_num, edge_num, r;
  cin >> node_num >> edge_num >> r;
  // r--;

  Graph g(node_num, edge_num);

  for (int i = 0; i < edge_num; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    // from--;
    // to--;
    g.cost[from].push_back({to, weight});
    // g.cost[to].push_back({from, weight});
  }
  // cout << g.node_num << endl;
  g.dijkstra(r);
  for (int i = 0; i < node_num; i++) {
    if(g.min_cost[i] == INT_MAX) cout << "INF" << endl;
    else cout << g.min_cost[i] << endl;
  }
}
