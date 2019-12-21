#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nAnum, nBnum, nCnum;
  cin >> nAnum >> nBnum >> nCnum;

  bool nRslt = false;
  for (int n = 1; n <= nBnum; n++)
    if ((nAnum * n - nCnum) % nBnum == 0)
    {
      nRslt = true;
      break;
    }

  if (nRslt)  cout << "YES" << endl;
  else        cout << "NO"  << endl;

  return 0;
}
