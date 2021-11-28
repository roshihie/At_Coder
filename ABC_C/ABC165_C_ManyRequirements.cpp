#include <bits/stdc++.h>
using namespace std;

struct StReqr
{
  StReqr() :
    m_nBgn(0), m_nEnd(0), m_nDiff(0), m_nPoint(0) { }

  int m_nBgn;
  int m_nEnd;
  int m_nDiff;
  int m_nPoint;
};

void input(int& rnSeqSiz, int& rnMaxNum, vector<StReqr>& rvoReqr)
{
  int nReqSiz;
  cin >> rnSeqSiz >> rnMaxNum >> nReqSiz;
  rvoReqr.resize(nReqSiz);

  for (StReqr& roReqr : rvoReqr)
  {
    cin >> roReqr.m_nBgn >> roReqr.m_nEnd >> roReqr.m_nDiff >> roReqr.m_nPoint;
    --roReqr.m_nBgn; --roReqr.m_nEnd;
  }
}
  
void dfsMakeSeq(int nDept, int nMaxNum, 
                vector<int>& rvnSeq,
                const vector<StReqr>& cnrvoReqr,
                int& rnMaxPoint)
{
  if (nDept == rvnSeq.size())
  {
    int nPoint = 0;

    for (StReqr oReqr : cnrvoReqr)
      if (rvnSeq[ oReqr.m_nEnd ] - rvnSeq[ oReqr.m_nBgn ] == oReqr.m_nDiff)
        nPoint += oReqr.m_nPoint;

    rnMaxPoint = max(rnMaxPoint, nPoint);
    return;
  }

  if (nDept > 0)
    rvnSeq[nDept] = rvnSeq[ nDept - 1 ];

  while (rvnSeq[nDept] <= nMaxNum)
  {
    dfsMakeSeq(nDept + 1, nMaxNum, rvnSeq, cnrvoReqr, rnMaxPoint);
    ++rvnSeq[nDept];
  }
}

int calcMaxPoint(int nSeqSiz, int nMaxNum, const vector<StReqr>& cnrvoReqr)
{
  int nMaxPoint = 0;
  vector<int> vnSeq(nSeqSiz, 1);

  dfsMakeSeq(0, nMaxNum, vnSeq, cnrvoReqr, nMaxPoint);
  return nMaxPoint;
}
  
int main()
{
  int nSeqSiz, nMaxNum;
  vector<StReqr> voReqr;

  input(nSeqSiz, nMaxNum, voReqr);
  cout << calcMaxPoint(nSeqSiz, nMaxNum, voReqr) << endl;

  return 0;
}
