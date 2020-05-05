#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

int64_t fnIntGet(const vector<char>& cnrvcNum)
{
  const vector<int> cnvnDgt = {0, 3, 5, 7};
  int64_t nRtn = 0;
  int nNumPos = 0;

  for (int i = cnrvcNum.size() - 1; i >= 0; i--)
  {
    if (cnrvcNum[i] == '0') break;
    nRtn += cnvnDgt[ cnrvcNum[i] - '0' ] * pow(10.0, nNumPos++);
  }

  return nRtn;
}

bool fnDgt753_Check(const vector<char>& cnrvcNum)
{
  int nDgt3Cnt = 0;
  int nDgt5Cnt = 0;
  int nDgt7Cnt = 0;

  for (int i = cnrvcNum.size() - 1; i >= 0; i--)
    if      (cnrvcNum[i] == '1') nDgt3Cnt++;
    else if (cnrvcNum[i] == '2') nDgt5Cnt++;
    else if (cnrvcNum[i] == '3') nDgt7Cnt++;

  if (nDgt3Cnt && nDgt5Cnt && nDgt7Cnt)
    return true;
  else 
    return false;
}

int fnDgt753_Count(int nMaxNum)
{
  int nDgt753Cnt = 0;
  int nDgtSiz = to_string(nMaxNum).size();
  vector<char> vcNum(nDgtSiz + 1, '0');

  while (fnIntGet(vcNum) <= nMaxNum)
  {
    if (fnDgt753_Check(vcNum)) nDgt753Cnt++;

    vcNum[vcNum.size() - 1]++;
    for (int i = vcNum.size() - 1; i > 0; i--)
      if (vcNum[i] > '3')
      {
        vcNum[i - 1]++;
        vcNum[i] = '1';
      }
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
