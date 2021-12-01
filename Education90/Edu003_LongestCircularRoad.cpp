#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnLink)
{
  int nLinkSiz;
  cin >> nLinkSiz;
  rvvnLink.resize( (nLinkSiz - 1) * 2 );

  for (int nCnt = 0; nCnt < nLinkSiz - 1; ++nCnt)
  {
    int nFromNode, nToNode;
    cin >> nFromNode >> nToNode;
    --nFromNode; --nToNode;

    rvvnLink[nFromNode].push_back( nToNode );
    rvvnLink[nToNode].push_back( nFromNode );
  } 
}

int calcMaxDistance(const vector<vector<int>>& cnrvvnLink, int nStart, int& rnEnd)
{
  int nSize = (int)cnrvvnLink.size();
  int nMaxDistance = 0;
  vector<vector<int>> vvnPassed(nSize, vector<int> (nSize) );

  queue<int> qnNode;
  qnNode.push( nStart );

  while ( qnNode.size() )
  {
    int nFromNode = qnNode.front(); qnNode.pop();
    int n1st = 0;

    for (int nToNode : cnrvvnLink[nFromNode])
    {
      if ( !vvnPassed[nFromNode][nToNode] )
      {
        qnNode.push( nToNode );
        rnEnd = nToNode;

        if ( !n1st++ ) ++nMaxDistance;
      }
      vvnPassed[nFromNode][nToNode] = vvnPassed[nToNode][nFromNode] = 1;
    }
  }
  return nMaxDistance;
}
  
int main()
{
  vector<vector<int>> vvnLink;

  input(vvnLink);
  int nEnd_From0, nEnd;

  calcMaxDistance(vvnLink, 0, nEnd_From0);
  cout << calcMaxDistance(vvnLink, nEnd_From0, nEnd) + 1 << endl;
  return 0;
}
