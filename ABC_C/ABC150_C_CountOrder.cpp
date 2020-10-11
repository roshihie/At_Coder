#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnSeqP, vector<int>& rvnSeqQ)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeqP.resize(nSeqSiz);
  rvnSeqQ.resize(nSeqSiz);

  for (int& rnSeqP : rvnSeqP)
    cin >> rnSeqP;
  for (int& rnSeqQ : rvnSeqQ)
    cin >> rnSeqQ;
}
  
int calcDiffOrderCnt(const vector<int>& cnrvnSeqP, const vector<int>& cnrvnSeqQ)
{
  vector<int> vnSeqX(cnrvnSeqP.size());
  int nxSeqP = 0;
  int nxSeqQ = 0;
  int nxSeqX = 0;

  iota(begin(vnSeqX), end(vnSeqX), 1);
  do {
    ++nxSeqX;
    if (cnrvnSeqP == vnSeqX) nxSeqP = nxSeqX;
    if (cnrvnSeqQ == vnSeqX) nxSeqQ = nxSeqX;
  }
  while ( next_permutation(begin(vnSeqX), end(vnSeqX) ) &&
          ( nxSeqP == 0 || nxSeqQ == 0 )                  );

  return abs(nxSeqP - nxSeqQ);
}
  
int main()
{
  vector<int> vnSeqP, vnSeqQ;

  input(vnSeqP, vnSeqQ);
  cout << calcDiffOrderCnt(vnSeqP, vnSeqQ) << endl;

  return 0;
}
