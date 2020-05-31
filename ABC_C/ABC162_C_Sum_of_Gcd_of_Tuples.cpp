#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNumK)
{
  cin >> rnNumK;
}

int fnGcdGet(const vector<int>& cnrvnNun)
{
  int nGcd = cnrvnNun[0];

  for (int i = 1; i < cnrvnNun.size(); i++)
  {
    int nDividend = max(nGcd, cnrvnNun[i]);
    int nDivisor  = min(nGcd, cnrvnNun[i]);

    while ( nDividend % nDivisor )
    {
      int nMod = nDividend % nDivisor;
      nDividend = nDivisor;
      nDivisor  = nMod;
    }
    nGcd = nDivisor;
  }
  return nGcd;
}
  
int fnSumGcdTuples(int nNumK)
{
  int nSumGcd = 0;

  for (int i = 1; i <= nNumK; i++)
    for (int j = 1; j <= nNumK; j++)
      for (int k = 1; k <= nNumK; k++)
      {
        vector<int> vnNum = {i, j, k};
        nSumGcd += fnGcdGet(vnNum);
      }

  return nSumGcd;
}
  
int main()
{
  int nNumK;

  fnInput(nNumK);
  cout << fnSumGcdTuples(nNumK) << endl;

  return 0;
}
