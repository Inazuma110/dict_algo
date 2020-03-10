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

// struct Graph {
//   vector<vector<p>> cost;
//   vector<bool> visited;
//   vector<int> min_cost;
//   int node_num, edge_num;
//
//   Graph(int nn, int en) : node_num(nn), edge_num(en){
//     min_cost = vector<int> (node_num, INT_MAX);
//     cost = vector<vector<p>> (node_num, vector<p>());
//   }
//
//
//   void dijkstra(int start){
//     priority_queue<p, vector<p>, greater<p>> pq;
//     pq.push({0, start});
//     min_cost[start] = 0;
//
//     while(!pq.empty()) {
//       int now_cost = pq.top().first;
//       int now = pq.top().second;
//       pq.pop();
//       if(min_cost[now] < now_cost) continue;
//
//       for(auto e : cost[now]){
//         if(min_cost[e.first] > now_cost + e.second){
//           min_cost[e.first] = now_cost + e.second;
//           pq.push({min_cost[e.first], e.first});
//         }
//       }
//     }
//   }
// };
//

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  WeightedGraph<int> g(6);
  for (int i = 0; i < 9; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    g[from].emplace_back(to, cost);
    g[to].emplace_back(from, cost);
  }


  for(auto e1 : g){
    print(e1);
    for(auto e2 : e1){
      cout << e2.to << endl;
      cout << e2.cost << endl;
    }
    cout << "--------------" << endl;
  }
  // auto res = dijkstra(g, 0);
  // print(res);


  // int node_num, edge_num, r;
  // cin >> node_num >> edge_num >> r;
  // // r--;
  //
  // Graph g(node_num, edge_num);
  //
  // for (int i = 0; i < edge_num; i++) {
  //   int from, to, weight;
  //   cin >> from >> to >> weight;
  //   // from--;
  //   // to--;
  //   g.cost[from].push_back({to, weight});
  //   // g.cost[to].push_back({from, weight});
  // }
  // // cout << g.node_num << endl;
  // g.dijkstra(r);
  // for (int i = 0; i < node_num; i++) {
  //   if(g.min_cost[i] == INT_MAX) cout << "INF" << endl;
  //   else cout << g.min_cost[i] << endl;
  // }
}
