#include <bits/stdc++.h>
using namespace std;

struct StDist
{
  StDist() : m_node( 0 ), m_dist( 0 ) { }

  int m_node;      // 最大距離の node
  int m_dist;      // 最大距離
};

void input( vector<vector<int>>& rvvLink )
{
  int linkSiz;
  cin >> linkSiz;
  rvvLink.resize( (linkSiz - 1) * 2 );

  for (int cnt = 0; cnt < linkSiz - 1; ++cnt)
  {
    int left, right;
    cin >> left >> right;
    --left; --right;

    rvvLink[left].push_back( right );
    rvvLink[right].push_back( left );
  } 
}

StDist calcMaxDistance( const vector<vector<int>>& cnrvvLink, int start )
{
  int size = (int)cnrvvLink.size() / 2 + 1;
  vector<int> vDist( size, -1 );

  queue<int> qNode;
  qNode.push( start );
  vDist[start] = 0;

  while ( qNode.size() )
  {
    int from = qNode.front(); qNode.pop();

    for ( int to : cnrvvLink[from] )
      if ( vDist[to] == -1 )
      {
        qNode.push( to );
        vDist[to] = vDist[from] + 1;
      }
  }
  auto itMax = max_element( begin( vDist ), end( vDist ));
  StDist oDist;
  oDist.m_node = (int)distance( begin( vDist ), itMax );
  oDist.m_dist = *itMax;
  return oDist;
}
  
int main()
{
  vector<vector<int>> vvLink;

  input( vvLink );
  int endFrom0, end;

  StDist oDist = calcMaxDistance( vvLink, 0 );
  cout << calcMaxDistance( vvLink, oDist.m_node ).m_dist + 1 << endl;
  return 0;
}
