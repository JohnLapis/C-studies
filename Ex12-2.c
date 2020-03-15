#include <stdio.h>

int bitpat_search(unsigned int source, int pattern){
  size_t pat_size = 0;
  size_t source_size = sizeof source * 8;
  unsigned int p = pattern;
  int index = 0;

  for (; p; pat_size++)
    p >>= 1;

  while (index + pat_size <= source_size){
    if (source >> source_size - pat_size - index == pattern)
      return index;
    
    source = source << index + 1 >> index + 1;
    index++;
  }
  
  return -1;
}

void printb(int n){
  int size = 0;

  
  for (unsigned int x = n; x > 0; size++)
    x >>= 1;
    
  char b[size + 2], *p_b = b + size + 1;

  *p_b-- = '\0';
  
  while (n){
    if (n % 2)
      *p_b = '1';
    else
      *p_b = '0';

    n >>= 1;
    p_b--;
  }

  *p_b = '0';
  printf("%s\n", b);
}

int main(){
  unsigned int a = 999999;
  int b = 3;
  
  //  scanf("%d %d", &a, &b);
  
  printb(bitpat_search(a, b));

  
  return 0;
}
