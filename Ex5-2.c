#include <stdio.h>
#include <math.h>

void main(){
  int nums[10]={1,2,3,4,5,6,7,8,9,10};
  int i = 0;

  for ( ; i < 10; i++)
    printf("%2d %d\n", nums[i], nums[i] * nums[i]);
}
