#include <bits/stdc++.h>
using namespace std;

struct StGrid
{
  StGrid() : m_x(0), m_y(0) { }

  int m_x;
  int m_y;
};

void input(int& rdistOne, StGrid& roGoal)
{
  cin >> rdistOne >> roGoal.m_x >> roGoal.m_y;
}

int calcGoalStps(int distOne, StGrid oGoal)
{
  double distAll = sqrt( (double)oGoal.m_x * oGoal.m_x +
                         (double)oGoal.m_y * oGoal.m_y  );
  double dbQuotnt = distAll / distOne;
  int iQuotnt = ceil(dbQuotnt);

  if ( dbQuotnt >= 1.0 )
    return iQuotnt;
  else
    return iQuotnt + 1;
}

int main()
{
  StGrid oGoal;
  int distOne;

  input(distOne, oGoal);
  cout << calcGoalStps(distOne, oGoal) << endl;

  return 0;
}
