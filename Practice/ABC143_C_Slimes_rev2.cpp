#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsColor)
{
  int nColorSiz;
  cin >> nColorSiz >> rsColor;
}

int fnColorCount(string sColor)
{
  int nColorCnt = 0;
  int nBgn = 0;

  while (nBgn < sColor.size())
  {
    nColorCnt++;
    int nFoward = nBgn + 1;

    while ( nFoward < sColor.size()  &&
            sColor[nFoward] == sColor[nBgn] )
      nFoward++;

    nBgn = nFoward;
  }
  return nColorCnt;
}

int main()
{
  string sColor;

  fnInput(sColor);
  cout << fnColorCount(sColor) << endl;

  return 0;
}
