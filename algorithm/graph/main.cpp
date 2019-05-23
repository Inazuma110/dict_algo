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
  vector<vector<int>> cost;
  vector<bool> visited;
  vector<int> min_cost;
  int node_num, edge_num;

  Graph(int nn, int en) : node_num(nn), edge_num(en){
    visited = vector<bool> (node_num, false);
    min_cost = vector<int> (node_num, INT_MAX);
    cost = vector<vector<int>> (node_num, vector<int> (node_num, -1));
  }

  int dijkstra(int start, int goal){
    min_cost[start] = 0;
    int now = start;
    while(true) {
      if(now == goal) {
        int result = min_cost[now];
        init();
        return result;
      }

      visited[now] = true;
      for (int i = 0; i < int(cost.size()); i++) {
        if(cost[now][i] != -1){
          min_cost[i] = min(min_cost[i], min_cost[now]+cost[now][i]);
        }
      }

      int min_node_index = -1;
      int min_node_cost = INT_MAX;
      for (int i = 0; i < int(cost.size()); i++) {
        if((min_node_cost > min_cost[i]) && !visited[i]){
          min_node_index = i;
          min_node_cost = min_cost[i];
        }
      }
      now = min_node_index;
    }

    // error
    return -1;
  }

  void init(){
    visited = vector<bool> (node_num, false);
    min_cost = vector<int> (node_num, INT_MAX);
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int node_num, edge_num;
  cin >> node_num >> edge_num;

  Graph g(node_num, edge_num);

  for (int i = 0; i < edge_num; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--;
    to--;
    g.cost[from][to] = weight;
    g.cost[to][from] = weight;
  }
  cout << g.node_num << endl;
  cout << g.dijkstra(0, 4) << endl;
  cout << g.dijkstra(0, 3) << endl;
}
