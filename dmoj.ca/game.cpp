#include <cstdio>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
  while (b>0) tie(a,b) = make_tuple(b,a%b);
  return a;
}

ll tree[19778000];
int child[19778000], nNodes=32;

int create(int i, int nAdd, int sign)
{
  nNodes += nAdd;
  return sign*( child[i]=sign*(nNodes-nAdd+1) );
}
int left(int i, bool isOuter, int nCreate, int sign=-1)
{
  int step = isOuter ? 32 : 1;
  if (child[i]==0 || child[i]==-sign*(i+step))
    if (nCreate==0)       return 0;
    else if (isOuter)     return create(i, 32, sign);
    else if (child[i]==0) return sign*( child[i]=sign*(i+1) );
    else                  return create(i, ceil(log2(nCreate))+1, sign);
  if (sign*child[i]>0) return sign*child[i];
  return i+step;
}
int right(int i, bool isOuter, int nCreate)
{
  return left(i, isOuter, nCreate, 1);
}

ll query(int y1, int y2, int i, int beg, int end, int x1, int x2, int C)
{
  if (!i) return 0;
  if (y1==beg && y2==end)
    if (C>0) return query(x1, x2, i+1, 0, C-1, -1, -1, -1);
    else return tree[i];

  int mid = (beg+end)/2;
  ll part1 = y1<=mid ? query(y1, min(y2,mid), left(i,C>0,0), beg, mid, x1, x2, C) : 0;
  ll part2 = y2>mid  ? query(max(y1,mid+1), y2, right(i,C>0,0), mid+1, end, x1, x2, C) : 0;
  return gcd(part1,part2);
}

void update(int y, ll val, int i, int beg, int end, int x, int C)
{
  if (beg==end) 
  {
    if (C>0) update(x, val, i+1, 0, C-1, -1, -1);
    else tree[i]=val;
    return;
  }
  
  int mid = (beg+end)/2;
  if (y<=mid) update(y, val, left(i,C>0,mid-beg+1), beg, mid, x, C);
  else        update(y, val, right(i,C>0,end-mid), mid+1, end, x, C);
  ll part1 = query(0, 0, left(i,C>0,0),  0, 0, x, x, C);
  ll part2 = query(0, 0, right(i,C>0,0), 0, 0, x, x, C);
  if (C>-1) update(x, gcd(part1,part2), i+1, 0, C-1, -1, -1);
  else tree[i] = gcd(part1,part2);
}

int R, C;
void init(int R, int C) {::R=R; ::C=C;}
void update(int P, int Q, long long K)
{
  update(P, K, 1, 0, R-1, Q, C);
}
long long calculate(int P, int Q, int U, int V)
{
  return query(P, U, 1, 0, R-1, Q, V, C);
}
