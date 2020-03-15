#include <stdio.h>

main () {
  int m, n, fact;

  for (m = 10; m >= 0; m--){
    fact = 1;
    for (n = m; n >= 1; n--)
      fact *= n;
    printf("The factorial of %d is %d\n", m, fact);
  }

  return 0;
}
