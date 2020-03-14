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

struct BipartiteMatching {
  vector< vector< int > > graph;
  vector< int > match, used;
  int timestamp;

  BipartiteMatching(int n) : graph(n), used(n, 0), match(n, -1), timestamp(0) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      // とりあえずつなげる
      // つながりたいやつがもう繋がってたら，そいつが他のやつに繋がれないか探す
      // つまり増加パスを探すとも言える
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching() {
    int ret = 0;
    for(int i = 0; i < int(graph.size()); i++) {
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < int(graph.size()); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // int n, m;
  // cin >> n >> m;
  // rep(i, n) rep(j, m){
  //   string tmp;
  //   cin >> tmp;
  //   bool is_edge = tmp == "o";
  //   if(is_edge) bm.add_edge(i, n+j);
  // }
  int x, y, m;
  cin >> x >> y >> m;
  BipartiteMatching bm(x+y);
  rep(i, m){
    int from, to;
    cin >> from >> to;
    to += x;
    bm.add_edge(from, to);
  }
  int res = bm.bipartite_matching();
  cout << res << endl;
  // bm.output();
}
