#include <bits/stdc++.h>
using namespace std;

void input(int& rnAchieve, vector<int>& rvnPrice, vector<vector<int>>& rvvnSkill)
{
  int nPriceSiz, nSkillSiz;
  cin >> nPriceSiz >> nSkillSiz >> rnAchieve;
  rvnPrice.resize(nPriceSiz);
  rvvnSkill.resize(nPriceSiz, vector<int>(nSkillSiz));

  for (int ny = 0; ny < rvvnSkill.size(); ++ny)
  {
    cin >> rvnPrice[ny];

    for (int nx = 0; nx < rvvnSkill[ny].size(); ++nx)
      cin >> rvvnSkill[ny][nx];
  }
}

int calcMinPriceSkillup(int nAchieve, const vector<int>& cnrvnPrice, 
                                      const vector<vector<int>>& cnrvvnSkill)
{
  int nMinPrice = INT_MAX;

  for (int nBit = 0; nBit < ( 1 << cnrvnPrice.size() ); ++nBit)
  {
    int nSumPrice = 0;
    vector<int> vnSumSkill(cnrvvnSkill[0].size());

    for (int ny = 0; ny < cnrvnPrice.size(); ++ny)
      if (nBit & ( 1 << ny ))
      {
        for (int nx = 0; nx < cnrvvnSkill[ny].size(); ++nx)
          vnSumSkill[nx] += cnrvvnSkill[ny][nx];

        nSumPrice += cnrvnPrice[ny];
      }

    bool bRslt = true;

    for (int nSumSkill : vnSumSkill)
      if (nSumSkill < nAchieve)
      {
        bRslt = false;
        break;
      }

    if (bRslt)
      nMinPrice = min(nMinPrice, nSumPrice);
  }
  if (nMinPrice == INT_MAX)
    return -1;
  else
    return nMinPrice;
}
  
int main()
{
  int nAchieve;
  vector<int> vnPrice;
  vector<vector<int>> vvnSkill;

  input(nAchieve, vnPrice, vvnSkill);
  cout << calcMinPriceSkillup(nAchieve, vnPrice, vvnSkill) << endl;

  return 0;
}
