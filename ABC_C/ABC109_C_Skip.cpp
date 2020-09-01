#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnBgn, vector<int>& rvnCoord)
{
  int nCoordSiz;
  cin >> nCoordSiz >> rnBgn;
  rvnCoord.resize(nCoordSiz);

  for (int& rnCoord : rvnCoord)
    cin >> rnCoord;
}

int fnGcd(int nOne, int nOtr)
{
  if ( !nOtr )
    return nOne;
  else
    return fnGcd(nOtr, nOne % nOtr);
}

int fnMaxMovemnt(int nBgn, const vector<int>& cnrvnCoord)
{
  vector<int> vnDiff(cnrvnCoord.size());

  for (int i = 0; i < cnrvnCoord.size(); ++i)
    vnDiff[i] = abs(nBgn - cnrvnCoord[i]);

  int nGcd = vnDiff[0];

  for (int i = 1; i < vnDiff.size(); ++i)
    nGcd = fnGcd(nGcd, vnDiff[i]);

  return nGcd;
}
  
int main()
{
  int nBgn;
  vector<int> vnCoord;
  
  fnInput(nBgn, vnCoord);
  cout << fnMaxMovemnt(nBgn, vnCoord) << endl;

  return 0;
}
