#include <bits/stdc++.h>
using namespace std;

void fnInput(map<int, int>& rmpCity)
{
  int nCitySiz, nRoadSiz;
  cin >> nCitySiz >> nRoadSiz;

  for (int i = 0; i < nCitySiz; i++)
    rmpCity[i + 1] = 0;

  for (int i = 0; i < nRoadSiz; i++)
  {
    int nFromCity, nToCity;
    cin >> nFromCity >> nToCity;
    rmpCity[nFromCity]++;
    rmpCity[nToCity]++;
  }
}

int fnRoadNumOut(const map<int, int>& cnrmpCity)
{
  for (pair<const int, int> PCity : cnrmpCity)
    cout << PCity.second << endl;
}

int main()
{
  map<int, int> mpCity;

  fnInput(mpCity);
  fnRoadNumOut(mpCity);

  return 0;
}
