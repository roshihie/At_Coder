#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rlen)
{
  cin >> rlen;
}

llong calcCutCombo(int len)
{
  llong cutCombo = 1LL;
  int combo = len - 11;

  for (int nx = 1; nx < 12; ++nx)
  {
    cutCombo = cutCombo * combo / nx;
    ++combo;
  }

  return cutCombo;
}

int main()
{
  int len;
  input(len);
  cout << calcCutCombo(len) << endl;

  return 0;
}
