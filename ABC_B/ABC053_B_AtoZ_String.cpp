#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsStr)
{
  cin >> rsStr;
}

int fnMaxStrAtoZ(string sStr)
{
  int nBgn, nEnd;
  for (int nx = 0; nx < sStr.size(); ++nx)
    if (sStr[nx] == 'A')
    {
      nBgn = nx;
      break;
    }

  for (int nx = sStr.size() - 1; nx >= 0; --nx)
    if (sStr[nx] == 'Z')
    {
      nEnd = nx;
      break;
    }

  return (nEnd - nBgn + 1);
}

int main()
{
  string sStr;

  fnInput(sStr);
  cout << fnMaxStrAtoZ(sStr) << endl;

  return 0;
}
