#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnNumber)
{
  cin >> rnNumber;
}

llong fnMinStepGet(llong nNumber)
{
  int nSqrtInt = sqrt(nNumber);
  int nMultpler;
  llong nMultplcand;

  for (int n = 1; n <= nSqrtInt; n++)
    if (nNumber % n == 0)
    {
      nMultpler = n;
      nMultplcand = nNumber / n;
    }

  return (nMultplcand + nMultpler - 2);
}

int main()
{
  llong nNumber;

  fnInput(nNumber);
  cout << fnMinStepGet(nNumber) << endl;

  return 0;
}
