#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnNumber)
{
  cin >> rnNumber;
}

llong calcMinSteps(llong nNumber)
{
  int nSqrtInt = sqrt(nNumber);
  int nMultpler;
  llong nMultplcand;

  for (int nx = 1; nx <= nSqrtInt; ++nx)
    if (nNumber % nx == 0)
    {
      nMultpler = nx;
      nMultplcand = nNumber / nx;
    }

  return (nMultplcand - 1) + (nMultpler - 1);
}

int main()
{
  llong nNumber;

  input(nNumber);
  cout << calcMinSteps(nNumber) << endl;

  return 0;
}
