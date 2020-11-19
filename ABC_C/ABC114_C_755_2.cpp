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

  for (int nx = cnrvcNum.size() - 1; nx >= 0; --nx)
  {
    if (cnrvcNum[nx] == '0') break;
    llong nNum = cnvnDgt[ cnrvcNum[nx] - '0' ];
    
    for (int ny = 0; ny < nNumPos; ++ny) nNum *= 10;

    nRtn += nNum;
    ++nNumPos;
  }
  return nRtn;
}

int isDgt753(const vector<char>& cnrvcNum)
{
  int nDgt3 = 0, nDgt5 = 0, nDgt7 = 0;

  for (int nx = 0; nx < cnrvcNum.size(); ++nx)
    if      (cnrvcNum[nx] == '1') ++nDgt3;
    else if (cnrvcNum[nx] == '2') ++nDgt5;
    else if (cnrvcNum[nx] == '3') ++nDgt7;

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
    if ( isDgt753(vcNum) ) ++nDgt753Cnt;

    ++vcNum[vcNum.size() - 1];
    for (int nx = vcNum.size() - 1; nx > 0; --nx)
      if (vcNum[nx] > '3')
      {  
        ++vcNum[nx - 1];
        vcNum[nx] = '1';
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
