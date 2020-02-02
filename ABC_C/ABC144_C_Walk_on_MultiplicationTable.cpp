#include <bits/stdc++.h>
using namespace std;

void fnInput(int64_t& rnNumber)
{
  cin >> rnNumber;
}

int64_t fnMinStepGet(int64_t nNumber)
{
  int nSqrtInt = sqrt(nNumber);
  int nMultpler;
  int64_t nMultplcand;
  int64_t nMinDiff = INT64_MAX;

  for (int n = 1; n <= nSqrtInt; n++)
  {
    if (nNumber % n == 0)
    {
      int64_t nOther = nNumber / n;
      if (nOther - n < nMinDiff)
      {
        nMultplcand = nOther;
        nMultpler = n;
        nMinDiff = nMultplcand - nMultpler;
      }
    }
  }

  return (nMultplcand + nMultpler - 2);
}

int main()
{
  int64_t nNumber;

  fnInput(nNumber);
  cout << fnMinStepGet(nNumber) << endl;

  return 0;
}
