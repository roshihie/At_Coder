#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnLeft, int& rnRigt)
{
  cin >> rnLeft >> rnRigt;
}
  
int fnMinRemain2019(int nLeft, int nRigt)
{
  if (nLeft + 2018 <= nRigt) return 0;         // nLeft～nRigtまでの数に
                                               // 2019 で割り切れる数が存在
  int nMinRem2019 = 2018;

  for (int i = nLeft; i < nRigt; i++)
    for (int j = i + 1; j < nRigt + 1; j++)
    {
      int nRem2019 = (llong)i * j % 2019;
      nMinRem2019 = min(nMinRem2019, nRem2019);
    }

  return nMinRem2019;
}
  
int main()
{
  int nLeft, nRigt;
  fnInput(nLeft, nRigt);
  cout << fnMinRemain2019(nLeft, nRigt) << endl;

  return 0;
}
