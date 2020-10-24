#include <bits/stdc++.h>
using namespace std;

void input(string& rsColor)
{
  int nColorSiz;
  cin >> nColorSiz >> rsColor;
}

int calcColor(const string& cnrsColor)
{
  int nColor = 0;
  int nFwd = 0;

  while (nFwd < cnrsColor.size() )
  {
    ++nColor;

    while ( nFwd < cnrsColor.size() - 1  &&
            cnrsColor[nFwd] == cnrsColor[nFwd + 1] )
      ++nFwd;

    ++nFwd;
  }
  return nColor;
}

int main()
{
  string sColor;

  input(sColor);
  cout << calcColor(sColor) << endl;

  return 0;
}
