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
  
string isDistinct(const vector<int>& cnrvnSeq)
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

  input(vnSeq);
  cout << isDistinct(vnSeq) << endl;

  return 0;
}
