#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvElem)
{
  int elemSiz;
  cin >> elemSiz;
  rvElem.resize(elemSiz);

  for (int& elem : rvElem)
    cin >> elem;
}

int calcMinOrXor(const vector<int>& crvElem)
{
  int cntMinXor = INT_MAX;
  int seprtSiz = (int)crvElem.size() - 1;

  for (int bit = 0; bit < ( 1 << seprtSiz ); ++bit)
  {
    int orElem = 0;
    int xorElem = 0;

    for (int each = 0; each < seprtSiz; ++each)
    {
      orElem |= crvElem[each];

      if ( bit & ( 1 << each )) 
      {
        xorElem ^= orElem;
        orElem = 0;
      }
    }
    orElem |= crvElem[seprtSiz];
    xorElem ^= orElem;

    cntMinXor = min(cntMinXor, xorElem);
  }
  return cntMinXor;
}

int main()
{
  vector<int> vElem;

  input(vElem);
  cout << calcMinOrXor(vElem) << endl;

  return 0;
}
