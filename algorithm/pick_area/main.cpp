#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

/*
 * @param i grid points num
 * @param e side's grid num
 */

double pick_area(double i, double e)
{
  return i + e / 2 - 1;
}

int main(){
  cout << pick_area(3, 2) << endl;

}
