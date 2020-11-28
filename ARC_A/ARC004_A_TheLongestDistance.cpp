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

int fnDistGet(int i, int j, const vector<StCoord>& cnrvoCoord)
{
  return pow((cnrvoCoord[i].m_nXcord - cnrvoCoord[j].m_nXcord), 2) +
         pow((cnrvoCoord[i].m_nYcord - cnrvoCoord[j].m_nYcord), 2);
}

double fnLongestDist(const vector<StCoord>& cnrvoCoord)
{
  int nMaxDist = 0;
  for (int i = 0; i < cnrvoCoord.size(); i++)
    for (int j = 0; j < cnrvoCoord.size(); j++)
      if (i != j)
        nMaxDist = max(nMaxDist, fnDistGet(i, j, cnrvoCoord));

   return sqrt((double)nMaxDist); 
}

int main()
{
  vector<StCoord> voCoord;

  fnInput(voCoord);
  cout << fnLongestDist(voCoord) << endl;

  return 0;
}
