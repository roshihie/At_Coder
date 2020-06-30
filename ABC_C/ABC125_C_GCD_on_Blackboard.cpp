#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

int fnGcdGet(int nNumA, int nNumB)
{
  int nDividend = max(nNumA, nNumB);
  int nDivisor  = min(nNumA, nNumB);

  while (nDividend % nDivisor != 0)
  {
    int nRemain = nDividend % nDivisor;
    nDividend = nDivisor;
    nDivisor  = nRemain;
  }
  return nDivisor;
}

int fnMaxGcd(const vector<int>& cnrvnNum)
{
  vector<int> vnLeftGcd(cnrvnNum.size());
  vector<int> vnRigtGcd(cnrvnNum.size());
  vector<int> vnRemnGcd(cnrvnNum.size());

  vnLeftGcd[0] = cnrvnNum[0];
  
  for (int i = 1; i < cnrvnNum.size(); i++)
    vnLeftGcd[i] = fnGcdGet(vnLeftGcd[i - 1], cnrvnNum[i]);
  
  vnRigtGcd[cnrvnNum.size() - 1] = cnrvnNum[cnrvnNum.size() - 1];

  for (int i = cnrvnNum.size() - 2; i >= 0; i--)
    vnRigtGcd[i] = fnGcdGet(vnRigtGcd[i + 1], cnrvnNum[i]);

  for (int i = 0; i < cnrvnNum.size(); i++)
    if (i == 0)
      vnRemnGcd[i] = vnRigtGcd[i + 1];
    else if (i == cnrvnNum.size() - 1)
      vnRemnGcd[i] = vnLeftGcd[i - 1];
    else
      vnRemnGcd[i] = fnGcdGet(vnLeftGcd[i - 1], vnRigtGcd[i + 1]);
  
  auto it = max_element(begin(vnRemnGcd), end(vnRemnGcd));
  return *it;
}
 
int main()
{
  vector<int> vnNum;

  fnInput(vnNum);
  cout << fnMaxGcd(vnNum) << endl;

  return 0;
}
