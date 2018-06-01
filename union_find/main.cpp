#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;

// 根ならそのグループの要素数(負)が、子であれば親の番号が入る。初期値-1。
vector<int> uni(10000, -1);

// 頂点aの所属するグループを調べる。
int root(int a)
{
  // uni[a]が負の値なら親はa自身
  if (uni[a] < 0) return a;
  // 正の値であれば、親ルートを調べ戻り値で根に直接つなぐ。
  uni[a] = root(uni[a]);
}

// 頂点aとbをつなぐ、もともと同じグループの場合falseを返す。
bool connect(int a, int b)
{
  a = root(a);
  b = root(b);
  if (a == b) return false;

  // aを大きなグループにしたいので、逆であれば入れ替える。
  if (uni[a] > uni[b])
  {
    int hoge = a;
    a = b;
    b = hoge;
  }

  //aとbを結合し、bをaの親とする。
  uni[a] += uni[b];
  uni[b] = a;
  return true;
}

//  頂点a, bが同じグループか
bool isConnect(int a, int b)
{
  return root(a) == root(b);
}

// 頂点aを含むグループの頂点数を調べる
int size(int a)
{
  return -uni[root(a)];
}

int main()
{
  // for (int i = 1; i < 10; i++)
  // {
  //   uni[i] = i;
  // }
  // cout << connect(2,3) << endl;
//   cout << root(3) << endl;
//   cout << isConnect(1,3) << endl;
//   // cout << size(1) << endl;
//   cout << connect(2, 5) << endl;
//   cout << isConnect(1, 5) << endl;
//   cout << connect(3, 2) << endl;
//   cout << isConnect(1, 5) << endl;
//   // cout << size(3) << endl;
//   cout << root(5) << endl;
//
//   return 0;
}
