#include <bits/stdc++.h>
using namespace std;

void input( vector<int>& rvSeq )
{
  int seqSiz;
  cin >> seqSiz;
  rvSeq.resize( seqSiz );

  for ( int& rseq : rvSeq )
    cin >> rseq;
}
  
int calcLower( const vector<int>& crvSeq )
{
  int maxSeqCnt = 0;
  int fwd = 0;

  while (fwd < crvSeq.size() )
  {
    int seqCnt = 0;

    while ( fwd < crvSeq.size() - 1       &&
            crvSeq[fwd] >= crvSeq[fwd + 1]  )
    {
      ++seqCnt;
      ++fwd;
    }
    maxSeqCnt = max( maxSeqCnt, seqCnt );
    ++fwd;
  }
  return maxSeqCnt;
}
  
int main()
{
  vector<int> vSeq;

  input( vSeq );
  cout << calcLower( vSeq ) << endl;

  return 0;
}
