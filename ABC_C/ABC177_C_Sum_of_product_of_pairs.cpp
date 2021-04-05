#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

llong calcSumOfMultiple(const vector<int>& cnrvnNum)
{
  const int cnnMod = 1e9 + 7;
  llong nCumlSum = 0;

  for (int nx = 0; nx < cnrvnNum.size(); ++nx)
    nCumlSum += cnrvnNum[nx];

  llong nSumOfMultpl = 0;

  for (int nx = 0; nx < cnrvnNum.size() - 1; ++nx)
  {
    nCumlSum -= cnrvnNum[nx];

    nSumOfMultpl += cnrvnNum[nx] * ( nCumlSum % cnnMod );
    nSumOfMultpl %= cnnMod;
  }

  return nSumOfMultpl;
}
  
int main()
{
  vector<int> vnNum;
  
  input(vnNum);
  cout << calcSumOfMultiple(vnNum) << endl;

  return 0;
}
