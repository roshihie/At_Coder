#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnMember, int& rnScore, vector<int>& rvnAnsMem)
{
  int nMemSiz, nAnsSiz;
  cin >> rnMember >> rnScore >> nAnsSiz;

  rvnAnsMem.resize(nAnsSiz);
  for (int& rnAnsMem : rvnAnsMem)
    cin >> rnAnsMem;
}

void fnScoreCheck(int nMember, int nScore, const vector<int>& cnrvnAnsMem)
{
  vector<int> vnMemScore(nMember + 1, nScore - cnrvnAnsMem.size());

  for (int nAnsMem : cnrvnAnsMem)
    vnMemScore[ nAnsMem ]++;

  for (int i = 1; i <vnMemScore.size(); i++)
    if (vnMemScore[i] > 0) cout << "Yes" << endl;
    else                   cout << "No"  << endl;
}

int main()
{
  int nMember, nScore;
  vector<int> vnAnsMem;

  fnInput(nMember, nScore, vnAnsMem);
  fnScoreCheck(nMember, nScore, vnAnsMem);

  return 0;
}
