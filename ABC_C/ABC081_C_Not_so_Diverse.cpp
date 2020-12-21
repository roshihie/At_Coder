#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnBallCnt, int& rnVarie)
{
  int nBallSiz;
  cin >> nBallSiz >> rnVarie;
  rvnBallCnt.resize(nBallSiz);

  for (int nx = 0; nx < nBallSiz; ++nx)
  {
    int nBall;
    cin >> nBall;
    ++rvnBallCnt[nBall - 1];
  }
  sort(begin(rvnBallCnt), end(rvnBallCnt));
}

int calcRewCount(const vector<int>& cnrvnBallCnt, int nVarie)
{
  int nRewCnt = 0;

  for (int nx = 0; nx < cnrvnBallCnt.size() - nVarie; ++nx)
    nRewCnt += cnrvnBallCnt[nx];

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
