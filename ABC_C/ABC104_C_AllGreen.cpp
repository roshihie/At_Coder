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
    int nCntPfect = 0;
    int nPntPfect = 0;
    int nEachPfect;

    for (nEachPfect = 0; nEachPfect < cnrvoPrblm.size(); ++nEachPfect)
      if (nBitPfect & ( 1 << nEachPfect ))
      {
        nCntPfect += cnrvoPrblm[nEachPfect].m_nPrbCnt; 
        nPntPfect += cnrvoPrblm[nEachPfect].m_nPrbCnt * (nEachPfect + 1) * 100
                        + cnrvoPrblm[nEachPfect].m_nPrbSpc;
      }

    if (nPntPfect >= nGoal)
      nMinSolveCnt = min(nMinSolveCnt, nCntPfect);
    else
    {
      for (int nBitPtial = 0; nBitPtial < ( 1 << cnrvoPrblm.size() ); ++nBitPtial)
      {
        int nCntPtial = 0;
        int nPntPtial = 0;
        int nEachPtial;
        bool bSkip = false;

        for (nEachPtial = cnrvoPrblm.size() - 1; nEachPtial >= 0; --nEachPtial)
          if ( nBitPtial & ( 1 << nEachPtial ) &&
               nBitPfect & ( 1 << nEachPtial )   ) 
          {
            bSkip = true;
            break;
          }
        if ( bSkip ) continue;

        for (nEachPtial = cnrvoPrblm.size() - 1; nEachPtial >= 0; --nEachPtial)
          if (nBitPtial & ( 1 << nEachPtial ))
          {
            int nCurCnt;

            for (nCurCnt = 1; nCurCnt < cnrvoPrblm[nEachPtial].m_nPrbCnt; ++nCurCnt)
            {
              nPntPtial += (nEachPtial + 1) * 100;

              if (nPntPfect + nPntPtial >= nGoal)
              {
                nCntPtial += nCurCnt;
                nMinSolveCnt = min(nMinSolveCnt, nCntPfect + nCntPtial);
                break;
              }
            }
            if (nPntPfect + nPntPtial >= nGoal)
              break;
            else
              nCntPtial += nCurCnt - 1;
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
