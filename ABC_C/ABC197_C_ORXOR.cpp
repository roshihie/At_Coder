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

int calcOrXor(const vector<int>& cnrvnBgn, const vector<int>& cnrvnElm)
{
  vector<int> vnElmOr(cnrvnBgn.size() - 1);

  for (int nBgn = 0; nBgn < cnrvnBgn.size() - 1; ++nBgn)
  {
    int nElmOr = 0;

    for (int nx = cnrvnBgn[nBgn]; nx < cnrvnBgn[nBgn + 1]; ++nx)
      nElmOr |= cnrvnElm[nx];

    vnElmOr[nBgn] = nElmOr;
  }

  int nElmXor = vnElmOr[0];

  if (vnElmOr.size() > 1)
    for (int nx = 1; nx < vnElmOr.size(); ++nx)
      nElmXor ^= vnElmOr[nx];

  return nElmXor;
}

void dfsOrXor(int nDept, int& rnSepOrXor, 
              vector<int>& rvnBgn, const vector<int>& cnrvnElm)
{
  if (nDept == rvnBgn.size() - 1)
  {
    rvnBgn[nDept] = cnrvnElm.size();
    int nCurOrXor = calcOrXor(rvnBgn, cnrvnElm);
    rnSepOrXor = min(rnSepOrXor, nCurOrXor);
    return;
  }
  else if ( !nDept )
  {
    dfsOrXor(nDept + 1, rnSepOrXor, rvnBgn, cnrvnElm);
    return;
  }

  rvnBgn[nDept] = rvnBgn[nDept - 1] + 1;

  while (rvnBgn[nDept] < cnrvnElm.size())
  {
    dfsOrXor(nDept + 1, rnSepOrXor, rvnBgn, cnrvnElm);
    ++rvnBgn[nDept];
  }
}

int calcMinOrXor(const vector<int>& cnrvnElm)
{
  int nMinOrXor = INT_MAX;

  for (int nSep = 1; nSep <= cnrvnElm.size(); ++nSep)
  {
    vector<int> vnBgn(nSep + 1);
    int nSepOrXor = INT_MAX;

    dfsOrXor(0, nSepOrXor, vnBgn, cnrvnElm);
    nMinOrXor = min(nMinOrXor, nSepOrXor);
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
