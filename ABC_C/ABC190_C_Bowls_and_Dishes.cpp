#include <bits/stdc++.h>
using namespace std;

struct StCond
{
  StCond() : m_nDish1(0), m_nDish2(0) { }

  int m_nDish1;
  int m_nDish2;
};

void input(int& rnDishSiz, vector<StCond>& rvoCond, 
                           vector<StCond>& rvoStatmnt)
{
  int nCondSiz;
  cin >> rnDishSiz >> nCondSiz;
  rvoCond.resize(nCondSiz);

  for (StCond& roCond : rvoCond)
  {
    cin >> roCond.m_nDish1 >> roCond.m_nDish2;
    --roCond.m_nDish1; --roCond.m_nDish2;
  }

  int nStatmntSiz;
  cin >> nStatmntSiz;
  rvoStatmnt.resize(nStatmntSiz);

  for (StCond& roStatmnt : rvoStatmnt)
  {
    cin >> roStatmnt.m_nDish1 >> roStatmnt.m_nDish2;
    --roStatmnt.m_nDish1; --roStatmnt.m_nDish2;
  }
}

int calcMeetCond(const vector<StCond>& cnrvoCond,
                 const vector<int>& cnrvnBowlDish)
{
  int nMeetCond = 0;

  for (StCond oCond : cnrvoCond)
    if ( cnrvnBowlDish[ oCond.m_nDish1 ] &&
         cnrvnBowlDish[ oCond.m_nDish2 ]    )
      ++nMeetCond;

  return nMeetCond;
}

int calcMaxMeetCond(int nDishSiz, const vector<StCond>& cnrvoCond,
                                  const vector<StCond>& cnrvoStatmnt)
{
  int nMaxMeetCond = 0;

  for (int nBit = 0; nBit < ( 1 << cnrvoStatmnt.size() ); ++nBit)
  {
    vector<int> vnBowlDish(nDishSiz);

    for (int nEach = 0; nEach < cnrvoStatmnt.size(); ++nEach)
      if ( nBit & ( 1 << nEach ) )
        vnBowlDish[ cnrvoStatmnt[nEach].m_nDish2 ] = 1;
      else
        vnBowlDish[ cnrvoStatmnt[nEach].m_nDish1 ] = 1;
      
    int nMeetCond = calcMeetCond(cnrvoCond, vnBowlDish);
    nMaxMeetCond = max(nMaxMeetCond, nMeetCond);
  }
  return nMaxMeetCond;
}
  
int main()
{
  int nDishSiz;
  vector<StCond> voCond, voStatmnt;

  input(nDishSiz, voCond, voStatmnt);
  cout << calcMaxMeetCond(nDishSiz, voCond, voStatmnt) << endl;

  return 0;
}
