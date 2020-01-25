#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsStr)
{
  cin >> rsStr;
}

int fnMaxStrAtoZ(string sStr)
{
  int nBgn, nEnd;
  for (int i = 0; i < sStr.size(); i++)
    if (sStr[i] == 'A')
    {
      nBgn = i;
      break;
    }

  for (int i = sStr.size() - 1; i >= 0; i--)
    if (sStr[i] == 'Z')
    {
      nEnd = i;
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
