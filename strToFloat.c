#include <stdio.h>
#include <math.h>
#include <string.h>

float strToFloat(char str[]){

  float n = 0;
  char *p_str = str;
  int point = 0, i;

  while (*p_str - 0 < 49 || *p_str - 0 > 57)
    p_str++;

  n += (*p_str - 48) * pow(10, strlen(str) - 2 - (*str == '-'?1:0));

  p_str = str + strlen(str) - 1;

  int condition = *str == '-'? (*(str+1) == '.'? 2:1):(*str == '.'? 1:0);
  
  for (i = 0; p_str - str > 0 + condition; p_str--){
    if (*p_str == '.' || *p_str == ',')
      point = i;
    else{
      n += (*p_str - 48) * pow(10, i);
      i++;
    }
  }

  if (point)
    n /= pow(10, point);
  else
    n /= pow(10, ++i);

  return *str != '-' ? n : -n;
}
main(){
  char num[32];

  scanf("%32s", num);
  printf("%g\n", strToFloat(num));

  return 0;
}
