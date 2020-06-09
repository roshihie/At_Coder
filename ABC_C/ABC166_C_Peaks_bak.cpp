#include <bits/stdc++.h>
using namespace std;

struct StEdge
{
  StEdge() :
    m_nBgn(0), m_nEnd(0) { }

  int m_nBgn;
  int m_nEnd;
};

void fnInput(vector<int>& rvnNode, vector<StEdge>& rvoEdge)
{
  int nNodeSiz, nEdgeSiz;
  cin >> nNodeSiz>> nEdgeSiz;
  rvnNode.resize(nNodeSiz);
  rvoEdge.resize(nEdgeSiz);

  for (int& rnNode : rvnNode)
    cin >> rnNode;

  for (StEdge& roEdge : rvoEdge)
    cin >> roEdge.m_nBgn >> roEdge.m_nEnd;

}

int fnPeakCnt(const vector<int> cnrvnNode, const vector<StEdge>& cnrvoEdge)
{
  vector<vector<int>> vvnEdge(cnrvnNode.size(), vector<int>(cnrvnNode.size(), -1));

  for (StEdge oEdge : cnrvoEdge)
    if (cnrvnNode[ oEdge.m_nBgn - 1] > cnrvnNode[ oEdge.m_nEnd - 1])
    {
      vvnEdge[ oEdge.m_nBgn - 1 ][ oEdge.m_nEnd - 1 ] = 1;
      vvnEdge[ oEdge.m_nEnd - 1 ][ oEdge.m_nBgn - 1 ] = 0;
    }
    else if (cnrvnNode[ oEdge.m_nBgn - 1] < cnrvnNode[ oEdge.m_nEnd - 1])
    {
      vvnEdge[ oEdge.m_nBgn - 1 ][ oEdge.m_nEnd - 1 ] = 0;
      vvnEdge[ oEdge.m_nEnd - 1 ][ oEdge.m_nBgn - 1 ] = 1;
    }
    else
    {
      vvnEdge[ oEdge.m_nBgn - 1 ][ oEdge.m_nEnd - 1 ] = 0;
      vvnEdge[ oEdge.m_nEnd - 1 ][ oEdge.m_nBgn - 1 ] = 0;
    }

  int nPeakCnt = 0;

  for (int i = 0; i < vvnEdge.size(); i++)
  {
    bool bPeak = true;

    for (int j = 0; j < vvnEdge[i].size(); j++)
      if (vvnEdge[i][j] == 0) 
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
  vector<StEdge> voEdge;

  fnInput(vnNode, voEdge);
  cout << fnPeakCnt(vnNode, voEdge) << endl;

  return 0;
}
