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

int fnGcd(int nOne, int nOtr)
{
  if (nOtr == 0)
    return nOne;
  else
    return fnGcd(nOtr, nOne % nOtr);
}

int fnMaxGcd(const vector<int>& cnrvnNum)
{
  vector<int> vnLeftGcd(cnrvnNum.size());
  vector<int> vnRigtGcd(cnrvnNum.size());
  int nMaxGcd = 0;

  vnLeftGcd[0] = cnrvnNum[0];
  
  for (int i = 1; i < cnrvnNum.size(); i++)
    vnLeftGcd[i] = fnGcd(vnLeftGcd[i - 1], cnrvnNum[i]);
  
  vnRigtGcd[cnrvnNum.size() - 1] = cnrvnNum[cnrvnNum.size() - 1];

  for (int i = cnrvnNum.size() - 2; i >= 0; i--)
    vnRigtGcd[i] = fnGcd(vnRigtGcd[i + 1], cnrvnNum[i]);

  for (int i = 0; i < cnrvnNum.size(); i++)
    if (i == 0)
      nMaxGcd = max(nMaxGcd, vnRigtGcd[i + 1] );
    else if (i == cnrvnNum.size() - 1)
      nMaxGcd = max(nMaxGcd, vnLeftGcd[i - 1] );
    else
      nMaxGcd = max(nMaxGcd, fnGcd(vnLeftGcd[i - 1], vnRigtGcd[i + 1] ));
  
  return nMaxGcd;
}
 
int main()
{
  vector<int> vnNum;

  fnInput(vnNum);
  cout << fnMaxGcd(vnNum) << endl;

  return 0;
}
