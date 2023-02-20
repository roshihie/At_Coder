#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvSeq)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  for (int& rseq : rvSeq)
    cin >> rseq;
}

string isTotal1000(vector<int>& crvSeq)
{
  for (int nx = 0; nx < crvSeq.size() - 2; ++nx)
    for (int ny = nx + 1; ny < crvSeq.size() - 1; ++ny)
      for (int nz = ny + 1; nz < crvSeq.size(); ++nz)
        if (crvSeq[nx] + crvSeq[ny] + crvSeq[nz] == 1000)
          return "Yes";

  return "No";
}

int main()
{
  vector<int> vSeq;

  input(vSeq);
  cout << isTotal1000(vSeq) << endl;

  return 0;
}
