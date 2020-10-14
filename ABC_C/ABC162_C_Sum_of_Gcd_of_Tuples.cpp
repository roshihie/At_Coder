#include <bits/stdc++.h>
using namespace std;

void input(int& rnUpperLim)
{
  cin >> rnUpperLim;
}

int calcGcd(int nOne, int nOtr)
{
  if ( !nOtr ) return nOne;
  return calcGcd(nOtr, nOne % nOtr);
}

int calcGcdTuples(const vector<int>& cnrvnNun)
{
  int nGcd = cnrvnNun[0];

  for (int nx = 1; nx < cnrvnNun.size(); ++nx)
    nGcd = calcGcd(nGcd, cnrvnNun[nx]);

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
        nSumGcd += calcGcdTuples(vnNum);
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
