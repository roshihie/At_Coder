#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<vector<int>>& rvvnCandy)
{
  int nSize;
  cin >> nSize;

  rvvnCandy.resize(2, vector<int>(nSize, 0));
 
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < nSize; j++)
      cin >> rvvnCandy[i][j];
}

int fnCumlSum(const vector<vector<int>>& cnrvvnCandy)
{
  int nCumlSum = 0;
  int n1stSum  = 0;
  for (int i = 0; i < cnrvvnCandy[0].size(); i++)
  {
    n1stSum += cnrvvnCandy[0][i];
    int n2ndSum = 0;
    for (int j = i; j < cnrvvnCandy[1].size(); j++)
      n2ndSum += cnrvvnCandy[1][j];

    nCumlSum = max(nCumlSum, (n1stSum + n2ndSum));
  }
  return nCumlSum;
}
    
int main()
{
  vector<vector<int>> vvnCandy;
  
  fnInput(vvnCandy);
  cout << fnCumlSum(vvnCandy) << endl;

  return 0;
}
