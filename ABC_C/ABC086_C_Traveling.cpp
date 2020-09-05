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
  StPoint oPoint;
  int nSize;
  cin >> nSize;

  rvoPoint.resize(nSize + 1, oPoint);
  for (int i = 0; i < nSize; i++)
    cin >> rvoPoint[i + 1].m_nTime >> rvoPoint[i + 1].m_nXcrd >> rvoPoint[i + 1].m_nYcrd;
}

int canTravel(const vector<StPoint>& cnrvoPoint)
{
  for (int i = 0; i < cnrvoPoint.size() - 1; i++)
  {
    int nTime = cnrvoPoint[i + 1].m_nTime - cnrvoPoint[i].m_nTime;
    int nDist = abs(cnrvoPoint[i + 1].m_nXcrd - cnrvoPoint[i].m_nXcrd)
              + abs(cnrvoPoint[i + 1].m_nYcrd - cnrvoPoint[i].m_nYcrd);

    if (nTime < nDist)           return 0;
    if (nTime % 2 != nDist % 2)  return 0;
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
