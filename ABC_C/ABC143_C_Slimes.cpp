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
  int nFwd = 0;

  while (nFwd < sColor.size() )
  {
    while ( nFwd < sColor.size() - 1   &&
            sColor[nFwd] == sColor[nFwd + 1] )
      ++nFwd;

    ++nColorCnt;
    ++nFwd;
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
