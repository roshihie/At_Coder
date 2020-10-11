#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnSeqB)
{
  int nSeqASiz;
  cin >> nSeqASiz;
  rvnSeqB.resize(nSeqASiz - 1);

  for (int& rnSeqB : rvnSeqB)
    cin >> rnSeqB;
}
  
int calcMaxValue(const vector<int>& cnrvnSeqB)
{
  vector<int> vnSeqA(cnrvnSeqB.size() + 1, 1e5 + 1);

  for (int nx = 0; nx < cnrvnSeqB.size(); ++nx)
  {
    if (cnrvnSeqB[nx] < vnSeqA[nx])
      vnSeqA[nx] = cnrvnSeqB[nx];
    if (cnrvnSeqB[nx] < vnSeqA[nx + 1])
      vnSeqA[nx + 1] = cnrvnSeqB[nx];
  }
  int nSum = accumulate(begin(vnSeqA), end(vnSeqA), 0);
  return nSum;
}
  
int main()
{
  vector<int> vnSeqB;

  input(vnSeqB);
  cout << calcMaxValue(vnSeqB) << endl;

  return 0;
}
