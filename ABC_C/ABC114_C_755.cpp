#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

int64_t fnConvInt(const vector<char>& cnrvcNum)
{
  const vector<int> cnvnNum = {0, 3, 5, 7};

  vector<char> vcRevNum(cnrvcNum);
  reverse(begin(vcRevNum), end(vcRevNum));

  int64_t nNum = 0;
  for (int i = 0; i < vcRevNum.size(); i++)
  {
    if (vcRevNum[i] == '0') break;
    nNum += cnvnNum[ vcRevNum[i] - '0' ] * pow(10, i);
  }

  return nNum;
}

int fnDgt753_Check(const vector<char>& cnrvcNum)
{
  int nDig3 = 0, nDig5 = 0, nDig7 = 0;

  for (int i = 0; i < cnrvcNum.size(); i++)
    if      (cnrvcNum[i] == '1') nDig3++;
    else if (cnrvcNum[i] == '2') nDig5++;
    else if (cnrvcNum[i] == '3') nDig7++;

  if (nDig3 && nDig5 && nDig7)
    return 1;
  else
    return 0;
}

int fnDgt753_Count(int nMaxNum)
{
  vector<char> vcNum(10, '0');
  int nDgt753Cnt = 0;

  while (fnConvInt(vcNum) <= nMaxNum) 
  {
    if (fnDgt753_Check(vcNum)) nDgt753Cnt++;

    vcNum[vcNum.size() - 1]++;
    for (int i = vcNum.size() - 1; i >= 1; i--)
      if (vcNum[i] > '3')
      {  
        vcNum[i - 1]++;
        vcNum[i] = '1';
      }
      else
        break;
  }

  return nDgt753Cnt;
}

int main()
{
  int nMaxNum;

  fnInput(nMaxNum);
  cout << fnDgt753_Count(nMaxNum) << endl;

  return 0;
}
