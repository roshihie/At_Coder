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

int fnDgt753_Check(const vector<char>& rvcNum)
{
  int nDig3 = 0, nDig5 = 0, nDig7 = 0;

  for (int i = 0; i <rvcNum.size(); i++)
    if      (rvcNum[i] == '1') nDig3++;
    else if (rvcNum[i] == '2') nDig5++;
    else if (rvcNum[i] == '3') nDig7++;

  if (nDig3 && nDig5 && nDig7)
    return 1;
  else
    return 0;
}

int fnDgt753_Count(int nMaxNum)
{
  vector<char> vcNum(11, '0');
  int nDgt753Cnt = 0;

  while (true)
  {
    vcNum[vcNum.size() - 1]++;
    for (int i = vcNum.size() - 1; i >= 1; i--)
      if (vcNum[i] > '3')
      {  
        vcNum[i - 1]++;
        vcNum[i] = '1';
      }
      else
        break;

    if (!fnDgt753_Check(vcNum)) continue;
    if (fnConvInt(vcNum) > nMaxNum) break;
    nDgt753Cnt++;
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
