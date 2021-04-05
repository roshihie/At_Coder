#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnLen)
{
  cin >> rnLen;
}

llong calcCutCombo(int nLen)
{
  vector<int> vnDividend(11);
  vector<int> vnDivisor(11);
  --nLen;

  for (int& rnDividend : vnDividend)
    rnDividend = nLen--;

  int nDiv = 11;
  for (int& rnDivisor : vnDivisor)
    rnDivisor = nDiv--;

  for (int& rnDivisor : vnDivisor)
    for (int& rnDividend : vnDividend)
      if (rnDividend % rnDivisor == 0)
      {
        rnDividend /= rnDivisor;
        rnDivisor = 1;
        break;
      }

  llong nCutCombo = 1;

  for (int nDividend : vnDividend)
    nCutCombo *= nDividend;

  for (int nDivisor : vnDivisor)
    nCutCombo /= nDivisor;

  return nCutCombo;
}

int main()
{
  int nLen;
  input(nLen);
  cout << calcCutCombo(nLen) << endl;

  return 0;
}
