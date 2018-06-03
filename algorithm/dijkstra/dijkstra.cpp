#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
typedef pair<int,int> p;

int main()
{
  // input & declare
  int nodeNum,edgeNum;
  cin >> nodeNum >> edgeNum;
  std::vector<std::vector<p>> graph(nodeNum,std::vector<p>());
  int from,to,cost;

  rep(j, edgeNum){
    cin >> from >> to >> cost;
    graph[from].push_back(p(to,cost));
    graph[to].push_back(p(from,cost));
    // std::cout << "=================================================" << '\n';
    // std::cout << from << '\n';
    // std::cout << to << '\n';
    // std::cout << cost << '\n';
  }

  std::vector<int> nodeSize(nodeNum,INT_MAX);
  nodeSize[0] = 0;
  std::vector<bool> isSearched(nodeNum, false);
  std::vector<int> optNodes; //候補点

  // for (int i = 0; i < nodeNum; i++)
  // {
  //   for(p j : graph[i])
  //   {
  //     std::cout << "from : " << i << " to : " << j.first << " cost : " << j.second << '\n';
  //
  //   }
  // }


  // process
  int i = 0;
  for(int k = 0; k < nodeNum; k++){
    isSearched[i] = true;
    for(p j : graph[i]){
      if (isSearched[j.first] == false) {
        optNodes.push_back(j.first);
        nodeSize[j.first] = min(nodeSize[i] + j.second, nodeSize[j.first]);
      }
    }

    int min_node = INT_MAX;
    int result;
    for (int j : optNodes)
    {
      if (min_node > nodeSize[j]) {
        min_node = nodeSize[j];

        result = j;
      }
    }
    i = result; //場所
    optNodes.erase(remove(optNodes.begin(),optNodes.end(),i),optNodes.end());
    // 配列optNodesからiをすべて削除する。

    // for(int j : optNodes){
    //   std::cout << j << '\n';
    // }
    // std::cout << "=========================" << '\n';
    // for(int j : nodeSize){
    //   std::cout << j << '\n';
    // }

  }
  std::cout << "==================コスト==================-" << '\n';
  // output
  for(int j : nodeSize)
  {
    std::cout << j << '\n';
  }
}
