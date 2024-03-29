#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvElem)
{
  int sizElem;
  cin >> sizElem;
  rvElem.resize(sizElem);

  for (int& elem : rvElem)
    cin >> elem;
}

int calcMinOrXor(const vector<int>& crvElem)
{
  int minOrXor = INT_MAX;
  int cntSeprt = (int)crvElem.size() - 1;

  for (int bit = 0; bit < ( 1 << cntSeprt ); ++bit)
  {
    int orElem = 0;
    int xorElem = 0;

    for (int each = 0; each < cntSeprt; ++each)
    {
      orElem |= crvElem[each];

      if ( bit & ( 1 << each )) 
      {
        xorElem ^= orElem;
        orElem = 0;
      }
    }
    orElem |= crvElem[cntSeprt];   // 最左端要素 参照
    xorElem ^= orElem;

    minOrXor = min(minOrXor, xorElem);
  }
  return minOrXor;
}

int main()
{
  vector<int> vElem;

  input(vElem);
  cout << calcMinOrXor(vElem) << endl;

  return 0;
}
