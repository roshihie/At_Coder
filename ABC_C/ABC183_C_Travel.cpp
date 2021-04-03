#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnCost, int& rnTrgCost)
{
  int nCostSiz;
  cin >> nCostSiz >> rnTrgCost;
  rvvnCost.resize(nCostSiz, vector<int>(nCostSiz));

  for (vector<int>& rvnCost : rvvnCost)
    for (int& rnCost : rvnCost)
      cin >> rnCost;
}

int calcMatchCostCnt(const vector<vector<int>>& cnrvvnCost, int nTrgCost)
{
  vector<int> vnCity;

  for (int nx = 0; nx < cnrvvnCost.size(); ++nx)
    vnCity.push_back( nx );

  vnCity.push_back( 0 );
  int nMatchCostCnt = 0;

  do {
    int nTotalCost = 0;

    for (int nx = 0; nx < vnCity.size() - 1; ++nx)
      nTotalCost += cnrvvnCost[ vnCity[nx] ][ vnCity[nx + 1] ];

    if (nTotalCost == nTrgCost)
      ++nMatchCostCnt;
  }
  while ( next_permutation(begin(vnCity) + 1, end(vnCity) - 1) );
  
  return nMatchCostCnt;
}

int main()
{
  vector<vector<int>> vvnCost;
  int nTrgCost;

  input(vvnCost, nTrgCost);
  cout << calcMatchCostCnt(vvnCost, nTrgCost) << endl;

  return 0;
}
