#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNode, vector<vector<int>>& rvvnEdge)
{
  int nNodeSiz, nEdgeSiz;
  cin >> nNodeSiz>> nEdgeSiz;
  rvnNode.resize(nNodeSiz);
//rvvnEdge.resize(nNodeSiz, vector<int>(nNodeSiz, 0));
  rvvnEdge.resize(nNodeSiz);   //２次元目 push_back

  for (int& rnNode : rvnNode)
    cin >> rnNode;

  for (int nx = 0; nx < nEdgeSiz; ++nx)
  {
    int nLeft, nRigt;
    cin >> nLeft >> nRigt;
    --nLeft; --nRigt;
    rvvnEdge[ nLeft ].push_back( nRigt );
    rvvnEdge[ nRigt ].push_back( nLeft );
  }
}

int calcGoodPeaks(const vector<int> cnrvnNode, const vector<vector<int>>& cnrvvnEdge)
{
  int nGoodPeaks = 0;

  for (int nBgn = 0; nBgn < cnrvnNode.size(); ++nBgn)
  {
    bool bPeak = true;

    for (int nEnd : cnrvvnEdge[nBgn])
      if (cnrvnNode[nBgn] <= cnrvnNode[nEnd])
      {
        bPeak = false;
        break;
      }

    if (bPeak) ++nGoodPeaks;
  }
  return nGoodPeaks;
}
  
int main()
{
  vector<int> vnNode;
  vector<vector<int>> vvnEdge;

  input(vnNode, vvnEdge);
  cout << calcGoodPeaks(vnNode, vvnEdge) << endl;

  return 0;
}
