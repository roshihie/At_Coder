#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnBallCnt, int& rnVarie)
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

int calcRewCount(vector<int>& rvnBallCnt, int nVarie)
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

  input(vnBallCnt, nVarie);
  cout << calcRewCount(vnBallCnt, nVarie) << endl;

  return 0;
}
