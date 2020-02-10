#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nAnum, nBnum, nCnum;
  cin >> nAnum >> nBnum >> nCnum;

  bool nReslt = false;
  for (int n = 1; n <= nBnum; n++)
    if ((nAnum * n - nCnum) % nBnum == 0)
    {
      nReslt = true;
      break;
    }

  if (nReslt)  cout << "YES" << endl;
  else         cout << "NO"  << endl;

  return 0;
}
