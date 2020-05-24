#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
string fnDistinctChk(const vector<int>& cnrvnSeq)
{
  set<int> seDistinct;

  for (int nSeq : cnrvnSeq)
    seDistinct.insert(nSeq);

  if (cnrvnSeq.size() == seDistinct.size())
    return "YES";
  else
    return "NO"; 
}
  
int main()
{
  vector<int> vnSeq;

  fnInput(vnSeq);
  cout << fnDistinctChk(vnSeq) << endl;

  return 0;
}
