#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rlen)
{
  cin >> rlen;
}

llong calcCutCombo(int len)
{
  const int cn = len - 1;
  const int cr = 11;
  llong cntCutCombo = 1;

  for (int nx = 1; nx <= cr; ++nx)
  {
    cntCutCombo *= (cn - cr + nx);
    cntCutCombo /= nx;
  }
  return cntCutCombo;
}

int main()
{
  int len;
  input(len);
  cout << calcCutCombo(len) << endl;

  return 0;
}
