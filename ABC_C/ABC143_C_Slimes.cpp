#include <bits/stdc++.h>
using namespace std;

void input(string& rsColor)
{
  int nColorSiz;
  cin >> nColorSiz >> rsColor;
}

int calcColor(string sColor)
{
  int nColorCnt = 0;
  int nBgn = 0;

  while (nBgn < sColor.size() )
  {
    int nFoward = nBgn;

    while ( nFoward < sColor.size() - 1  &&
            sColor[nFoward] == sColor[nFoward + 1] )
      nFoward++;

    nColorCnt++;
    nBgn = nFoward + 1;
  }
  return nColorCnt;
}

int main()
{
  string sColor;

  input(sColor);
  cout << calcColor(sColor) << endl;

  return 0;
}
