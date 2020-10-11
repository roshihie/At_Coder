#include <bits/stdc++.h>
using namespace std;

void input(int& rnMember, int& rnScore, vector<int>& rvnAnsMem)
{
  int nAnsSiz;
  cin >> rnMember >> rnScore >> nAnsSiz;

  rvnAnsMem.resize(nAnsSiz);
  for (int& rnAnsMem : rvnAnsMem)
    cin >> rnAnsMem;
}

void calcWinLoss(int nMember, int nScore, const vector<int>& cnrvnAnsMem)
{
  vector<int> vnMemScore(nMember, nScore - cnrvnAnsMem.size() );

  for (int nAnsMem : cnrvnAnsMem)
    ++vnMemScore[ nAnsMem - 1 ];

  for (int nMemScore : vnMemScore)
    if (nMemScore > 0) cout << "Yes" << endl;
    else               cout << "No"  << endl;
}

int main()
{
  int nMember, nScore;
  vector<int> vnAnsMem;

  input(nMember, nScore, vnAnsMem);
  calcWinLoss(nMember, nScore, vnAnsMem);

  return 0;
}
