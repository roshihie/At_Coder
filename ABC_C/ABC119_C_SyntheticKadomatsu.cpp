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

void fnInput(StTrgLen& roTrgLen, vector<int>& rvnMatLen)
{
  int nMatLenSiz;
  cin >> nMatLenSiz >> roTrgLen.m_nLenA >> roTrgLen.m_nLenB >> roTrgLen.m_nLenC;
  rvnMatLen.resize(nMatLenSiz);

  for (int& rnMatLen : rvnMatLen)
    cin >> rnMatLen;
}

int fnDfs(int nDpth, StTrgLen oTrgLen, StMatrl& roMatrl, const vector<int>& cnrvnMatLen)
{
  if (nDpth == cnrvnMatLen.size())
    if ( roMatrl.m_nLenA && roMatrl.m_nLenB && roMatrl.m_nLenC )
      return  abs(oTrgLen.m_nLenA - roMatrl.m_nLenA)
            + abs(oTrgLen.m_nLenB - roMatrl.m_nLenB) 
            + abs(oTrgLen.m_nLenC - roMatrl.m_nLenC);
    else
      return 1 << 30; 

  int nMinMp = 0; 
  int nAddMp;

  nMinMp = fnDfs(nDpth + 1, oTrgLen, roMatrl, cnrvnMatLen);

  StMatrl oMatrlA(roMatrl);
  nAddMp = oMatrlA.m_nLenA ? 10 : 0;
  oMatrlA.m_nLenA += cnrvnMatLen[nDpth];
  nMinMp = min(nMinMp, fnDfs(nDpth + 1, oTrgLen, oMatrlA, cnrvnMatLen) + nAddMp);

  StMatrl oMatrlB(roMatrl);
  nAddMp = oMatrlB.m_nLenB ? 10 : 0;
  oMatrlB.m_nLenB += cnrvnMatLen[nDpth];
  nMinMp = min(nMinMp, fnDfs(nDpth + 1, oTrgLen, oMatrlB, cnrvnMatLen) + nAddMp);

  StMatrl oMatrlC(roMatrl);
  nAddMp = oMatrlC.m_nLenC ? 10 : 0;
  oMatrlC.m_nLenC += cnrvnMatLen[nDpth];
  nMinMp = min(nMinMp, fnDfs(nDpth + 1, oTrgLen, oMatrlC, cnrvnMatLen) + nAddMp);

  return nMinMp;
}

int fnMinCostTrgLen(StTrgLen oTrgLen, const vector<int>& cnrvnMatLen)
{
  StMatrl oMatrl;

  return fnDfs(0, oTrgLen, oMatrl, cnrvnMatLen);
}
 
int main()
{
  StTrgLen oTrgLen;
  vector<int> vnMatLen;

  fnInput(oTrgLen, vnMatLen);
  cout << fnMinCostTrgLen(oTrgLen, vnMatLen) << endl;

  return 0;
}
