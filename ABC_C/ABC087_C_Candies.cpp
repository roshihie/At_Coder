#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnCandy)
{
  int nSize;
  cin >> nSize;

  rvvnCandy.resize(2, vector<int>(nSize, 0));
 
  for (int ny = 0; ny < 2; ++ny)
    for (int nx = 0; nx < nSize; ++nx)
      cin >> rvvnCandy[ny][nx];
}

int calcCandy(const vector<vector<int>>& cnrvvnCandy)
{
  int nMaxSum = 0;
  int nRow0Sum = 0;

  for (int nxR0 = 0; nxR0 < cnrvvnCandy[0].size(); ++nxR0)
  {
    nRow0Sum += cnrvvnCandy[0][nxR0];
    int nRow1Sum = 0;

    for (int nxR1 = nxR0; nxR1 < cnrvvnCandy[1].size(); ++nxR1)
      nRow1Sum += cnrvvnCandy[1][nxR1];

    nMaxSum = max(nMaxSum, (nRow0Sum + nRow1Sum));
  }
  return nMaxSum;
}
    
int main()
{
  vector<vector<int>> vvnCandy;
  
  input(vvnCandy);
  cout << calcCandy(vvnCandy) << endl;

  return 0;
}
