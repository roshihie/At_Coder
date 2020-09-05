#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

llong toInt(const vector<char>& cnrvcNum)
{
  const vector<int> cnvnDgt = {0, 3, 5, 7};
  llong nRtn = 0;
  int nNumPos = 0;

  for (int i = cnrvcNum.size() - 1; i >= 0; i--)
  {
    if (cnrvcNum[i] == '0') break;
    llong nNum = cnvnDgt[ cnrvcNum[i] - '0' ];
    
    for (int n = 0; n < nNumPos; n++) nNum *= 10;

    nRtn += nNum;
    nNumPos++;
  }
  return nRtn;
}

int isDgt753(const vector<char>& cnrvcNum)
{
  int nDgt3 = 0, nDgt5 = 0, nDgt7 = 0;

  for (int i = 0; i < cnrvcNum.size(); i++)
    if      (cnrvcNum[i] == '1') nDgt3++;
    else if (cnrvcNum[i] == '2') nDgt5++;
    else if (cnrvcNum[i] == '3') nDgt7++;

  if (nDgt3 && nDgt5 && nDgt7)
    return 1;
  else
    return 0;
}

int countDgt753(int nMaxNum)
{
  int nDgt753Cnt = 0;
  int nDgtSiz = to_string(nMaxNum).size();
  vector<char> vcNum(nDgtSiz + 1, '0');

  while (toInt(vcNum) <= nMaxNum) 
  {
    if (isDgt753(vcNum)) nDgt753Cnt++;

    vcNum[vcNum.size() - 1]++;
    for (int i = vcNum.size() - 1; i > 0; i--)
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

  input(nMaxNum);
  cout << countDgt753(nMaxNum) << endl;

  return 0;
}
