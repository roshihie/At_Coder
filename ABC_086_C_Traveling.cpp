#include <bits/stdc++.h>
using namespace std;

struct StPoint
{
  StPoint() :
    m_nTime(0), m_nPntX(0), m_nPntY(0)
  { }

  int m_nTime;
  int m_nPntX;
  int m_nPntY;
};

void fnInput(vector<StPoint>& rvoPoint)
{
  StPoint oPoint;
  int nSiz;
  cin >> nSiz;

  rvoPoint.resize(nSiz + 1, oPoint);
  for (int i = 0; i < nSiz; i++)
    cin >> rvoPoint[i + 1].m_nTime >> rvoPoint[i + 1].m_nPntX >> rvoPoint[i + 1].m_nPntY;
}

int fnTravel(const vector<StPoint>& cnrvoPoint)
{
  for (int i = 0; i < cnrvoPoint.size() - 1; i++)
  {
    int nTime = cnrvoPoint[i + 1].m_nTime - cnrvoPoint[i].m_nTime;
    int nDist = abs(cnrvoPoint[i + 1].m_nPntX - cnrvoPoint[i].m_nPntX)
              + abs(cnrvoPoint[i + 1].m_nPntY - cnrvoPoint[i].m_nPntY);

    if (nTime < nDist)           return 0;
    if (nTime % 2 != nDist % 2)  return 0;
  }
  return 1;
}

int main()
{
  vector<StPoint> voPoint;

  fnInput(voPoint);
  if (fnTravel(voPoint))  cout << "Yes" << endl;
  else                    cout << "No"  << endl;

  return 0;
}
