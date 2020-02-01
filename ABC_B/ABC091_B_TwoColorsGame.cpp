#include <bits/stdc++.h>
using namespace std;

void fnInput(map<string, int>& rmpScore)
{
  int nBluelSiz;
  cin >> nBluelSiz;

  for (int i = 0; i < nBluelSiz; i++)
  {
    string sBlueStr;
    cin >> sBlueStr;
    rmpScore[sBlueStr]++;
  }

  int nRedSiz;
  cin >> nRedSiz;

  for (int i = 0; i < nRedSiz; i++)
  {
    string sRedStr;
    cin >> sRedStr;
    rmpScore[sRedStr]--;
  }
}

int fnScoreCheck(const map<string, int>& cnrmpScore)
{
  int nMaxScore = 0;
  for (pair<const string, int> PScore : cnrmpScore)
    nMaxScore = max(nMaxScore, PScore.second);

  return nMaxScore;
}

int main()
{
  map<string, int> mpScore;

  fnInput(mpScore);
  cout << fnScoreCheck(mpScore) << endl;

  return 0;
}
