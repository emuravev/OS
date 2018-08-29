#include <limits.h>
#include <float.h>
#include <stdio.h>

main (void)
{
  int ival = INT_MAX;
  float fval = FLT_MAX;
  double dval = DBL_MAX;

  printf("value = %d size = %d\n", ival, sizeof(ival));
  printf("value = %f size = %d\n", fval, sizeof(fval));
  printf("value = %g size = %d\n", dval, sizeof(dval));

  return 0;
}
