#include <bits/stdc++.h>
using namespace std;

struct StDist
{
  StDist() : m_nNode( 0 ), m_nDist( 0 ) { }

  int m_nNode;     // 最大距離の node
  int m_nDist;     // 最大距離
};

void input( vector<vector<int>>& rvvnLink )
{
  int nLinkSiz;
  cin >> nLinkSiz;
  rvvnLink.resize( (nLinkSiz - 1) * 2 );

  for (int nCnt = 0; nCnt < nLinkSiz - 1; ++nCnt)
  {
    int nLeft, nRigt;
    cin >> nLeft >> nRigt;
    --nLeft; --nRigt;

    rvvnLink[nLeft].push_back( nRigt );
    rvvnLink[nRigt].push_back( nLeft );
  } 
}

StDist calcMaxDistance( const vector<vector<int>>& cnrvvnLink, int nStart )
{
  int nSize = (int)cnrvvnLink.size() / 2 + 1;
  vector<int> vnDist( nSize, -1 );

  queue<int> qnNode;
  qnNode.push( nStart );
  vnDist[nStart] = 0;

  while ( qnNode.size() )
  {
    int nFrom = qnNode.front(); qnNode.pop();

    for ( int nTo : cnrvvnLink[nFrom] )
      if ( vnDist[nTo] == -1 )
      {
        qnNode.push( nTo );
        vnDist[nTo] = vnDist[nFrom] + 1;
      }
  }
  auto itMax = max_element( begin( vnDist ), end( vnDist ));
  StDist oDist;
  oDist.m_nNode = (int)distance( begin( vnDist ), itMax );
  oDist.m_nDist = *itMax;
  return oDist;
}
  
int main()
{
  vector<vector<int>> vvnLink;

  input( vvnLink );
  int nEnd_From0, nEnd;

  StDist oDist = calcMaxDistance( vvnLink, 0 );
  cout << calcMaxDistance( vvnLink, oDist.m_nNode ).m_nDist + 1 << endl;
  return 0;
}
