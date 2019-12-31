#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnNum)
{
  int nSize;
  cin >> nSize;
  rvnNum.resize(nSize);

  for (int& rnElm : rvnNum)
    cin >> rnElm;
}

int64_t fnSignChgTimes(const vector<int>& cnrvnNum)
{ 
  vector<int64_t> vnTimes(2);

  for (int nParity = 0; nParity < vnTimes.size(); nParity++)
  {
    int64_t nTimes = 0;
    int64_t nSum   = 0;
    for (int n = 0; n < cnrvnNum.size(); n++)
    {
      nSum += cnrvnNum[n];
      if (n % 2 == nParity)
        if (nSum > 0);
        else
        {
          nTimes += 1 - nSum;
          nSum = 1;
        }
      else
        if (nSum >= 0)
        {
          nTimes += 1 + nSum;
          nSum = -1;
        }
        else;
    }
    vnTimes[nParity] = nTimes;
  }
  auto itElm = min_element(begin(vnTimes), end(vnTimes));
  return *itElm;
}

int main()
{
  vector<int> vnNum;

  fnInput(vnNum);
  cout << fnSignChgTimes(vnNum) << endl;

  return 0;
}
