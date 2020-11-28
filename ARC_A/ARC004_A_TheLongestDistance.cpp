#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_nXcord(0), m_nYcord(0) { }

  int m_nXcord;
  int m_nYcord;
};
void fnInput(vector<StCoord>& rvoCoord)
{
  int nCoordSiz;
  cin >> nCoordSiz;
  rvoCoord.resize(nCoordSiz);

  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nXcord >> roCoord.m_nYcord;
}

int fnDistGet(int nOne, int nOtr, const vector<StCoord>& cnrvoCoord)
{
  return pow((cnrvoCoord[nOne].m_nXcord - cnrvoCoord[nOtr].m_nXcord), 2) +
         pow((cnrvoCoord[nOne].m_nYcord - cnrvoCoord[nOtr].m_nYcord), 2);
}

double fnLongestDist(const vector<StCoord>& cnrvoCoord)
{
  int nMaxDist = 0;
  for (int nOne = 0; nOne < cnrvoCoord.size(); ++nOne)
    for (int nOtr = 0; nOtr < cnrvoCoord.size(); ++nOtr)
      if (nOne != nOtr)
        nMaxDist = max(nMaxDist, fnDistGet(nOne, nOtr, cnrvoCoord));

   return sqrt((double)nMaxDist); 
}

int main()
{
  vector<StCoord> voCoord;

  fnInput(voCoord);
  cout << fnLongestDist(voCoord) << endl;

  return 0;
}
