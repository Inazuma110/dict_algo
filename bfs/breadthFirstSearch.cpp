#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <climits>
typedef long long ll;
using namespace std;

typedef pair<ll, ll> p;

int main()
{
  // input & declare
  ll r,c,sy,sx,gy,gx;
  string tmp;
  std::vector<string> v;
  ll dx[4] = {1,0,-1,0};
  ll dy[4] = {0,1,0,-1};
  // Rは行(Row)、Cは列(columm)

  cin >> r >> c >> sy >> sx >> gy >> gx;
  for(ll i = 1; i <= r; i++){
    cin >> tmp;
    v.push_back(tmp);
  }

  ll d[r+1][c+1];

  for(ll i = 0; i <= r; i++){
    for(ll j = 0; j <= c; j++)
      d[i][j] = INT_MAX;
  }

  queue<p> queue;
  queue.push(p(sx,sy));
  d[sy][sx] = 0;

  // process  // '#' is wall.
  while (queue.size() != 0) {
    p ptmp = queue.front();
    queue.pop();
    for(ll i = 0; i < 4; i++)
    {
      ll nx = ptmp.first + dx[i];
      ll ny = ptmp.second + dy[i];
      if (nx >= 1 && ny >= 1 && nx <= c && ny <= r && d[ny][nx] == INT_MAX && v[ny - 1][nx - 1] == '.') {
        d[ny][nx] = d[ptmp.second][ptmp.first] + 1;
        queue.push(p(nx,ny));
      }
      // std::cout << d[nx][ny] << " : " << nx << ", " << ny << '\n';
      if (ptmp.first == gx && ptmp.second == gy) break;
    }
  }

  // //output
  std::cout << d[gy][gx] << '\n';
}
