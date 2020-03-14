#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

struct edge{int to, cap, cost, rev;};

int n, m;
vector<vector<edge>> g;
vector<int> dist, prevv, preve;

void add_edge(int from, int to, int cap, int cost){
  g[from].push_back({to, cap, cost, int(g[to].size())});
  g[to].push_back({from, 0, -cost, int(g[from].size())-1});
}

// start goal flow
int min_cost_flow(int s, int t, int f){
  int res = 0;
  while(f > 0){
    // bellman-ford
    dist = vector<int>(n, INT_MAX);
    dist[s] = 0;
    bool update = true;
    while(update){
      update = false;
      for (int v = 0; v < n; v++) {
        if(dist[v] == INT_MAX) continue;
        for(int i = 0; i < int(g[v].size()); i++){
          auto &e = g[v][i];
          if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            update = true;
          }
        }
      }
    }

    if(dist[t] == INT_MAX) return -1;

    int d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, g[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * dist[t];
    for (int v = t; v != s; v = prevv[v]) {
      auto &e = g[prevv[v]][preve[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return res;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int f;
  cin >> n >> m >> f;
  g = vector<vector<edge>> (n);
  dist = vector<int>(n+100);
  prevv = vector<int>(n+109);
  preve = vector<int>(n+100);
  for (int i = 0; i < m; i++) {
    int from, to, c, d;
    cin >> from >> to >> c >> d;
    add_edge(from, to, c, d);
  }

  cout << min_cost_flow(0, n-1, f) << endl;
}
