#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnCandy, int& rnCandySiz)
{
  int nChildSiz;
  cin >> nChildSiz >> rnCandySiz;
  rvnCandy.resize(nChildSiz);

  for (int& rnCandy : rvnCandy)
    cin >> rnCandy;

  sort(begin(rvnCandy), end(rvnCandy));
}

int fnCandyDist(const vector<int>& cnrvnCandy, int nCandySiz)
{
  int nFullyChld = 0;
  for (int nCandy : cnrvnCandy)
  {
    nCandySiz -= nCandy;
    if (nCandySiz >= 0)
      ++nFullyChld;
    else
      break;
  }
  if (nCandySiz > 0) --nFullyChld;

  return nFullyChld;
}

int main()
{
  int nCandySiz;
  vector<int> vnCandy;

  fnInput(vnCandy, nCandySiz);
  cout << fnCandyDist(vnCandy, nCandySiz) << endl;

  return 0;
}
