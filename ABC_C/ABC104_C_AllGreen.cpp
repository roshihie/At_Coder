#include <bits/stdc++.h>
using namespace std;

struct StPrblm
{
  StPrblm() : m_nPrbCnt(0), m_nPrbSpc(0) { }

  int m_nPrbCnt;
  int m_nPrbSpc;
};

void input(int& rnGoal, vector<StPrblm>& rvoPrblm)
{
  int nPrblmSiz;
  cin >> nPrblmSiz >> rnGoal;
  rvoPrblm.resize(nPrblmSiz);

  for (StPrblm& roPrblm : rvoPrblm)
    cin >> roPrblm.m_nPrbCnt >> roPrblm.m_nPrbSpc;
}

int calcMinSolveCnt(int nGoal, const vector<StPrblm>& cnrvoPrblm)
{
  int nMinSolveCnt = INT_MAX;

  for (int nBitPfect = 0; nBitPfect < ( 1 << cnrvoPrblm.size() ); ++nBitPfect)
  {
    int nSolvePntPfect = 0;
    int nSolveCntPfect = 0;
    int nEachPfect;

    for (nEachPfect = 0; nEachPfect < cnrvoPrblm.size(); ++nEachPfect)
      if (nBitPfect & ( 1 << nEachPfect ))
      {
        nSolveCntPfect += cnrvoPrblm[nEachPfect].m_nPrbCnt; 
        nSolvePntPfect += cnrvoPrblm[nEachPfect].m_nPrbCnt * (nEachPfect + 1) * 100
                        + cnrvoPrblm[nEachPfect].m_nPrbSpc;
      }

    if (nSolvePntPfect >= nGoal)
      nMinSolveCnt = min(nMinSolveCnt, nSolveCntPfect);
    else
    {
      int nSolvePntPtial = 0;
      int nSolveCntPtial = 0;

      for (int nBitPtial = 0; nBitPtial < ( 1 << cnrvoPrblm.size() ); ++nBitPtial)
      {
        int nEachPtial;
        bool bSkip = false;

        for (nEachPtial = cnrvoPrblm.size() - 1; nEachPtial >= 0; --nEachPtial)
          if (nBitPtial & ( 1 << nEachPfect )) 
          {
            bSkip = true;
            break;
          }
        if ( bSkip ) continue;

        for (nEachPtial = cnrvoPrblm.size() - 1; nEachPtial >= 0; --nEachPtial)
          if (nBitPtial & ( 1 << nEachPtial ))
            while ( nSolveCntPtial < cnrvoPrblm[nEachPtial].m_nPrbCnt - 1 &&
                    nSolvePntPfect + nSolvePntPtial < nGoal                  )
            {
              ++nSolveCntPtial;
              nSolvePntPtial += (nEachPtial + 1) * 100;
            }

        if (nSolvePntPfect + nSolvePntPtial >= nGoal)
        {
          nMinSolveCnt = min(nMinSolveCnt, nSolvePntPfect + nSolveCntPtial);
          break;
        }
      }
    }  
  }
  return nMinSolveCnt;
}

int main()
{
  int nGoal;
  vector<StPrblm> voPrblm;

  input(nGoal, voPrblm);
  cout << calcMinSolveCnt(nGoal, voPrblm) << endl;

  return 0;
}
