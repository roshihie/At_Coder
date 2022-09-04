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

int calcElemOrXor(const vector<int>& crvStartnx, const vector<int>& crvElem)
{
  vector<int> vOrElem(crvStartnx.size() - 1);

  for (int nx = 0; nx < (int)crvStartnx.size() - 1; ++nx)
  {
    int orElem = 0;

    for (int ny = crvStartnx[nx]; ny < crvStartnx[nx + 1]; ++ny)
      orElem |= crvElem[ny];

    vOrElem[nx] = orElem;
  }

  int xorElem = 0;

  for (int orElem : vOrElem)
    xorElem ^= orElem;

  return xorElem;
}

void dfsOrXor(int dept, int& rOneOrXor, 
              vector<int>& rvStartnx, const vector<int>& crvElem)
{
  if (dept == rvStartnx.size() - 1)    // 深さ＝配列の最終要素 のとき
  {
    rvStartnx[dept] = crvElem.size();  // 配列の size値 設定
    int xorElem = calcElemOrXor(rvStartnx, crvElem);
    rOneOrXor = min(rOneOrXor, xorElem);
    return;
  }

  rvStartnx[dept] = rvStartnx[dept - 1] + 1;

  while (rvStartnx[dept] < crvElem.size())
  {
    dfsOrXor(dept + 1, rOneOrXor, rvStartnx, crvElem);
    ++rvStartnx[dept];
  }
}

int calcMinOrXor(const vector<int>& crvElem)
{
  int minOrXor = INT_MAX;

  for (int seprt = 1; seprt <= (int)crvElem.size(); ++seprt)
  {
    vector<int> vStartnx(seprt + 1);  // 最終要素は配列の size値 設定
    int oneOrXor = INT_MAX;

    dfsOrXor(1, oneOrXor, vStartnx, crvElem);
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
