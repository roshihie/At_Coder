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

int calcMaxOpeCnt( const vector<int>& crvSeq )
{
  int maxOpeCnt = 0;

  for ( int seq : crvSeq )
  {
    while ( seq % 2 == 0 )
    {
      ++maxOpeCnt;
      seq /= 2;
    }
  }
  return maxOpeCnt;
}

int main()
{
  vector<int> vSeq;
  
  input( vSeq );
  cout << calcMaxOpeCnt( vSeq ) << endl;

  return 0;
}
