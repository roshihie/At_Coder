#include <bits/stdc++.h>
using namespace std;

struct StReqr
{
  StReqr() :
    m_bgn(0), m_end(0), m_diff(0), m_point(0) { }

  int m_bgn;
  int m_end;
  int m_diff;
  int m_point;
};

void input( int& rseqSiz, int& rmaxNum, vector<StReqr>& rvoReqr )
{
  int reqSiz;
  cin >> rseqSiz >> rmaxNum >> reqSiz;
  rvoReqr.resize( reqSiz );

  for ( StReqr& roReqr : rvoReqr )
  {
    cin >> roReqr.m_bgn >> roReqr.m_end >> roReqr.m_diff >> roReqr.m_point;
    --roReqr.m_bgn; --roReqr.m_end;
  }
}
  
void dfsMakeSeq( int nDept, int maxNum, 
                 vector<int>& rvnSeq,
                 const vector<StReqr>& crvoReqr,
                 int& rmaxPoint)
{
  if ( nDept == rvnSeq.size())
  {
    int nPoint = 0;

    for ( StReqr oReqr : crvoReqr )
      if ( rvnSeq[ oReqr.m_end ] - rvnSeq[ oReqr.m_bgn ] == oReqr.m_diff )
        nPoint += oReqr.m_point;

    rmaxPoint = max( rmaxPoint, nPoint );
    return;
  }

  if ( nDept > 0 )
    rvnSeq[nDept] = rvnSeq[ nDept - 1 ];

  while ( rvnSeq[nDept] <= maxNum )
  {
    dfsMakeSeq( nDept + 1, maxNum, rvnSeq, crvoReqr, rmaxPoint );
    ++rvnSeq[nDept];
  }
}

int calcMaxPoint( int seqSiz, int maxNum, const vector<StReqr>& crvoReqr )
{
  int maxPoint = 0;
  vector<int> vnSeq( seqSiz, 1 );

  dfsMakeSeq( 0, maxNum, vnSeq, crvoReqr, maxPoint );
  return maxPoint;
}
  
int main()
{
  int seqSiz, maxNum;
  vector<StReqr> voReqr;

  input( seqSiz, maxNum, voReqr );
  cout << calcMaxPoint( seqSiz, maxNum, voReqr ) << endl;

  return 0;
}
