#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvSeq)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  for (int& rSeq : rvSeq)
    cin >> rSeq;
}

int calcMaxRect(const vector<int>& crvSeq)
{
  int maxRect = 0;

  for (int left = 0; left < (int)crvSeq.size(); ++left)
  {
    int height = crvSeq[left];
    int right = left + 1;

    while ( right < (int)crvSeq.size() )
    {
      maxRect = max( maxRect, (right - left) * height );

      if ( height > crvSeq[right] )
        height = crvSeq[right];

      ++right;
    }
    maxRect = max( maxRect, (right - left) * height );
  }
  return maxRect;
}
  
int main()
{
  vector<int> vSeq;

  input(vSeq);
  cout << calcMaxRect(vSeq) << endl;

  return 0;
}
