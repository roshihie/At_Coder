#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nAnum, nBnum, nCnum;
  cin >> nAnum >> nBnum >> nCnum;

  bool nReslt = false;
  for (int nx = 1; nx <= nBnum; ++nx)
    if ((nAnum * nx - nCnum) % nBnum == 0)
    {
      nReslt = true;
      break;
    }

  if (nReslt)  cout << "YES" << endl;
  else         cout << "NO"  << endl;

  return 0;
}
