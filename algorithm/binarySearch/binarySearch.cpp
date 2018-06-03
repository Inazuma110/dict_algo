using namespace std;

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
#include <numeric>
typedef long long ll;
typedef pair<int,int> p;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)


int main()
{
  vector<int> v = {3,5,9,11,30,101,300};
  int k = 2;
  int left = 0;
  int right = int(v.size()) - 1;
  int center = (left + right) / 2;
  while (right - left != 1)
  {
    // if (k == v[center])
    // {
    //   cout << k << endl;
    //   return 0;
    // }
    if (k <= v[center])
    {
      right = center;
      center = (left + right) / 2;
    }
    else
    {
      left = center;
      center = (left + right) / 2;
    }

    if (right - left == 1)
    {
      int v1 = v[center];
      int v2 = v[center+1];
      if (v1 >= k)
      {
        cout << v1 << endl;
        return 0;
      }
      v[center] = max(v1,v2);
      break;
    }
  }

  cout << v[center] << endl;


}
