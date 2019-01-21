#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

vector<vector<int>> edge;
vector<vector<int>> cost;

// node -> V
// edge -> E
// O(VE) algorithm
int spfa(int from, int to, int v){
  // distance between from
  vector<int> d(v, INT_MAX);
  // node in queue
  vector<bool> inQueue(v, false);
  d[from] = 0;
  inQueue[from] = true;

  // bfs
  queue<int> q;
  q.push(from);
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    inQueue[now] = false;
    for (int i = 0; i < int(edge[now].size()); i++) {
      int next = edge[now][i];
      int nextd = d[now] + cost[now][i];
      if(nextd < d[next]){
        nextd = d[next];
        if(!inQueue[next]){
          inQueue[next] = true;
          q.push(next);
        }
      }
    }
    return d[to];
  }



}

int main(){

}
