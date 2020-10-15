#include <bits/stdc++.h>
using namespace std;

struct StRequir
{
  StRequir() :
    m_nBgn(0), m_nEnd(0), m_nDiff(0), m_nPoint(0) { }

  int m_nBgn;
  int m_nEnd;
  int m_nDiff;
  int m_nPoint;
};

void input(int& rnSeqSiz, int& rnMaxNum, vector<StRequir>& rvoRequir)
{
  int nReqSiz;
  cin >> rnSeqSiz >> rnMaxNum >> nReqSiz;
  rvoRequir.resize(nReqSiz);

  for (StRequir& roRequir : rvoRequir)
    cin >> roRequir.m_nBgn >> roRequir.m_nEnd >> roRequir.m_nDiff >> roRequir.m_nPoint;
}
  
void dfsMakeSeq(int nDept, int nMaxNum, vector<int>& rvnSeq,
                  const vector<StRequir>& cnrvoRequir, int& rnMaxPoint)
{
  if (nDept == rvnSeq.size())
  {
    int nPoint = 0;

    for (StRequir oRequir : cnrvoRequir)
      if (rvnSeq[ oRequir.m_nEnd - 1 ] - rvnSeq[ oRequir.m_nBgn - 1 ] == oRequir.m_nDiff)
        nPoint += oRequir.m_nPoint;

    rnMaxPoint = max(rnMaxPoint, nPoint);
    return;
  }

  if (nDept > 0)
    rvnSeq[nDept] = rvnSeq[ nDept - 1 ];

  while (rvnSeq[nDept] <= nMaxNum)
  {
    dfsMakeSeq(nDept + 1, nMaxNum, rvnSeq, cnrvoRequir, rnMaxPoint);
    ++rvnSeq[nDept];
  }
}

int calcMaxPoint(int nSeqSiz, int nMaxNum, const vector<StRequir>& cnrvoRequir)
{
  int nMaxPoint = 0;
  vector<int> vnSeq(nSeqSiz, 1);

  dfsMakeSeq(0, nMaxNum, vnSeq, cnrvoRequir, nMaxPoint);
  return nMaxPoint;
}
  
int main()
{
  int nSeqSiz, nMaxNum;
  vector<StRequir> voRequir;

  input(nSeqSiz, nMaxNum, voRequir);
  cout << calcMaxPoint(nSeqSiz, nMaxNum, voRequir) << endl;

  return 0;
}
