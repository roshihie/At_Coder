#include <bits/stdc++.h>
using namespace std;

struct StPoint
{
  StPoint() :
    m_nTime(0), m_nXcrd(0), m_nYcrd(0)
  { }

  int m_nTime;
  int m_nXcrd;
  int m_nYcrd;
};

void input(vector<StPoint>& rvoPoint)
{
  int nSize;
  cin >> nSize;

  rvoPoint.resize(nSize + 1);
  for (int nx = 0; nx < nSize; ++nx)
    cin >> rvoPoint[nx + 1].m_nTime >> rvoPoint[nx + 1].m_nXcrd >> rvoPoint[nx + 1].m_nYcrd;
}

int canTravel(const vector<StPoint>& cnrvoPoint)
{
  for (int nx = 0; nx < cnrvoPoint.size() - 1; ++nx)
  {
    int nTimeDiff = cnrvoPoint[nx + 1].m_nTime - cnrvoPoint[nx].m_nTime;
    int nDistDiff = abs(cnrvoPoint[nx + 1].m_nXcrd - cnrvoPoint[nx].m_nXcrd)
                  + abs(cnrvoPoint[nx + 1].m_nYcrd - cnrvoPoint[nx].m_nYcrd);

    if (nTimeDiff < nDistDiff)          return 0;
    if (nTimeDiff % 2 != nDistDiff % 2) return 0;
  }
  return 1;
}

int main()
{
  vector<StPoint> voPoint;

  input(voPoint);
  if (canTravel(voPoint)) cout << "Yes" << endl;
  else                    cout << "No"  << endl;

  return 0;
}
