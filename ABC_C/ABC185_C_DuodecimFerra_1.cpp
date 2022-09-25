#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rlen)
{
  cin >> rlen;
}

llong calcCutCombo(int len)
{
  vector<int> vDividend(11);
  vector<int> vDivisor(11);
  --len;

  for (int& rdividend : vDividend)
    rdividend = len--;

  int div = 11;
  for (int& rdivisor : vDivisor)
    rdivisor = div--;

  for (int& rdivisor : vDivisor)
    for (int& rdividend : vDividend)
      if (rdividend % rdivisor == 0)
      {
        rdividend /= rdivisor;
        rdivisor = 1;
        break;
      }

  llong cntCutCombo = 1;

  for (int dividend : vDividend)
    cntCutCombo *= dividend;

  for (int divisor : vDivisor)
    cntCutCombo /= divisor;

  return cntCutCombo;
}

int main()
{
  int len;
  input(len);
  cout << calcCutCombo(len) << endl;

  return 0;
}
