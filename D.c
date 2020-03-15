#include <stdio.h>

main(){
  char message2[] = "you said it\n";
  int start = 4;
  char *format = "x = %i\n";
  printf (format, start);

  return 0;
}
