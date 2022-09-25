#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "ArtemLib12.h"

int main(void)
{  
  CVectR2 v[N] = {CVectR2(-6, 1), CVectR2(-6, -5), CVectR2(-7, 1)};
  CVect m1(v);
  CVect m2(1, 6);
  CAngl a(m1 ,m2);
  double b[N] = {1, 2 ,3};
  CAngl g(b);     
  CVect k=CVect(v) + b;        
  cout<<a<<endl<<g<<endl<<k;
  return 0;
} 






















