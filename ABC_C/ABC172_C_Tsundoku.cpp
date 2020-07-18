#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnLimit, vector<llong>& rvnCostA, vector<llong>& rvnCostB)
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

int fnMaxSelCnt(int nLimit, const vector<llong>& cnrvnCostA, 
                            const vector<llong>& cnrvnCostB)
{
  int nMaxSelCnt = 0;
  int nBgnB = cnrvnCostB.size() - 1;
  int nxA = 0;

  while (nxA < cnrvnCostA.size()  &&
         cnrvnCostA[nxA] <= nLimit   )
  {
    int nxB = nBgnB;

    while (cnrvnCostB[nxB] > nLimit - cnrvnCostA[nxA])
      nxB--;

    nMaxSelCnt = max(nMaxSelCnt, nxA + nxB);
    nBgnB = nxB;

    nxA++;
  }
  return nMaxSelCnt;
}
 
int main()
{
  int nLimit;
  vector<llong> vnCostA, vnCostB;

  fnInput(nLimit, vnCostA, vnCostB);
  cout << fnMaxSelCnt(nLimit, vnCostA, vnCostB) << endl;

  return 0;
}
