#include "combo.h"

char L='A', l1='B', l2='X', l3='Y';

std::string guess_sequence(int N) 
{
  if (press("AB"))
    if (press("B")) std::swap(L,l1);
    else;
  else
    if (press("X")) std::swap(L,l2);
    else std::swap(L,l3);
    
  std::string sure;
  sure += L;
  if (N==1) return sure;
  
  for (int i=1; i<N-1; i++)
  {
    int coins = press(sure+l1+l1 +sure+l1+l2 +sure+l1+l3 +sure+l2) -i;
    if (coins==0) sure += l3;
    else if (coins==1) sure += l2;
    else sure += l1;
  }
    
  if (press(sure+l1 +sure+l2)==N)
    if (press(sure+l1)==N) return sure+l1;
    else return sure+l2;
  else return sure+l3;
  return sure;
}
