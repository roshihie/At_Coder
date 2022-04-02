#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvElem)
{
  int sizElem;
  cin >> sizElem;
  rvElem.resize(sizElem);

  for (int& rElem : rvElem)
    cin >> rElem;
}

int calcElemOrXor(const vector<int>& crvBgnix, const vector<int>& crvElem)
{
  vector<int> vElemOr(crvBgnix.size() - 1);

  for (int nx = 0; nx < crvBgnix.size() - 1; ++nx)
  {
    int orElem = 0;

    for (int ny = crvBgnix[nx]; ny < crvBgnix[nx + 1]; ++ny)
      orElem |= crvElem[ny];

    vElemOr[nx] = orElem;
  }

  int xorElem = vElemOr[0];

  if (vElemOr.size() > 1)
    for (int nx = 1; nx < vElemOr.size(); ++nx)
      xorElem ^= vElemOr[nx];

  return xorElem;
}

void dfsOrXor(int dept, int& rOneOrXor, 
              vector<int>& rvBgnix, const vector<int>& crvElem)
{
  if (dept == (int)rvBgnix.size() - 1)
  {
    rvBgnix[dept] = crvElem.size();
    int xorElem = calcElemOrXor(rvBgnix, crvElem);
    rOneOrXor = min(rOneOrXor, xorElem);
    return;
  }
  else if ( !dept )
  {
    dfsOrXor(dept + 1, rOneOrXor, rvBgnix, crvElem);
    return;
  }

  rvBgnix[dept] = rvBgnix[dept - 1] + 1;

  while (rvBgnix[dept] < crvElem.size())
  {
    dfsOrXor(dept + 1, rOneOrXor, rvBgnix, crvElem);
    ++rvBgnix[dept];
  }
}

int calcMinOrXor(const vector<int>& crvElem)
{
  int minOrXor = INT_MAX;

  for (int seprt = 1; seprt <= crvElem.size(); ++seprt)
  {
    vector<int> vBgnix(seprt + 1);
    int oneOrXor = INT_MAX;

    dfsOrXor(0, oneOrXor, vBgnix, crvElem);
    minOrXor = min(minOrXor, oneOrXor);
  }
  return minOrXor;
}

int main()
{
  vector<int> vElem;

  input(vElem);
  cout << calcMinOrXor(vElem) << endl;

  return 0;
}
