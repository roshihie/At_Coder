#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StGoods
{
  StGoods() : m_nPrice(0), m_nNum(0) { }

  int m_nPrice;
  int m_nNum;
};

void input(int& rnTrgNum, vector<StGoods>& rvoGoods)
{
  int nGoodsSiz;
  cin >> nGoodsSiz >> rnTrgNum;
  rvoGoods.resize(nGoodsSiz);

  for (StGoods& roGoods : rvoGoods)
    cin >> roGoods.m_nPrice >> roGoods.m_nNum;
}

llong calcMinCost(int nTrgNum, const vector<StGoods>& cnrvoGoods)
{
  map<int, int> mpGoods;

  for (StGoods oGoods : cnrvoGoods)
    mpGoods[ oGoods.m_nPrice ] += oGoods.m_nNum;

  llong nCost = 0;

  for (auto PGoods : mpGoods)
  {
    int nUsedNum = min(nTrgNum, PGoods.second);
    nCost += (llong)PGoods.first * nUsedNum;
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
