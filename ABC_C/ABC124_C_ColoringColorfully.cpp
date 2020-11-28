#include <bits/stdc++.h>
using namespace std;

void input(string& rsColor)
{
  cin >> rsColor;
}

int fnChangeCnt(string sBgnColor, string sColor)
{
  int nChangeCnt = 0;

  for (int nx = 0; nx < sColor.size(); ++nx)
  {
    int nMod2 = nx % 2;
    if (sColor[nx] != sBgnColor[nMod2]) ++nChangeCnt;
  }
  return nChangeCnt;
}

int calcMinChangeCnt(string sColor)
{
  int nMinChangeCnt = INT_MAX;
  nMinChangeCnt = min(nMinChangeCnt, fnChangeCnt("01", sColor));
  nMinChangeCnt = min(nMinChangeCnt, fnChangeCnt("10", sColor));

  return nMinChangeCnt;
}
 
int main()
{
  string sColor;
  input(sColor);
  cout << calcMinChangeCnt(sColor) << endl;

  return 0;
}
