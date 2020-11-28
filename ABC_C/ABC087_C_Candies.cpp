#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnCandy)
{
  int nSize;
  cin >> nSize;

  rvvnCandy.resize(2, vector<int>(nSize, 0));
 
  for (int nx = 0; nx < 2; ++nx)
    for (int ny = 0; ny < nSize; ++ny)
      cin >> rvvnCandy[nx][ny];
}

int calcCandy(const vector<vector<int>>& cnrvvnCandy)
{
  int nCumlSum = 0;
  int n1stSum  = 0;
  for (int nx = 0; nx < cnrvvnCandy[0].size(); ++nx)
  {
    n1stSum += cnrvvnCandy[0][nx];
    int n2ndSum = 0;
    for (int ny = nx; ny < cnrvvnCandy[1].size(); ++ny)
      n2ndSum += cnrvvnCandy[1][ny];

    nCumlSum = max(nCumlSum, (n1stSum + n2ndSum));
  }
  return nCumlSum;
}
    
int main()
{
  vector<vector<int>> vvnCandy;
  
  input(vvnCandy);
  cout << calcCandy(vvnCandy) << endl;

  return 0;
}
