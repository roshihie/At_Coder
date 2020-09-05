#include <bits/stdc++.h>
using namespace std;

struct StNumCnt
{
  StNumCnt() : m_nNum(0), m_nCnt(0) { }

  int m_nNum;
  int m_nCnt;
};

class CGreater_nCnt
{
  public:
    bool operator()(const StNumCnt& lhs, const StNumCnt& rhs)
    {
      return lhs.m_nCnt > rhs.m_nCnt;
    }
};

void input(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

int calcMinChangeCnt(const vector<int>& cnrvnNum)
{
  map<int, int> mpNumCntEvn, mpNumCntOdd;

  for (int i = 0; i < cnrvnNum.size(); ++i)
    if ( i % 2 == 0 )
      mpNumCntEvn[ cnrvnNum[i] ]++;
    else
      mpNumCntOdd[ cnrvnNum[i] ]++;

  vector<StNumCnt> voNumCntEvn( mpNumCntEvn.size() ),
                   voNumCntOdd( mpNumCntOdd.size() );

  int n = 0;
  for (pair<int, int> PNumCnt : mpNumCntEvn)
  {
    voNumCntEvn[n].m_nNum   = PNumCnt.first;
    voNumCntEvn[n++].m_nCnt = PNumCnt.second;
  }

  n = 0;
  for (pair<int, int> PNumCnt : mpNumCntOdd)
  {
    voNumCntOdd[n].m_nNum   = PNumCnt.first;
    voNumCntOdd[n++].m_nCnt = PNumCnt.second;
  }

  sort(begin(voNumCntEvn), end(voNumCntEvn), CGreater_nCnt() );
  sort(begin(voNumCntOdd), end(voNumCntOdd), CGreater_nCnt() );

  int nMinChangeCnt = INT_MAX;

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if (voNumCntEvn[i].m_nNum != voNumCntOdd[j].m_nNum)
        nMinChangeCnt = 
          min( nMinChangeCnt, 
               (int)cnrvnNum.size() - voNumCntEvn[i].m_nCnt - voNumCntOdd[j].m_nCnt );

  return nMinChangeCnt;
}
  
int main()
{
  vector<int> vnNum;
  
  input(vnNum);
  cout << calcMinChangeCnt(vnNum) << endl;

  return 0;
}
