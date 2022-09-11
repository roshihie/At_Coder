#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvElem)
{
  int sizElem;
  cin >> sizElem;
  rvElem.resize(sizElem);

  for (int& rElem : rvElem)
    cin >> rElem;
}

int calcElemOrXor(const vector<int>& crvBegin, const vector<int>& crvElem)
{
  vector<int> vOrElem(crvBegin.size() - 1);

  for (int nx = 0; nx < (int)crvBegin.size() - 1; ++nx)
  {
    int orElem = 0;

    for (int ny = crvBegin[nx]; ny < crvBegin[nx + 1]; ++ny)
      orElem |= crvElem[ny];

    vOrElem[nx] = orElem;
  }

  int xorElem = 0;

  for (int orElem : vOrElem)
    xorElem ^= orElem;

  return xorElem;
}

void dfsOrXor(int dept, int& rOneOrXor, 
              vector<int>& rvBegin, const vector<int>& crvElem)
{
  if (dept == (int)rvBegin.size() - 1)     // 深さ＝配列の最終要素 のとき
  {
    rvBegin[dept] = (int)crvElem.size();   // 配列の size値 設定
    int xorElem = calcElemOrXor(rvBegin, crvElem);
    rOneOrXor = min(rOneOrXor, xorElem);
    return;
  }

  rvBegin[dept] = rvBegin[dept - 1] + 1;

  while (rvBegin[dept] < (int)crvElem.size())
  {
    dfsOrXor(dept + 1, rOneOrXor, rvBegin, crvElem);
    ++rvBegin[dept];
  }
}

int calcMinOrXor(const vector<int>& crvElem)
{
  int minOrXor = INT_MAX;

  for (int seprt = 1; seprt <= (int)crvElem.size(); ++seprt)
  {
    vector<int> vBegin(seprt + 1);     // 最終要素は配列の size値 設定用に＋１
    int oneOrXor = INT_MAX;

    dfsOrXor(1, oneOrXor, vBegin, crvElem);
    minOrXor = min(minOrXor, oneOrXor);
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
