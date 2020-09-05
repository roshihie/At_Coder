#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnNum)
{
  int nSize;
  cin >> nSize;
  rvnNum.resize(nSize);

  for (int& rnElm : rvnNum)
    cin >> rnElm;
}

llong calcSignChgTimes(const vector<int>& cnrvnNum)
{ 
  vector<llong> vnTimes(2);

  for (int nParity = 0; nParity < vnTimes.size(); nParity++)
  {
    llong nTimes = 0;
    llong nSum   = 0;
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

  input(vnNum);
  cout << calcSignChgTimes(vnNum) << endl;

  return 0;
}
