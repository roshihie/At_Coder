#include <bits/stdc++.h>
using namespace std;

struct StAnsHist
{
  StAnsHist() : m_nProbNo(0), m_sJudge("") { }

  int    m_nProbNo;
  string m_sJudge;
};

void input(int& rnProbSiz, vector<StAnsHist>& rvoAnsHist)
{
  int nSubmitSiz;
  cin >> rnProbSiz >> nSubmitSiz;
  rvoAnsHist.resize(nSubmitSiz);

  for (StAnsHist& roAnsHist : rvoAnsHist)
  {
    cin >> roAnsHist.m_nProbNo >> roAnsHist.m_sJudge;
    --roAnsHist.m_nProbNo;
  }
}
  
void calcNumOfAnser(int nProbSiz, const vector<StAnsHist>& cnrvoAnsHist, 
                    int& rnRightAns, int& rnPenalty)
{
  vector<int> vnWACnt(nProbSiz);
  set<int> seRightAns;

  rnRightAns = 0;
  rnPenalty = 0;

  for (StAnsHist oAnsHist : cnrvoAnsHist)
    if (oAnsHist.m_sJudge == "AC")
      seRightAns.insert( oAnsHist.m_nProbNo );
    else
      if ( !seRightAns.count( oAnsHist.m_nProbNo ) )
        ++vnWACnt[ oAnsHist.m_nProbNo ];

  rnRightAns = seRightAns.size();

  for (int nRightAns : seRightAns)
    rnPenalty += vnWACnt[nRightAns]; 
}
  
int main()
{
  int nProbSiz;
  vector<StAnsHist> voAnsHist;
  input(nProbSiz, voAnsHist);

  int nRightAns, nPenalty;
  calcNumOfAnser(nProbSiz, voAnsHist, nRightAns, nPenalty);

  cout << nRightAns << " " << nPenalty;
  return 0;
}
