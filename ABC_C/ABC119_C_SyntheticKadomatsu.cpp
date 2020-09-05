#include <bits/stdc++.h>
using namespace std;

struct StTrgLen
{
  StTrgLen() : m_nLenA(0), m_nLenB(0), m_nLenC(0) { }

  int m_nLenA;
  int m_nLenB;
  int m_nLenC;
};

struct StMatrl
{
  StMatrl() : m_nLenA(0), m_nLenB(0), m_nLenC(0) { }

  int m_nLenA;
  int m_nLenB;
  int m_nLenC;
};

void input(StTrgLen& roTrgLen, vector<int>& rvnMatLen)
{
  int nMatLenSiz;
  cin >> nMatLenSiz >> roTrgLen.m_nLenA >> roTrgLen.m_nLenB >> roTrgLen.m_nLenC;
  rvnMatLen.resize(nMatLenSiz);

  for (int& rnMatLen : rvnMatLen)
    cin >> rnMatLen;
}

int dfs(int nDpth, StTrgLen oTrgLen, StMatrl oMatrl, const vector<int>& cnrvnMatLen)
{
  if (nDpth == cnrvnMatLen.size())
    if ( oMatrl.m_nLenA && oMatrl.m_nLenB && oMatrl.m_nLenC )
      return  abs(oTrgLen.m_nLenA - oMatrl.m_nLenA)
            + abs(oTrgLen.m_nLenB - oMatrl.m_nLenB) 
            + abs(oTrgLen.m_nLenC - oMatrl.m_nLenC);
    else
      return 1 << 30; 

  int nMinMp = 0; 
  int nAddMp;

  nMinMp = dfs(nDpth + 1, oTrgLen, oMatrl, cnrvnMatLen);

  StMatrl oMatrlA(oMatrl);
  nAddMp = oMatrlA.m_nLenA ? 10 : 0;
  oMatrlA.m_nLenA += cnrvnMatLen[nDpth];
  nMinMp = min(nMinMp, dfs(nDpth + 1, oTrgLen, oMatrlA, cnrvnMatLen) + nAddMp);

  StMatrl oMatrlB(oMatrl);
  nAddMp = oMatrlB.m_nLenB ? 10 : 0;
  oMatrlB.m_nLenB += cnrvnMatLen[nDpth];
  nMinMp = min(nMinMp, dfs(nDpth + 1, oTrgLen, oMatrlB, cnrvnMatLen) + nAddMp);

  StMatrl oMatrlC(oMatrl);
  nAddMp = oMatrlC.m_nLenC ? 10 : 0;
  oMatrlC.m_nLenC += cnrvnMatLen[nDpth];
  nMinMp = min(nMinMp, dfs(nDpth + 1, oTrgLen, oMatrlC, cnrvnMatLen) + nAddMp);

  return nMinMp;
}

int calcMinCostTrgLen(StTrgLen oTrgLen, const vector<int>& cnrvnMatLen)
{
  StMatrl oMatrl;

  return dfs(0, oTrgLen, oMatrl, cnrvnMatLen);
}
 
int main()
{
  StTrgLen oTrgLen;
  vector<int> vnMatLen;

  input(oTrgLen, vnMatLen);
  cout << calcMinCostTrgLen(oTrgLen, vnMatLen) << endl;

  return 0;
}
