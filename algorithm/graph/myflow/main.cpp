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

int n, m;

struct edge{
  int to, cap, rev;
  edge(int t, int c, int r){
    to = t; cap = c; rev = r;
  }
};

vector<vector<edge>> g;
vector<bool> used;

// v start t goal f flow
int dfs(int v, int t, int f){
  cout << v << ' ' << t << ' ' << f << endl;
  if(v == t) return f;
  used[v] = true;
  for(edge &e : g[v]){
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int maxflow(int s, int t){
  int flow = 0;
  while(true){
    used = vector<bool>(n, false);
    int f = dfs(s, t, INT_MAX);
    if(f == 0) return flow;
    flow += f;
    cout << flow << endl;
    // cout << "======" << endl;
  }
}

void output(){
  for(auto a : g){
    for(auto b : a){
      cout << b.to << ' ' << b.cap << ' ' << b.rev << endl;
    }
    cout << "=============" << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  g = vector<vector<edge>>(n);
  used = vector<bool>(n);
  rep(i, m){
    int from, to, cap;
    cin >> from >> to >> cap;
    g[from].push_back({to, cap, int(g[to].size())});
    g[to].push_back({from, 0, int(g[from].size())-1});
  }
  output();
  cout << "+================================" << endl;
  cout << maxflow(0, n-1) << endl;
}
