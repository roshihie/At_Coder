#include <bits/stdc++.h>
using namespace std;

struct StDist
{
  StDist() : m_node(0), m_dist(0) { }

  int m_node;      // 最大距離の node
  int m_dist;      // 最大距離
};

void input( vector<vector<int>>& rvvLink )
{
  int linkSiz;
  cin >> linkSiz;
  rvvLink.resize( (linkSiz - 1) * 2 );

  for ( int cnt = 0; cnt < linkSiz - 1; ++cnt )
  {
    int left, right;
    cin >> left >> right;
    --left; --right;

    rvvLink[left].push_back( right );
    rvvLink[right].push_back( left );
  } 
}

StDist calcMaxDistance( const vector<vector<int>>& crvvLink, int startNode )
{
  int size = (int)crvvLink.size() / 2 + 1;
  vector<int> vDist( size, -1 );

  queue<int> qNode;
  qNode.push( startNode );
  vDist[startNode] = 0;

  while ( qNode.size() )
  {
    int fromNode = qNode.front(); qNode.pop();

    for ( int toNode : crvvLink[fromNode] )
      if ( vDist[toNode] == -1 )
      {
        qNode.push( toNode );
        vDist[toNode] = vDist[fromNode] + 1;
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
  int endfromNode0, end;

  StDist oDist = calcMaxDistance( vvLink, 0 );
  cout << calcMaxDistance( vvLink, oDist.m_node ).m_dist + 1 << endl;
  return 0;
}
