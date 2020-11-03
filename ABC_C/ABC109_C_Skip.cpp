#include <bits/stdc++.h>
using namespace std;

void input(int& rnBgn, vector<int>& rvnCoord)
{
  int nCoordSiz;
  cin >> nCoordSiz >> rnBgn;
  rvnCoord.resize(nCoordSiz);

  for (int& rnCoord : rvnCoord)
    cin >> rnCoord;
}

int calcGcd(int nOne, int nOtr)
{
  if ( !nOtr ) return nOne;
  return calcGcd(nOtr, nOne % nOtr);
}

int calcMaxMovemnt(int nBgn, const vector<int>& cnrvnCoord)
{
  vector<int> vnDiff(cnrvnCoord.size());

  for (int i = 0; i < cnrvnCoord.size(); ++i)
    vnDiff[i] = abs(nBgn - cnrvnCoord[i]);

  int nGcd = vnDiff[0];

  for (int i = 1; i < vnDiff.size(); ++i)
    nGcd = calcGcd(nGcd, vnDiff[i]);

  return nGcd;
}
  
int main()
{
  int nBgn;
  vector<int> vnCoord;
  
  input(nBgn, vnCoord);
  cout << calcMaxMovemnt(nBgn, vnCoord) << endl;

  return 0;
}
