#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnElm)
{
  int nElmSiz;
  cin >> nElmSiz;
  rvnElm.resize(nElmSiz);

  for (int& rnElm : rvnElm)
    cin >> rnElm;
}

int calcMinOrXor(const vector<int>& cnrvnElm)
{
  int nMinOrXor = INT_MAX;
//                 cnrvnElm 要素間の位置について全bit探索する
  for (int nBit = 0; nBit < ( 1 << cnrvnElm.size() - 1 ); ++nBit)
  {
    int nElmOr = 0;
    int nElmOrXor = 0;
//                 cnrvnElm 要素間の位置の個数は cnrvnElm.size()-1 であるから
//                 nEach＝[ 0, cnrvnElm.size()-1 ) まででよいが、cnrvnElm 最終要素を
//                 を参照するため cnrvnElm.size()-1 までループする
    for (int nEach = 0; nEach <= cnrvnElm.size() - 1; ++nEach)
    {
      nElmOr |= cnrvnElm[nEach];

      if ( nEach == cnrvnElm.size() - 1 ||
           nBit & ( 1 << nEach )          )
      {
        nElmOrXor ^= nElmOr;
        nElmOr = 0;
      }
    }
    nMinOrXor = min(nMinOrXor, nElmOrXor);
  }
  return nMinOrXor;
}

int main()
{
  vector<int> vnElm;

  input(vnElm);
  cout << calcMinOrXor(vnElm) << endl;

  return 0;
}
