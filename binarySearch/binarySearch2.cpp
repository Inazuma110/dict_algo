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

double function(double x){
  return x * x;
}


int main()
{
  double left = 0;
  double right = 1000;
  double center = (left + right) / 2;
  int re;
  while (abs(140 - (re = function(center))) >= pow(10,-6))
  {
    if (re > 140)
    {
      right = center;
      center = (left + right) / 2;
    }
    else
    {
        left = center;
        center = (left + right) / 2;
    }
    // cout << "left" << left << endl;
    // cout << "right: " << right << endl;
    // cout << "center: " << center <<  endl;
  }

  // cout << (abs(140 - (re = function(center)))) << endl;
  // cout << (pow(10,-6)) << endl;
  // cout << re << endl;
  // cout << (abs(140 - (re = function(center))) >= pow(10,-6)) << endl;
  cout << center << endl;
}
