#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> vvA;

void input()
{
  cin >> H >> W;
  vvA.resize( H, vector<int> ( W ));

  for ( auto& vA : vvA )
    for ( int& num : vA )
      cin >> num;
}

void calcCrossSum()
{
  vector<int> vRowSum( H ), vColSum( W );

  for ( int row = 0; row < H; ++row )
    for ( int col = 0; col < W; ++col )
    {
      vRowSum[row] += vvA[row][col];
      vColSum[col] += vvA[row][col];
    }

  for ( int row = 0; row < H; ++row )
  {
    for ( int col = 0; col < W; ++col )
    {
      if ( col ) cout << " ";
      cout << vRowSum[row] + vColSum[col] - vvA[row][col];
    }
    cout << endl;
  }
  cout << endl;
}
  
int main()
{
  input();
  calcCrossSum();

  return 0;
}
