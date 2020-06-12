#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnAchieve, vector<int>& rvnPrice, vector<vector<int>>& rvvnSkill)
{
  int nPriceSiz, nSkillSiz;
  cin >> nPriceSiz >> nSkillSiz >> rnAchieve;
  rvnPrice.resize(nPriceSiz);
  rvvnSkill.resize(nPriceSiz, vector<int>(nSkillSiz));

  for (int i = 0; i < rvvnSkill.size(); i++)
  {
    cin >> rvnPrice[i];

    for (int j = 0; j < rvvnSkill[i].size(); j++)
      cin >> rvvnSkill[i][j];
  }
}

int fnMinPriceSkillup(int nAchieve, const vector<int> cnrvnPrice, 
                      const vector<vector<int>>& cnrvvnSkill)
{
  int nMinPrice = INT_MAX;

  for (int nCtl = 0; nCtl < (1 << cnrvnPrice.size()); nCtl++)
  {
    int nPrice = 0;
    vector<int> vnSumSkill(cnrvvnSkill[0].size());

    for (int ny = 0; ny < cnrvnPrice.size(); ny++)
      if (nCtl & (1 << ny))
      {
        for (int nx = 0; nx < cnrvvnSkill[ny].size(); nx++)
          vnSumSkill[nx] += cnrvvnSkill[ny][nx];

        nPrice += cnrvnPrice[ny];
      }

    bool bRslt = true;

    for (int nSumSkill : vnSumSkill)
      if (nSumSkill < nAchieve)
      {
        bRslt = false;
        break;
      }

    if (bRslt)
      nMinPrice = min(nMinPrice, nPrice);
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

  fnInput(nAchieve, vnPrice, vvnSkill);
  cout << fnMinPriceSkillup(nAchieve, vnPrice, vvnSkill) << endl;

  return 0;
}
