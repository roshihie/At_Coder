#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnCard)
{
  int nCardSiz;
  cin >> nCardSiz;

  rvnCard.resize(nCardSiz);
  for (int i = 0; i < nCardSiz; i++)
    cin >> rvnCard[i];

  sort(begin(rvnCard), end(rvnCard), greater<int>() );
}

int fnGameExec(const vector<int>& cnrvnCard)
{
  int nAlicePnt = 0, nBobPnt = 0;

  for (int i = 0; i < cnrvnCard.size(); i++)
  {
    if (i % 2 == 0)
      nAlicePnt += cnrvnCard[i];
    else
      nBobPnt  += cnrvnCard[i];
  }

  return (nAlicePnt - nBobPnt);
}

int main()
{
  vector<int> vnCard;
  fnInput(vnCard);
  cout << fnGameExec(vnCard) << endl;

  return 0;
}
