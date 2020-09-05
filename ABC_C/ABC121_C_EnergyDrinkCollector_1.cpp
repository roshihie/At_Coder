#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StGoods
{
  StGoods() : m_nPrice(0), m_nNum(0) { }

  int m_nPrice;
  int m_nNum;

  bool operator<(const StGoods& rhs) const
  {
    return m_nPrice < rhs.m_nPrice;
  }
};

void input(int& rnTrgNum, vector<StGoods>& rvoGoods)
{
  int nGoodsSiz;
  cin >> nGoodsSiz >> rnTrgNum;
  rvoGoods.resize(nGoodsSiz);

  for (StGoods& roGoods : rvoGoods)
    cin >> roGoods.m_nPrice >> roGoods.m_nNum;
}

llong calcMinCost(int nTrgNum, vector<StGoods>& rvoGoods)
{
  sort(begin(rvoGoods), end(rvoGoods));

  llong nCost = 0;

  for (StGoods oGoods : rvoGoods)
  {
    int nUsedNum = min(nTrgNum, oGoods.m_nNum);
    nCost += (llong)oGoods.m_nPrice * nUsedNum;
    nTrgNum -= nUsedNum;

    if ( !nTrgNum ) break;
  }
  return nCost;
}
 
int main()
{
  int nTrgNum;
  vector<StGoods> voGoods;

  input(nTrgNum, voGoods);
  cout << calcMinCost(nTrgNum, voGoods) << endl;

  return 0;
}
