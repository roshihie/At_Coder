#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnLeft, int& rnRigt)
{
  cin >> rnLeft >> rnRigt;
}
  
int calcMinRemain2019(int nLeft, int nRigt)
{
  if (nLeft + 2018 <= nRigt) return 0;         // nLeft～nRigtまでの数に
                                               // 2019 で割り切れる数が存在
  int nMinRem2019 = 2018;

  for (int nx = nLeft; nx < nRigt; ++nx)
    for (int ny = nx + 1; ny < nRigt + 1; ++ny)
    {
      int nRem2019 = (llong)nx * ny % 2019;
      nMinRem2019 = min(nMinRem2019, nRem2019);
    }

  return nMinRem2019;
}
  
int main()
{
  int nLeft, nRigt;
  input(nLeft, nRigt);
  cout << calcMinRemain2019(nLeft, nRigt) << endl;

  return 0;
}
