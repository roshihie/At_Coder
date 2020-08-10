#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnPicSiz, vector<int>& rvnCoordx)
{
  int nCoordxSiz;
  cin >> rnPicSiz >> nCoordxSiz;
  rvnCoordx.resize(nCoordxSiz);

  for (int& rnCoordx : rvnCoordx)
    cin >> rnCoordx;

  sort(begin(rvnCoordx), end(rvnCoordx));
}

int fnMinMoveCnt(int nPicSiz, const vector<int>& cnrvnCoordx)
{
  vector<int> vnDist;

  for (int i = 0; i < cnrvnCoordx.size() - 1; i++)
    vnDist.push_back( cnrvnCoordx[i + 1] - cnrvnCoordx[i] );

  sort(begin(vnDist), end(vnDist));
  int nMinMoveCnt = 0;

  for (int i = 0; i < (int)vnDist.size() - (nPicSiz - 1); i++)
    nMinMoveCnt += vnDist[i];

  return nMinMoveCnt;
}
 
int main()
{
  int nPicSiz;
  vector<int> vnCoordx;

  fnInput(nPicSiz, vnCoordx);
  cout << fnMinMoveCnt(nPicSiz, vnCoordx) << endl;

  return 0;
}
