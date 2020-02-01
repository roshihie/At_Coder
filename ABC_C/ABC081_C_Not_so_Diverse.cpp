#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnBallCnt, int& rnVarie)
{
  int nBallSiz;
  cin >> nBallSiz >> rnVarie;

  rvnBallCnt.resize(nBallSiz);
  for (int i = 0; i < nBallSiz; i++)
  {
    int nBall;
    cin >> nBall;
    rvnBallCnt[nBall - 1]++;
  }
}

int fnRewCount(vector<int>& rvnBallCnt, int nVarie)
{
  sort(begin(rvnBallCnt), end(rvnBallCnt));
  int nRewCnt = 0;

  for (int i = 0; i < rvnBallCnt.size() - nVarie; i++)
    nRewCnt += rvnBallCnt[i];

  return nRewCnt;
}

int main()
{
  vector<int> vnBallCnt;
  int nVarie;

  fnInput(vnBallCnt, nVarie);
  cout << fnRewCount(vnBallCnt, nVarie) << endl;

  return 0;
}
