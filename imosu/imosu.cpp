// いもす法

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

int main()
{
  // input & declare
  int n;
  cin >> n;
  // date num
  std::vector<int> minv;
  std::vector<int> maxv;
  int tmp1,tmp2;
  int answer = 0;
  for(int i = 0;i < n; i++)
  {
    cin >> tmp1 >> tmp2;
    minv.push_back(tmp1);
    maxv.push_back(tmp2);
  }
  std::vector<int> result(1000001,0);

  // process
  for(int i = 0; i < n; i++)
  {
    result[minv[i]]++;
    result[maxv[i]+1]--;
  }

  for(int i = 1; i < 1000001; i++)
  {
    result[i] += result[i-1];
  }

  set<int> s(result.begin(), result.end());
  answer = *max_element(s.begin(),s.end());

  // //output
  std::cout << answer << '\n';

}
