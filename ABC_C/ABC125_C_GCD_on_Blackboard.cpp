#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

int calcGcd(int nOne, int nOtr)
{
  if ( !nOtr ) return nOne;
  return calcGcd(nOtr, nOne % nOtr);
}

int calcMaxGcd(const vector<int>& cnrvnNum)
{
  vector<int> vnLeftGcd(cnrvnNum.size());
  vector<int> vnRigtGcd(cnrvnNum.size());
  int nMaxGcd = 0;

  vnLeftGcd[0] = cnrvnNum[0];
  
  for (int nx = 1; nx < cnrvnNum.size(); ++nx)
    vnLeftGcd[nx] = calcGcd(vnLeftGcd[nx - 1], cnrvnNum[nx]);
  
  vnRigtGcd[cnrvnNum.size() - 1] = cnrvnNum[cnrvnNum.size() - 1];

  for (int nx = cnrvnNum.size() - 2; nx >= 0; --nx)
    vnRigtGcd[nx] = calcGcd(vnRigtGcd[nx + 1], cnrvnNum[nx]);

  for (int nx = 0; nx < cnrvnNum.size(); ++nx)
    if (nx == 0)
      nMaxGcd = max(nMaxGcd, vnRigtGcd[nx + 1] );
    else if (nx == cnrvnNum.size() - 1)
      nMaxGcd = max(nMaxGcd, vnLeftGcd[nx - 1] );
    else
      nMaxGcd = max(nMaxGcd, calcGcd(vnLeftGcd[nx - 1], vnRigtGcd[nx + 1] ));
  
  return nMaxGcd;
}
 
int main()
{
  vector<int> vnNum;

  input(vnNum);
  cout << calcMaxGcd(vnNum) << endl;

  return 0;
}
