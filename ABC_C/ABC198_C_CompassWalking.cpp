#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0) { }

  int m_nx;
  int m_ny;
};

void input(int& rnOneDist, StCoord& roGoal)
{
  cin >> rnOneDist >> roGoal.m_nx >> roGoal.m_ny;
}

llong calcMinMovingDist(int nOneDist, StCoord oGoal)
{
  double nGoalDist = sqrt((llong)oGoal.m_nx * oGoal.m_nx +
                          (llong)oGoal.m_ny * oGoal.m_ny   );
  double nGoalDivdbl = nGoalDist / nOneDist;
  llong  nGoalDivint = nGoalDist / nOneDist;

  if (nGoalDivdbl < 1.0) return (llong)2;
  if (nGoalDivdbl == nGoalDivint) return nGoalDivint;
  return nGoalDivint + 1;
}

int main()
{
  StCoord oGoal;
  int nOneDist;
  input(nOneDist, oGoal);
  cout << calcMinMovingDist(nOneDist, oGoal) << endl;

  return 0;
}
