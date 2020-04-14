#include <bits/stdc++.h>
using namespace std;

struct StAnsHist
{
  StAnsHist() : m_nProblmNo(0), m_sJudge("") { }

  int    m_nProblmNo;
  string m_sJudge;
};

void fnInput(int& rnProblmSiz, vector<StAnsHist>& rvoAnsHist)
{
  int nSubmitSiz;
  cin >> rnProblmSiz >> nSubmitSiz;
  rvoAnsHist.resize(nSubmitSiz);

  for (StAnsHist& roAnsHist : rvoAnsHist)
    cin >> roAnsHist.m_nProblmNo >> roAnsHist.m_sJudge;
}
  
void fnAnserCheck(int nProblmSiz, const vector<StAnsHist>& cnrvoAnsHist, 
                  int& rnRightAns, int& rnPenalty)
{
  vector<int> vnWACnt(nProblmSiz + 1);
  set<int> seRightAns;

  rnRightAns = 0;
  rnPenalty = 0;

  for (StAnsHist oAnsHist : cnrvoAnsHist)
    if (oAnsHist.m_sJudge == "AC")
      seRightAns.insert( oAnsHist.m_nProblmNo );
    else
      if (!seRightAns.count( oAnsHist.m_nProblmNo ))
        vnWACnt[ oAnsHist.m_nProblmNo ]++;

  rnRightAns = seRightAns.size();

  for (int nRightAns : seRightAns)
    rnPenalty += vnWACnt[nRightAns]; 
}
  
int main()
{
  int nProblmSiz;
  vector<StAnsHist> voAnsHist;
  fnInput(nProblmSiz, voAnsHist);

  int nRightAns, nPenalty;
  fnAnserCheck(nProblmSiz, voAnsHist, nRightAns, nPenalty);

  cout << nRightAns << " " << nPenalty;
  return 0;
}
