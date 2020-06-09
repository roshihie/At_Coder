#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnNode, vector<vector<int>>& rvvnEdge)
{
  int nNodeSiz, nEdgeSiz;
  cin >> nNodeSiz>> nEdgeSiz;
  rvnNode.resize(nNodeSiz);
//rvvnEdge.resize(nNodeSiz, vector<int>(nNodeSiz, 0));
  rvvnEdge.resize(nNodeSiz);   //２次元目 push_back

  for (int& rnNode : rvnNode)
    cin >> rnNode;

  for (int i = 0; i <= nEdgeSiz; i++)
  {
    int nLeft, nRigt;
    cin >> nLeft >> nRigt;
    rvvnEdge[ nLeft - 1 ].push_back( nRigt - 1 );
    rvvnEdge[ nRigt - 1 ].push_back( nLeft - 1 );
  }
}

int fnPeakCnt(const vector<int> cnrvnNode, const vector<vector<int>>& cnrvvnEdge)
{
  int nPeakCnt = 0;

  for (int nBgn = 0; nBgn < cnrvnNode.size(); nBgn++)
  {
    bool bPeak = true;

    for (int nEnd : cnrvvnEdge[nBgn])
      if (cnrvnNode[nBgn] <= cnrvnNode[nEnd])
      {
        bPeak = false;
        break;
      }

    if (bPeak) nPeakCnt++;
  }
  return nPeakCnt;
}
  
int main()
{
  vector<int> vnNode;
  vector<vector<int>> vvnEdge;

  fnInput(vnNode, vvnEdge);
  cout << fnPeakCnt(vnNode, vvnEdge) << endl;

  return 0;
}
