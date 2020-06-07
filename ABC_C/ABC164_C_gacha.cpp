#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<string>& rvsGacha)
{
  int nGachaSiz;
  cin >> nGachaSiz;
  rvsGacha.resize(nGachaSiz);

  for (string& rsGacha : rvsGacha)
    cin >> rsGacha;
}
  
int fnGachaCnt(const vector<string>& cnrvsGacha)
{
  set<string> stGacha;

  for (string sGacha : cnrvsGacha)
    stGacha.insert( sGacha );

  return stGacha.size();
}
  
int main()
{
  vector<string> vsGacha;

  fnInput(vsGacha);
  cout << fnGachaCnt(vsGacha) << endl;

  return 0;
}
