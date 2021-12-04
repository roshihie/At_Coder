#include <bits/stdc++.h>
using namespace std;

void input( vector<vector<int>>& rvvNum )
{
  int rowSiz, colSiz;
  cin >> rowSiz >> colSiz;
  rvvNum.resize( rowSiz );

  for ( auto& rvNum : rvvNum )
  {
    rvNum.resize( colSiz );

    for ( int& rnum : rvNum )
      cin >> rnum;
  }
}

void calcCrossSum( const vector<vector<int>>& crvvNum )
{
  int rowSiz = (int)crvvNum.size();
  int colSiz = (int)crvvNum[0].size();
  vector<int> vRowSum( rowSiz );
  vector<int> vColSum( colSiz );

  for ( int row = 0; row < rowSiz; ++row )
    for ( int col = 0; col < colSiz; ++col )
    {
      vRowSum[row] += crvvNum[row][col];
      vColSum[col] += crvvNum[row][col];
    }

  for ( int row = 0; row < rowSiz; ++row )
  {
    for ( int col = 0; col < colSiz; ++col )
    {
      if  ( col ) cout << " ";
      cout << vRowSum[row] + vColSum[col] - crvvNum[row][col];
    }
    cout << endl;
  }
  cout << endl;
}
  
int main()
{
  vector<vector<int>> vvNum;

  input( vvNum );
  calcCrossSum( vvNum );
  return 0;
}
