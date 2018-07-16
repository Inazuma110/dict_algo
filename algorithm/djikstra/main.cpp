#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn long long

typedef long long ll;
typedef pair<ll,ll> p;

int n, m;

int djikstra(int from, int to, vector<vector<p>> graph)
{
  // 大きな値で距離を初期化。
  vector<int> distance(n, INT_MAX);
  // 頂点に訪れたかどうかを示すcheckをfalseで初期化。
  vector<bool> check(n, false);
  distance[from] = 0;
  // 頂点の数だけforをまわす。
  for(int i = 0; i < n; i++)
  {
    int now = 0;
    int nd = INT_MAX;
    for(int j = 0; j < n; j++)
    {
      if(nd > distance[j] && !check[j])
      {
        nd = distance[j];
        now = j;
      }
    }
    if(nd == INT_MAX) break;
    check[now] = true;

    for(int j = 0; j < int(graph[now].size()); j++)
    {
      int next = graph[now].first;
      int nextd = distance[now] + graph[now].second;
      if(nextd < distance[next]) distance[next] = next;
    }
  }
  return distance[to];
}

int main()
{
  cin >> n >> m;
  vector<vector<p>> graph(n, vector<p>());
  for (int i = 0; i < m; i++)
  {
    int tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    graph[tmp1-1].push_back({tmp2, tmp3});
    graph[tmp2-1].push_back({tmp1, tmp3});
  }
  // for(auto a : from) cout << a << endl;
  cout << djikstra(1, 2, graph) << endl;
}
