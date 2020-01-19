#include <bits/stdc++.h>
using namespace std;

struct StNumCnt
{
  StNumCnt() :
    m_nNum(0), m_nCnt(0)
  { }

  int m_nNum;
  int m_nCnt;
};

void fnInput(vector<int>& rvnNum)
{
  int nSize;
  cin >> nSize;
  rvnNum.resize(nSize);

  for (int& rnElm : rvnNum)
    cin >> rnElm;
}

int fnTogether(const vector<int>& cnrvnNum)
{
  map<int, int> mpNumCnt;
  for (int nNum : cnrvnNum)
  {
    mpNumCnt[nNum]++;
    mpNumCnt[nNum - 1]++;
    mpNumCnt[nNum + 1]++;
  }

  int nMaxCnt = 0;
  for (pair<const int, int> PNumCnt : mpNumCnt)
    nMaxCnt = max(PNumCnt.second, nMaxCnt);

  return nMaxCnt;
}

int main()
{
  vector<int> vnNum;

  fnInput(vnNum);
  cout << fnTogether(vnNum) << endl;

  return 0;
}
