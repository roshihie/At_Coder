#include <bits/stdc++.h>
using namespace std;

struct StDish
{
  StDish() : m_nDish1(0), m_nDish2(0) { }

  int m_nDish1;
  int m_nDish2;
};

void input(int& rnDishSiz, vector<StDish>& rvoCond, 
                           vector<StDish>& rvoPutDish)
{
  int nCondSiz;
  cin >> rnDishSiz >> nCondSiz;
  rvoCond.resize(nCondSiz);

  for (StDish& roCond : rvoCond)
  {
    cin >> roCond.m_nDish1 >> roCond.m_nDish2;
    --roCond.m_nDish1; --roCond.m_nDish2;
  }

  int nPutDishSiz;
  cin >> nPutDishSiz;
  rvoPutDish.resize(nPutDishSiz);

  for (StDish& roPutDish : rvoPutDish)
  {
    cin >> roPutDish.m_nDish1 >> roPutDish.m_nDish2;
    --roPutDish.m_nDish1; --roPutDish.m_nDish2;
  }
}

int calcMeetCond(const vector<StDish>& cnrvoCond,
                 const vector<int>& cnrvnSelDish)
{
  int nMeetCond = 0;

  for (StDish oCond : cnrvoCond)
    if ( cnrvnSelDish[ oCond.m_nDish1 ] &&
         cnrvnSelDish[ oCond.m_nDish2 ]    )
      ++nMeetCond;

  return nMeetCond;
}

int calcMaxMeetCond(int nDishSiz, const vector<StDish>& cnrvoCond,
                                  const vector<StDish>& cnrvoPutDish)
{
  int nMaxMeetCond = 0;

  for (int nBit = 0; nBit < ( 1 << cnrvoPutDish.size() ); ++nBit)
  {
    vector<int> vnSelDish(nDishSiz);

    for (int nEach = 0; nEach < cnrvoPutDish.size(); ++nEach)
      if ( nBit & ( 1 << nEach ) )
        vnSelDish[ cnrvoPutDish[nEach].m_nDish2 ] = 1;
      else
        vnSelDish[ cnrvoPutDish[nEach].m_nDish1 ] = 1;
      
    int nMeetCond = calcMeetCond(cnrvoCond, vnSelDish);
    nMaxMeetCond = max(nMaxMeetCond, nMeetCond);
  }
  return nMaxMeetCond;
}
  
int main()
{
  int nDishSiz;
  vector<StDish> voCond, voPutDish;

  input(nDishSiz, voCond, voPutDish);
  cout << calcMaxMeetCond(nDishSiz, voCond, voPutDish) << endl;

  return 0;
}
