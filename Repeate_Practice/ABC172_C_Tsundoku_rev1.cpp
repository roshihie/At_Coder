#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnLimit, vector<llong>& rvnCostA, vector<llong>& rvnCostB)
{
  int nCostASiz, nCostBSiz;
  cin >> nCostASiz >> nCostBSiz >> rnLimit;
  rvnCostA.resize(nCostASiz + 1);
  rvnCostB.resize(nCostBSiz + 1);

  for (int i = 1; i < rvnCostA.size(); i++)
  {
    int nOneCost;
    cin >> nOneCost;
    rvnCostA[i] = rvnCostA[i - 1] + nOneCost;
  }

  for (int i = 1; i < rvnCostB.size(); i++)
  {
    int nOneCost;
    cin >> nOneCost;
    rvnCostB[i] = rvnCostB[i - 1] + nOneCost;
  }
}

int calcMaxSelect(int nLimit, const vector<llong>& cnrvnCostA, 
                              const vector<llong>& cnrvnCostB)
{
  int nCntA = cnrvnCostA.size() - 1;
  
  while ( cnrvnCostA[nCntA] > nLimit )
    --nCntA;

  int nMaxSelect = nCntA;
  int nBgnB = 0;
  int nCntB;

  while ( nCntA >= 0 ) 
  {
    while ( nBgnB < cnrvnCostB.size()  &&
            cnrvnCostA[nCntA] + cnrvnCostB[nBgnB] <= nLimit )
    {
      nCntB = nBgnB;
      ++nBgnB;
    }

    nMaxSelect = max(nMaxSelect, nCntA + nCntB);

    nBgnB = nCntB;
    --nCntA;
  }
  return nMaxSelect;
}
 
int main()
{
  int nLimit;
  vector<llong> vnCostA, vnCostB;

  input(nLimit, vnCostA, vnCostB);
  cout << calcMaxSelect(nLimit, vnCostA, vnCostB) << endl;

  return 0;
}
