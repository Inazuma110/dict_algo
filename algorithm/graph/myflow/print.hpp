// #ifndef bits/stdc++.h
#include <bits/stdc++.h>
// #endif /* end of include guard */

using namespace std;

struct Container;

template <class>
struct Ignore{
  typedef Container type;
};

template <class T, class X=Container>
struct PrintObj{
  void operator()(T value){
    cout << value;
  }
};

template<class T>
struct PrintObj<T, typename Ignore<typename T::iterator>::type>{
  void operator()(T value){
    // cout << endl << "[";
    cout << "[";
    bool isFirst = true;
    for(auto a : value){
      if(!isFirst){
        cout << ", ";
      }
      PrintObj<typename T::value_type>()(a);
      isFirst = false;
    }
    cout << "]" << endl;
  }
};

template<class T>
void print(T value){
  PrintObj<T>()(value);
  cout << endl;
}

template<class T, class U>
ostream& operator << (ostream& os, const pair<T, U> p){
  os << "(" << p.first << " : " << p.second << ")";
  return os;
}
