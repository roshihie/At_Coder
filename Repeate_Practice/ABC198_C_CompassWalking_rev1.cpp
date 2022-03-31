#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0) { }

  int m_nx;
  int m_ny;
};

void input(int& rdistOne, StCoord& roGoal)
{
  cin >> rdistOne >> roGoal.m_nx >> roGoal.m_ny;
}

int calcGoalStps(int distOne, StCoord oGoal)
{
  double distGoal = sqrt( (llong)oGoal.m_nx * oGoal.m_nx + 
                          (llong)oGoal.m_ny * oGoal.m_ny  );
  int cntGoalStps = max( distGoal / distOne, 1.0 );

  if ( distGoal != distOne * cntGoalStps )
    ++cntGoalStps;

  return cntGoalStps;
}

int main()
{
  StCoord oGoal;
  int distOne;

  input(distOne, oGoal);
  cout << calcGoalStps(distOne, oGoal) << endl;

  return 0;
}
