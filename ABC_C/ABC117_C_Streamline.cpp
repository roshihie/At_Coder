#include <bits/stdc++.h>
using namespace std;

void input(int& rnPicSiz, vector<int>& rvnCoordx)
{
  int nCoordxSiz;
  cin >> rnPicSiz >> nCoordxSiz;
  rvnCoordx.resize(nCoordxSiz);

  for (int& rnCoordx : rvnCoordx)
    cin >> rnCoordx;

  sort(begin(rvnCoordx), end(rvnCoordx));
}

int calcMinMoveCnt(int nPicSiz, const vector<int>& cnrvnCoordx)
{
  vector<int> vnDist;

  for (int nx = 0; nx < cnrvnCoordx.size() - 1; ++nx)
    vnDist.push_back( cnrvnCoordx[nx + 1] - cnrvnCoordx[nx] );

  sort(begin(vnDist), end(vnDist));
  int nMinMoveCnt = 0;

  for (int nx = 0; nx < (int)vnDist.size() - (nPicSiz - 1); ++nx)
    nMinMoveCnt += vnDist[nx];

  return nMinMoveCnt;
}
 
int main()
{
  int nPicSiz;
  vector<int> vnCoordx;

  input(nPicSiz, vnCoordx);
  cout << calcMinMoveCnt(nPicSiz, vnCoordx) << endl;

  return 0;
}
