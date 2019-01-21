#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

struct Node {
  vector<int> to;
  vector<int> cost;
  bool done = false;
  int minCost = INT_MAX;
};

void printNode(vector<Node> v){
  int nodeNum = int(v.size());
  cout << "Node vector" << endl;
  for (int i = 0; i < nodeNum; i++) {
    print(v[i].to);
    print(v[i].cost);
    cout << v[i].done << endl;
    cout << v[i].minCost << endl;
    cout << "======" << endl;
  }

}

int djikstra(vector<Node> v, int start, int goal){
  int nodeNum = int(v.size());
  v[0].minCost = 0;
  int now = start;
  while(true) {
    // printNode(v);
    v[now].done = true;
    int edgeNum = int(v[now].to.size());
    for (int i = 0; i < edgeNum; i++) {
      int nextNodeIndex = v[now].to[i];
      v[nextNodeIndex].minCost =
        min(v[nextNodeIndex].minCost, v[now].minCost + v[now].cost[i]);
    }

    int minNodeIndex = -1;
    int minNodeCost = INT_MAX;
    for (int i = 0; i < nodeNum; i++) {
      if(i == now) continue;
      if(minNodeCost > v[i].minCost && !v[i].done){
        minNodeIndex = i;
        minNodeCost = v[i].minCost;
      }
    }
    now = minNodeIndex;
    if(now == goal) return v[now].minCost;
  }
}

int main(){
  int nodeNum, edgeNum;
  cin >> nodeNum >> edgeNum;
  vector<Node> v(nodeNum);
  for (int i = 0; i < edgeNum; i++) {
    int to, from, cost;
    cin >> to >> from >> cost;
    v[from].to.push_back(to);
    v[from].cost.push_back(cost);
    v[to].to.push_back(from);
    v[to].cost.push_back(cost);
  }
  cout << djikstra(v, 0, 4) << endl;
}
