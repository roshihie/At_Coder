#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StGrid
{
  StGrid() : m_x(0), m_y(0) {}
  StGrid(llong nx, llong ny) : m_x(nx), m_y(ny) {}

  bool operator==(const StGrid& croGridOtr) const
  {
    return ( m_x == croGridOtr.m_x && m_y == croGridOtr.m_y );
  }

  llong m_x;
  llong m_y;
};

void input(StGrid& roGridBgn, StGrid& roGridEnd)
{
  cin >> roGridBgn.m_x >> roGridBgn.m_y;
  cin >> roGridEnd.m_x >> roGridEnd.m_y;
}

int calcMinStepCnt(StGrid oGridBgn, StGrid oGridEnd)
{
  if ( oGridBgn == oGridEnd )
    return 0;

  llong difBgn = oGridBgn.m_x - oGridBgn.m_y;
  llong difEnd = oGridEnd.m_x - oGridEnd.m_y;
  llong sumBgn = oGridBgn.m_x + oGridBgn.m_y;
  llong sumEnd = oGridEnd.m_x + oGridEnd.m_y;
  llong difx   = oGridBgn.m_x - oGridEnd.m_x;
  llong dify   = oGridBgn.m_y - oGridEnd.m_y;

  if ( abs(difx) + abs(dify) <= 3LL ||
       sumBgn - sumEnd == 0LL       || difBgn - difEnd == 0LL )
    return 1;

  if ( ( difx + dify ) % 2 == 0LL   || abs(difx) + abs(dify)  <= 6LL  ||
       abs( difx + dify ) <= 3LL    || abs( difx - dify ) <= 3LL )
    return 2;

  return 3;
}

int main()
{
  StGrid oGridBgn, oGridEnd;
  input(oGridBgn, oGridEnd);
  cout << calcMinStepCnt(oGridBgn, oGridEnd) << endl;

  return 0;
}
