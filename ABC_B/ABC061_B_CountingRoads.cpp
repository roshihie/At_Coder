#include <bits/stdc++.h>
using namespace std;

void input(map<int, int>& rmpCity)
{
  int nCitySiz, nRoadSiz;
  cin >> nCitySiz >> nRoadSiz;

  for (int nx = 0; nx < nCitySiz; ++nx)
    rmpCity[nx + 1] = 0;

  for (int nx = 0; nx < nRoadSiz; ++nx)
  {
    int nFromCity, nToCity;
    cin >> nFromCity >> nToCity;
    ++rmpCity[nFromCity];
    ++rmpCity[nToCity];
  }
}

void countRoadSpread(const map<int, int>& cnrmpCity)
{
  for (auto PCity : cnrmpCity)
    cout << PCity.second << endl;
}

int main()
{
  map<int, int> mpCity;

  input(mpCity);
  countRoadSpread(mpCity);

  return 0;
}
