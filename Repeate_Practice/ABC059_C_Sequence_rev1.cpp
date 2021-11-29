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
  int nMinOpeTimes = 0;
  int nOpeTimes = 0;
  llong nCumlSum = 0;

  for (int i = 0; i < cnrvnNum.size(); ++i)
  {
    nCumlSum += cnrvnNum[i];
    if ( i % 2 == 0 )
      if ( nCumlSum > 0 );
      else
      {
        nOpeTimes += 1 - nCumlSum;
        nCumlSum = 1;
      }
    else
      if ( nCumlSum > 0 )
      {
        nOpeTimes += nCumlSum - (-1);
        nCumlSum = -1;
      }
  }
  nMinOpeTimes = nOpeTimes;

  nOpeTimes =  0;
  nCumlSum = 0;

  for (int i = 0; i < cnrvnNum.size(); ++i)
  {
    nCumlSum += cnrvnNum[i];
    if ( i % 2 == 0 )
      if ( nCumlSum > 0 )
      {
        nOpeTimes += nCumlSum - (-1);
        nCumlSum = -1;
      }
      else;
    else
      if ( nCumlSum > 0 );
      else
      {
        nOpeTimes += 1 - nCumlSum;
        nCumlSum = 1;
      }
  }
  nMinOpeTimes = min(nMinOpeTimes, nOpeTimes);

  return nMinOpeTimes;
}

int main()
{
  vector<int> vnNum;

  input(vnNum);
  cout << calcMinOpeTimes(vnNum) << endl;

  return 0;
}
