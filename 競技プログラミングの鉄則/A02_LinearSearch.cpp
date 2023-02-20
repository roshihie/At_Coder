#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvSeq, int& rtrg)
{
  int sizSeq;
  cin >> sizSeq >> rtrg;
  rvSeq.resize(sizSeq);

  for (int& rseq : rvSeq)
    cin >> rseq;
}

string SearchLinear(const vector<int>& crvSeq, int trg)
{
  for (int nx = 0; nx < crvSeq.size(); ++nx)
    if (crvSeq[nx] == trg) return "Yes";

  return "No";
}

int main()
{
  vector<int> vSeq;
  int trg;

  input(vSeq, trg);
  cout << SearchLinear(vSeq, trg) << endl;

  return 0;
}
