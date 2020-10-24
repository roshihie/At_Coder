#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnLimit, vector<llong>& rvnCostA, vector<llong>& rvnCostB)
{
  int nCostASiz, nCostBSiz;
  cin >> nCostASiz >> nCostBSiz >> rnLimit;
  rvnCostA.resize(nCostASiz + 1);
  rvnCostB.resize(nCostBSiz + 1);

  for (int nx = 1; nx < rvnCostA.size(); ++nx)
  {
    int nOneCost;
    cin >> nOneCost;
    rvnCostA[nx] = rvnCostA[nx - 1] + nOneCost;
  }

  for (int nx = 1; nx < rvnCostB.size(); ++nx)
  {
    int nOneCost;
    cin >> nOneCost;
    rvnCostB[nx] = rvnCostB[nx - 1] + nOneCost;
  }
}

int calcMaxSelect(int nLimit, const vector<llong>& cnrvnCostA,
                              const vector<llong>& cnrvnCostB)
{
  int nMaxSelCnt = 0;
  int nBwdB = cnrvnCostB.size() - 1;
  int nFwdA = 0;

  while ( nFwdA < cnrvnCostA.size()  &&
          cnrvnCostA[nFwdA] <= nLimit   )
  {
    while ( cnrvnCostB[nBwdB] > nLimit - cnrvnCostA[nFwdA] )
      --nBwdB;

    nMaxSelCnt = max(nMaxSelCnt, nFwdA + nBwdB);
    ++nFwdA;
  }
  return nMaxSelCnt;
}
 
int main()
{
  int nLimit;
  vector<llong> vnCostA, vnCostB;

  input(nLimit, vnCostA, vnCostB);
  cout << calcMaxSelect(nLimit, vnCostA, vnCostB) << endl;

  return 0;
}
