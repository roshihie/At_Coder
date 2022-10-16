#include <bits/stdc++.h>
using namespace std;

struct StDish
{
  StDish() : m_dish1(0), m_dish2(0) { }

  int m_dish1;
  int m_dish2;
};

void input(int& rsizDish, 
           vector<StDish>& rvCond, 
           vector<StDish>& rvMan  )
{
  int sizCond;
  cin >> rsizDish >> sizCond;
  rvCond.resize(sizCond);

  for ( StDish& roCond : rvCond )
  {
    cin >> roCond.m_dish1 >> roCond.m_dish2;
    --roCond.m_dish1, --roCond.m_dish2;
  }
  int sizMan;
  cin >> sizMan;
  rvMan.resize(sizMan);

  for ( StDish& roMan : rvMan )
  {
    cin >> roMan.m_dish1 >> roMan.m_dish2;
    --roMan.m_dish1, --roMan.m_dish2;
  }
}

int calcEachPoint(const vector<StDish>& crvCond,
                  const vector<int>& crvOnDish  )
{
  int eachPoint = 0;

  for ( StDish oCond : crvCond )
    if ( crvOnDish[ oCond.m_dish1 ] &&
         crvOnDish[ oCond.m_dish2 ]   )
      ++eachPoint;

  return eachPoint;
}

int calcMaxPoint(int sizDish,
                 const vector<StDish>& crvCond, 
                 const vector<StDish>& crvMan  )
{
  int maxPoint = 0;

  for (int bit = 0; bit < ( 1 << crvMan.size() ); ++bit)
  {
    vector<int> vOnDish(sizDish);

    for (int each = 0; each < (int)crvMan.size(); ++each)
    {
      if ( bit & ( 1 << each) )
        vOnDish[ crvMan[each].m_dish1 ] = 1;
      else
        vOnDish[ crvMan[each].m_dish2 ] = 1;
    }
    int eachPoint = calcEachPoint(crvCond, vOnDish);
    maxPoint = max(maxPoint, eachPoint);
  }
  return maxPoint;
}
  
int main()
{
  int sizDish;
  vector<StDish> vCond, vMan;

  input(sizDish, vCond, vMan);
  cout << calcMaxPoint(sizDish, vCond, vMan);

  return 0;
}
