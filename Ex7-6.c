#include <stdio.h>

main(){
  int a=0, b=1, c, n;

  scanf("%d", &n);
  
  for (int i = 0; i < n; i++){
    printf("%d\n", a);
    c = a;
    a = b;
    b += c;
  }
  
  return 0;
}
