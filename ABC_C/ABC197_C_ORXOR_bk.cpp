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

  for (int nBit = 0; nBit < ( 1 << cnrvnElm.size() ); ++nBit)
  {
    int nElmOr = 0;
    int nElmOrXor = 0;

    for (int nEach = 0; nEach < cnrvnElm.size(); ++nEach)
    {
      nElmOr |= cnrvnElm[nEach];

      if ( nBit & ( 1 << nEach )       ||
           nEach == cnrvnElm.size() - 1  )
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
