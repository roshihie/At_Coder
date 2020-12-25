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

llong calcMinOpeTimes(const vector<int>& cnrvnNum)
{ 
  vector<llong> vnOpeTimes(2);

  for (int nEvnOdd = 0; nEvnOdd < vnOpeTimes.size(); ++nEvnOdd)
  {
    llong nOpeTimes = 0;
    llong nCumlSum  = 0;

    for (int nx = 0; nx < cnrvnNum.size(); ++nx)
    {
      nCumlSum += cnrvnNum[nx];
      if ( nx % 2 == nEvnOdd )
        if ( nCumlSum > 0 );
        else
        {
          nOpeTimes += 1 - nCumlSum;
          nCumlSum = 1;
        }
      else
        if ( nCumlSum < 0 );
        else
        {
          nOpeTimes += nCumlSum - (-1);
          nCumlSum = -1;
        }
    }
    vnOpeTimes[nEvnOdd] = nOpeTimes;
  }
  auto itElm = min_element(begin(vnOpeTimes), end(vnOpeTimes));
  return *itElm;
}

int main()
{
  vector<int> vnNum;

  input(vnNum);
  cout << calcMinOpeTimes(vnNum) << endl;

  return 0;
}
