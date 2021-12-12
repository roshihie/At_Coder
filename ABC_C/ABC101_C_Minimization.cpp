#include <bits/stdc++.h>
using namespace std;

void input( int& rselSiz, vector<int>& rvSeq )
{
  int seqSiz;
  cin >> seqSiz >> rselSiz;
  rvSeq.resize( seqSiz );

  for ( int& rnSeq : rvSeq )
    cin >> rnSeq;
}

int calcMinSelCnt( int selSiz, const vector<int>& crvSeq )
{
  int minSelCnt = 1;
  minSelCnt += ( ( crvSeq.size() - selSiz ) + ( selSiz - 2 )) / ( selSiz - 1 );

  return minSelCnt;
}

int main()
{
  int selSiz;
  vector<int> vSeq;
  
  input( selSiz, vSeq );
  cout << calcMinSelCnt( selSiz, vSeq ) << endl;

  return 0;
}
