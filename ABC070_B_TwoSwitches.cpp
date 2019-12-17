#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nAlow, nAhigh, nBlow, nBhigh;
  cin >> nAlow >> nAhigh >> nBlow >> nBhigh;

  int nHigher = min(nAhigh, nBhigh);
  int nLower  = max(nAlow,  nBlow);

  cout << max(0, nHigher - nLower) << endl;

  return 0;
}
