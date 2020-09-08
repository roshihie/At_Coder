#include <bits/stdc++.h>
using namespace std;

void input(string& rsColor)
{
  cin >> rsColor;
}

int fnChangeCnt(string sBgnColor, string sColor)
{
  int nChangeCnt = 0;

  for (int i = 0; i < sColor.size(); i++)
  {
    int n = i % 2;
    if (sColor[i] != sBgnColor[n]) nChangeCnt++;
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
