#include <stdio.h>

//This limit is 150.

main(){
  int p[150];

  for (int i = 2; i < 150; i++)
    p[i] = 1;
  
  for (int i = 2; i < 150; i++)
    if (!p[i])
      for (int j = i; j * i < 150; j++)
	p[i*j] = 0;

  for (i=2;i<150;i++)
    if (p[i])
      printf("%d\n", i);
  
  return 0;

  
}
