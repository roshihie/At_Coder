#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnBall, int& rnVarie)
{
  int nBallSiz;
  cin >> nBallSiz >> rnVarie;

  rvnBall.resize(nBallSiz);
  for (int& rnBall : rvnBall)
    cin >> rnBall;
}

int fnRewCount(const vector<int>& cnrvnBall, int nVarie)
{
  map<int, int> mpBall;

  for (int nBall : cnrvnBall)
    mpBall[nBall]++;

  vector<int> vnNum;
  for (pair<const int, int> PBall : mpBall)
    vnNum.push_back(PBall.second);

  int nRewCnt = 0;
  sort(begin(vnNum), end(vnNum), greater<int>());
  if (vnNum.size() <= nVarie)
    nRewCnt = 0;
  else
    for (int i = nVarie; i < vnNum.size(); i++)
      nRewCnt += vnNum[i];

  return nRewCnt;
}

int main()
{
  vector<int> vnBall;
  int nVarie;
  fnInput(vnBall, nVarie);
  cout << fnRewCount(vnBall, nVarie) << endl;

  return 0;
}
