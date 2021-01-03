#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnCost, int& rnTrgTime)
{
  int nCostSiz;
  cin >> nCostSiz >> rnTrgTime;
  rvvnCost.resize(nCostSiz, vector<int>(nCostSiz));

  for (vector<int>& rvnCost : rvvnCost)
    for (int& rnCost : rvnCost)
      cin >> rnCost;
}

int calcMatchCostCnt(const vector<vector<int>>& cnrvvnCost, int nTrgTime)
{
  vector<int> vnCity;

  for (int nx = 0; nx < cnrvvnCost.size(); ++nx)
    vnCity.push_back( nx );

  vnCity.push_back( 0 );
  int nMachcCostCnt = 0;

  do {
    int nTotalCost = 0;

    for (int nx = 0; nx < vnCity.size() - 1; ++nx)
      nTotalCost += cnrvvnCost[ vnCity[nx] ][ vnCity[nx + 1] ];

    if (nTotalCost == nTrgTime)
      ++nMachcCostCnt;
  }
  while ( next_permutation(begin(vnCity) + 1, end(vnCity) - 1) );
  
  return nMachcCostCnt;
}

int main()
{
  vector<vector<int>> vvnCost;
  int nTrgTime;

  input(vvnCost, nTrgTime);
  cout << calcMatchCostCnt(vvnCost, nTrgTime) << endl;

  return 0;
}
