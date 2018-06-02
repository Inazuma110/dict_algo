#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <climits>
typedef long long ll;
using namespace std;

typedef pair<int,int> p;

int main()
{
  // input & declare
  int h,w;
  cin >> h >> w;
  int d[h][w];
  vector<string> v;
  string tmp;
  int sx,sy,gx,gy;
  for(int i = 0; i < h; i++)
  {
    cin >> tmp;
    for(int j = 0; j < w; j++)
    {
      if (tmp[j] == 's') { sy = i; sx = j; }
      if (tmp[j] == 'g') { gy = i; gx = j; }
      d[i][j] = INT_MAX;
    }
    v.push_back(tmp);
  }
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  stack<p> s;
  s.push(p(sy,sx));
  d[sy][sx] = 0;

  // process
  if (h == 1) {
    for(int i = min(sx,gx); i < max(sx,gx); i++)
    {
      if (v[0][i] == '#') {
        std::cout << "No" << '\n';
        exit(0);
      }
    }
    std::cout << "Yes" << '\n';
    exit(0);
  }

  while (s.size() != 0) {
    p ptmp = s.top();
    if (ptmp.first == gy && ptmp.second == gx)
    {
      std::cout << "Yes" << '\n';
      exit(0);
    }
    s.pop();
    // std::cout  << ptmp.first << " : " << ptmp.second << " : " <<d[ptmp.second][ptmp.first] << '\n';
    for(int i = 0; i < 4; i++)
    {
      int ny = ptmp.first + dy[i];
      int nx = ptmp.second + dx[i];
      if (nx >= 0 && nx < w && ny >= 0 && ny < w && (v[ny][nx] == '.' || v[ny][nx] == 'g') && d[ny][nx] == INT_MAX) {
        d[ny][nx] = d[ptmp.second][ptmp.first] + 1;
        s.push(p(ny,nx));
      }
    }
  }


  //output
  std::cout << "No" << '\n';
}
