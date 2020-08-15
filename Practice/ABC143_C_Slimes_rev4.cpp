#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsColor)
{
  int nColorSiz;
  cin >> nColorSiz >> rsColor;
}

int fnColorCount(string sColor)
{
  int nCoLorCnt = 0;
  int nBgn = 0;

  while (nBgn < sColor.size() )
  {
    int nFoward = nBgn;

    while (nFoward < sColor.size() - 1  &&
           sColor[nFoward] == sColor[nFoward + 1])
      nFoward++;

    nCoLorCnt++;
    nBgn = nFoward + 1;
  }
  return nCoLorCnt;
}

int main()
{
  string sColor;

  fnInput(sColor);
  cout << fnColorCount(sColor) << endl;

  return 0;
}
