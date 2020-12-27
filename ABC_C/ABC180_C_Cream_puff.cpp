#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnNum)
{
  cin >> rnNum;
}

void calcDivisor(llong nNum, vector<llong>& rvnDivisor)
{
  int nSqrt = sqrt(nNum);

  for (int nx = 1; nx <= nSqrt; ++nx)
    if (nNum % nx == 0)
    {
      rvnDivisor.push_back( (llong)nx );
      if (nNum == (llong)nx * nx );
      else
        rvnDivisor.push_back( nNum / nx );
    }

  sort(begin(rvnDivisor), end(rvnDivisor));
}

int main()
{
  llong nNum;
  vector<llong> vnDivisor;

  input(nNum);
  calcDivisor(nNum, vnDivisor);

  for (llong nDivisor : vnDivisor)
    cout << nDivisor << endl;

  return 0;
}
