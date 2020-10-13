#include <bits/stdc++.h>
using namespace std;

void input(int& rnUpperLim)
{
  cin >> rnUpperLim;
}

int calcGcd(const vector<int>& cnrvnNun)
{
  int nGcd = cnrvnNun[0];

  for (int nx = 1; nx < cnrvnNun.size(); ++nx)
  {
    int nDividend = max(nGcd, cnrvnNun[nx]);
    int nDivisor  = min(nGcd, cnrvnNun[nx]);

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
  
int calcSumGcdTuples(int nUpperLim)
{
  int nSumGcd = 0;

  for (int nx = 1; nx <= nUpperLim; ++nx)
    for (int ny = 1; ny <= nUpperLim; ++ny)
      for (int nz = 1; nz <= nUpperLim; ++nz)
      {
        vector<int> vnNum = {nx, ny, nz};
        nSumGcd += calcGcd(vnNum);
      }

  return nSumGcd;
}
  
int main()
{
  int nUpperLim;

  input(nUpperLim);
  cout << calcSumGcdTuples(nUpperLim) << endl;

  return 0;
}
