#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;

struct StDish
{
  StDish() : m_dish1(0), m_dish2(0) { }

  int m_dish1;
  int m_dish2;
};

void input(int& rmaxDish, vector<StDish>& rvCond, vector<StDish>& rvMan)
{
  int sizCond;
  cin >> rmaxDish >> sizCond;
  rvCond.resize(sizCond);

  for (StDish& roCond : rvCond)
  {
    cin >> roCond.m_dish1 >> roCond.m_dish2;
    --roCond.m_dish1, --roCond.m_dish2;
  }

  int sizMan;
  cin >> sizMan;
  rvMan.resize(sizMan);

  for (StDish& roMan : rvMan)
  {
    cin >> roMan.m_dish1 >> roMan.m_dish2;
    --roMan.m_dish1, --roMan.m_dish2;
  }
}

int calcEachPoint(const vector<StDish>& crvCond,
                  const vector<int>& crvOnDish  )
{
  int eachPoint = 0;

  for (uint nx = 0; nx < crvCond.size(); ++nx)
    if ( crvOnDish[ crvCond[nx].m_dish1 ] &&
         crvOnDish[ crvCond[nx].m_dish2 ]   )
      ++eachPoint;

  return eachPoint;
}

int calcMaxPoint(int maxDish,
                 const vector<StDish>& crvCond, 
                 const vector<StDish> crvMan   )
{
  int maxPoint = 0;

  for (int bit = 0; bit < ( 1 << crvMan.size() ); ++bit)
  {
    vector<int> vOnDish( maxDish ); 

    for (uint each = 0; each < crvMan.size(); ++each)
      if ( bit & ( 1 << each))
        ++vOnDish[ crvMan[each].m_dish1 ];
      else
        ++vOnDish[ crvMan[each].m_dish2 ];

    maxPoint = max( maxPoint, calcEachPoint(crvCond, vOnDish) );
  }

  return maxPoint;
}
  
int main()
{
  int maxDish;
  vector<StDish> vCond, vMan;

  input(maxDish, vCond, vMan);
  cout << calcMaxPoint(maxDish, vCond, vMan);

  return 0;
}
