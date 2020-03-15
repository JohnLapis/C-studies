#include <stdio.h>

main(){
  int a,b, a2, b2, r, lcm;

  scanf("%d %d", &a, &b);

  a2 = a;
  b2 = b;

  //a2 will become gcd(a,b)
  do {
    r = a2 % b2;
    printf("%d\n", r);
    a2 = b2;
    b2 = r;
  } while (r);

  lcm = a * (b / a2);

  printf("LCM: %d\nGCD: %d\n", lcm, a2);
  
  return 0;
}
