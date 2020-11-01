#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
void calcSeqMaxNum(const vector<int>& cnrvnSeq)
{
  vector<int> vnSrtSeq(cnrvnSeq);
  sort(begin(vnSrtSeq), end(vnSrtSeq));
  
  for (int nx = 0; nx < cnrvnSeq.size(); ++nx)
    if (cnrvnSeq[nx] == vnSrtSeq[vnSrtSeq.size() - 1])
      cout << vnSrtSeq[vnSrtSeq.size() - 2] << endl;
    else
      cout << vnSrtSeq[vnSrtSeq.size() - 1] << endl;
}
  
int main()
{
  vector<int> vnSeq;

  input(vnSeq);
  calcSeqMaxNum(vnSeq);

  return 0;
}
