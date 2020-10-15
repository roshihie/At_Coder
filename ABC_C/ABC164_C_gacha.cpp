#include <bits/stdc++.h>
using namespace std;

void input(vector<string>& rvsGacha)
{
  int nGachaSiz;
  cin >> nGachaSiz;
  rvsGacha.resize(nGachaSiz);

  for (string& rsGacha : rvsGacha)
    cin >> rsGacha;
}
  
int countGacha(const vector<string>& cnrvsGacha)
{
  set<string> stGacha;

  for (string sGacha : cnrvsGacha)
    stGacha.insert( sGacha );

  return stGacha.size();
}
  
int main()
{
  vector<string> vsGacha;

  input(vsGacha);
  cout << countGacha(vsGacha) << endl;

  return 0;
}
