#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> vvAB;

struct StRtnDist
{
  StRtnDist() : m_node(0), m_dist(0) { }

  int m_node;      // 最大距離の node
  int m_dist;      // 最大距離
};

void input()
{
  cin >> N;
  vvAB.resize( (N - 1) * 2 );
  int from, to;

  for ( int cnt = 0; cnt < N - 1; ++cnt )
  {
    cin >> from >> to;
    --from, --to;

    vvAB[from].push_back( to );
    vvAB[ to ].push_back( from ); 
  }
}

StRtnDist calcMaxDistance( int startNode )
{
  vector<int> vDist( N, -1 );
  vDist[startNode] = 0;

  queue<int> qNode;
  qNode.push( startNode );
  
  while ( qNode.size() )
  {
    int from = qNode.front(); qNode.pop();

    for ( int to : vvAB[from] )
      if ( vDist[to] == -1 )
      {
        vDist[to] = vDist[from] + 1;
        qNode.push( to );
      }
  }

  auto itMax = max_element( begin(vDist), end(vDist));
  StRtnDist oRtnDist;
  oRtnDist.m_node = distance( begin(vDist), itMax );
  oRtnDist.m_dist = *itMax;
  return oRtnDist;
}
  
int main()
{
  input();
  StRtnDist oRtnDist = calcMaxDistance( 0 );
  cout << calcMaxDistance( oRtnDist.m_node ).m_dist + 1 << endl;
  
  return 0;
}
