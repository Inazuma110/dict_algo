#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
#include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

struct Edge {
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;


/* dijkstra(G,s,dis,prev)
   入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
   計算量：O(|E|log|V|)
   副作用：dis, prevが書き換えられる
   */
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
  int N = G.size();
  dis.resize(N, INF);
  prev.resize(N, -1); // 初期化
  priority_queue<P, vector<P>, greater<P>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {
        dis[e.to] = dis[v] + e.cost;
        prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}
/* get_path(prev, t)
   入力：dijkstra で得た prev, ゴール t
   出力： t への最短路のパス
   */
vector<int> get_path(const vector<int> &prev, int t) {
  vector<int> path;
  for (int cur = t; cur != -1; cur = prev[cur]) {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
  return path;
}

int main(){
  int v, e, r;
  cin >> v >> e >> r;
  Graph g(v);
  for (int i = 0; i < e; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    g[from].push_back({to, cost});
    g[to].push_back({from, cost});
  }
  vector<ll> dist;
  vector<int> prev;
  dijkstra(g, 0, dist, prev);
  print(dist);
  print(prev);
}
