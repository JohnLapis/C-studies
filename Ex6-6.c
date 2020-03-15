#include <stdio.h>

main () {
  char* nums[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
  int n, i = 0;
  char* nn[10];
  
  scanf("%d", &n);
  if (n == '0'){
    printf("zero");
    return 0;
  }
  for (int b = 10; n > 0; i++){
    nn[i] =  nums[n % b];
    n = n / 10;
  }

  for ( ; i >= 0; i--)
    printf("%s ", nn[i]);

  return 0;
}
