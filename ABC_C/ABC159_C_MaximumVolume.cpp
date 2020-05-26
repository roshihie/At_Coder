#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnLen)
{
  cin >> rnLen;
}
  
double fnMaxVolGet(int nLen)
{
  double nDiv3 = nLen / 3.0;
  return nDiv3 * nDiv3 * nDiv3;
}
  
int main()
{
  int nLen;

  fnInput(nLen);
  cout << fixed << setprecision(10) << fnMaxVolGet(nLen) << endl;

  return 0;
}
