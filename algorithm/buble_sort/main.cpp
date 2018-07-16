#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn long long

typedef long long ll;
typedef pair<ll,ll> p;

vector<int> arr = {2,3,5,5,23,3,3,34};

void bubble_sort()
{
  while(true) {
    bool flag = true;
    for(int i = 1; i < int(arr.size()); i++)
    {
      int tmp = arr[i-1];
      if(tmp > arr[i])
      {
        arr[i-1] = arr[i];
        arr[i] = tmp;
        flag = false;
      }
    }
    if(flag) break;
  }
}

int main()
{
  bubble_sort();
  for(int i : arr) cout << i << endl;

}
