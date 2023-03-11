#include <bits/stdc++.h>
using namespace std;

struct StRect
{
  StRect() : m_TopRow(0), m_TopCol(0),
             m_BtmRow(0), m_BtmCol(0) { }

  int m_TopRow;        // 1-origin
  int m_TopCol;        // 1-origin
  int m_BtmRow;
  int m_BtmCol;
};

void input(vector<vector<int>>& rvvGrid, vector<StRect>& rvRect)
{
  int high, wide;
  cin >> high >> wide;
  rvvGrid.resize(high + 1, vector<int>(wide + 1, 0));
                       // row      1 … W,  col      1 … H
                       // 要素1# 0 1 … W,  要素2# 0 1 … H
  for (int row = 1; row <= high; ++row)
    for (int col = 1; col <= wide; ++col)
      cin >> rvvGrid[row][col];

  int sizRect;
  cin >> sizRect;
  rvRect.resize(sizRect);

  for ( StRect& rRect : rvRect )
  {
    cin >> rRect.m_TopRow >> rRect.m_TopCol;
    cin >> rRect.m_BtmRow >> rRect.m_BtmCol;
  }
}

void calcSumGrid(const vector<vector<int>>& crvvGrid,
                 const vector<StRect>& crvRect       )
{
                       // row      1 … W,  col      1 … H
                       // 要素1# 0 1 … W,  要素2# 0 1 … H
  vector<vector<int>> vCumGrid(crvvGrid.size(), vector<int>(crvvGrid[0].size() ));

  for (int row = 1; row < vCumGrid.size(); ++row)
    for (int col = 1; col < vCumGrid[row].size(); ++col)
      vCumGrid[row][col] = vCumGrid[row][col - 1] + crvvGrid[row][col];

  for (int col = 1; col < vCumGrid[0].size(); ++col)
    for (int row = 1; row < vCumGrid.size(); ++row)
      vCumGrid[row][col] += vCumGrid[row - 1][col];

  for ( StRect rect : crvRect )
  {
    int sumGrid = vCumGrid[ rect.m_BtmRow ][ rect.m_BtmCol ];
    sumGrid -= (  vCumGrid[ rect.m_BtmRow ][ rect.m_TopCol - 1]
                + vCumGrid[ rect.m_TopRow - 1][ rect.m_BtmCol ] );
    sumGrid += vCumGrid[ rect.m_TopRow - 1 ][ rect.m_TopCol - 1 ];

    cout << sumGrid << endl; 
  }
  return;
}

int main()
{
  vector<vector<int>> vvGrid;
  vector<StRect> vRect;

  input(vvGrid, vRect);
  calcSumGrid(vvGrid, vRect);

  return 0;
}
