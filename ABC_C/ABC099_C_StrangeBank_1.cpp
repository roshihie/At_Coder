#include <bits/stdc++.h>
using namespace std;

void input(int& rnCash)
{
  cin >> rnCash;
}

int calcOpeCnt(int nCash)
{
  //                           最大値に nCash 指定
  vector<int> vnDPExg(nCash + 1, nCash);
  vnDPExg[0] = 0;

  for (int nx = 0; nx <= nCash; ++nx)
  {
    for (int ny = 1; nx + ny <= nCash; ny *= 6)
      vnDPExg[nx + ny] = min(vnDPExg[nx + ny], vnDPExg[nx] + 1);

    for (int ny = 1; nx + ny <= nCash; ny *= 9)
      vnDPExg[nx + ny] = min(vnDPExg[nx + ny], vnDPExg[nx] + 1);
  }
  return vnDPExg[nCash];
}

int main()
{
  int nCash; 
  input(nCash);
  cout << calcOpeCnt(nCash) << endl;

  return 0;
}
