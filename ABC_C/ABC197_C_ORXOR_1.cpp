#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;

void input(vector<int>& rvElem)
{
  int sizElem;
  cin >> sizElem;
  rvElem.resize(sizElem);

  for (int& rElem : rvElem)
    cin >> rElem;
}

int calcElemOrXor(const vector<uint>& crvStartnx, const vector<int>& crvElem)
{
  vector<int> vOrElem(crvStartnx.size() - 1);

  for (uint nx = 0; nx < crvStartnx.size() - 1; ++nx)
  {
    int orElem = 0;

    for (uint ny = crvStartnx[nx]; ny < crvStartnx[nx + 1]; ++ny)
      orElem |= crvElem[ny];

    vOrElem[nx] = orElem;
  }

  int xorElem = 0;

  for (int orElem : vOrElem)
    xorElem ^= orElem;

  return xorElem;
}

void dfsOrXor(uint dept, int& rOneOrXor, 
              vector<uint>& rvStartnx, const vector<int>& crvElem)
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

  for (uint seprt = 1; seprt <= crvElem.size(); ++seprt)
  {
    vector<uint> vStartnx(seprt + 1);  // 最終要素は配列の size値 設定
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
