#include <stdio.h>
#include <string.h>

//See ~/Pictures/Untitled.png

_Bool hasNull(char* str, size_t strSize){
  for (int i = 0; i != strSize; i++, str++)
    if (*str == '\0')
      return 1;

  return 0;
}

char* subString(char *src, int start, int count, char str[],
		size_t srcSize, size_t strSize){

  char *p_str = str;

  if (strSize < srcSize - start || ! hasNull(src, srcSize))
    return NULL;

  for (src += start; count > 0 && *src != '\0'; count--)
    *p_str++ = *src++;
  
  *p_str = '\0';
  
  return str;
}

int findString(char src[], char ptrn[], size_t srcSize){
  int matches = 0;
  char *p_src = src, *p_ptrn = ptrn;

  if (! hasNull(src, srcSize))
    return 1;
  
  for (;*p_src != '\0'; p_src++){
    if (*p_src == *p_ptrn)
      p_ptrn++;
    else{
      if (*p_ptrn == '\0'){
	matches++;
	p_src--;
      }

      p_ptrn = ptrn;      
    }
  }

  return matches;
}

char* removeString(char src[], int start, int end, size_t srcSize){
  char newStr[srcSize - end];
  char *p_newStr = newStr, *p_src = src;

  if (srcSize < end || end + start > srcSize || ! hasNull(src, srcSize))
    return NULL;
 
  for (p_src += start + end; *p_src != '\0';)
    *p_newStr++ = *p_src++;
  
  //  p_src = src;
  p_newStr = newStr;
  
  for (p_src = src + start; *p_src != '\0';)
    *p_src++ = *p_newStr++;

  return src;
}

char* insertString(char src[], char str[], int start,
		   size_t srcSize, size_t strSize){
  char newStr[srcSize - start];
  char *p_newStr = newStr, *p_str = str, *p_src = src;

  if (! hasNull(src, srcSize)||
      ! hasNull(str, strSize)||
      srcSize < strlen(src) + 1 + strlen(str))
    return NULL;

  for (p_src += start; *p_newStr != '\0';)
    *p_newStr++ = *p_src++;    

  for (p_src = src + start; *p_str != '\0';)
    *p_src++ = *p_str++;

  for (p_newStr = newStr; *p_newStr != '\0';)
    *p_src++ = *p_newStr++;

  *p_src = '\0';

  return src;
}

char* replaceString(char src[], char str1[], char str2[],
		    size_t srcSize, size_t str1Size, size_t str2Size){

  int  matches = findString(src, str1, srcSize);
  char *p_src = src, *p_str1 = str1, *p_str2 = str2;
  int a = strlen(str2) - strlen(str1);
  
  struct indexes {int strt; int end;} list[matches], *p_list = list;
  
  if (! hasNull(src, srcSize)||
      ! hasNull(str1, str1Size)||
      ! hasNull(str2, str2Size)||
      srcSize < strlen(src) + 1 + matches * a)
    return NULL;
  
  for (; *p_src != '\0'; ++p_src){
    if (*p_src == *p_str1)
      p_str1++;
    else{
      if (*p_str1 == '\0'){
	p_src--;
	p_str1--;
	p_list->strt = (p_src - src) - (p_str1 - str1) + (p_list - list) * a;
	p_list->end = p_src - src + 1 + (p_list - list) * a;
	printf("%d--%d\n", p_list->strt, p_list->end);
	++p_list;
      }
      p_str1 = str1;
    }
  }

  char newStr[srcSize*2 + matches * (str2Size - str1Size)], *p_newStr = newStr;

  p_list = list;
  p_src = src;

  printf("++%s\n", src);

  printf("mat = %d\n", matches);
  
  for (;matches > 0; matches--, p_list++){
    printf("%d\n", p_list - list);
    p_src = src + p_list->end;
    printf("%d\n", p_src - src);
    
    for (p_newStr = newStr; *p_newStr != '\0';)
      *p_newStr++ = *p_src++;
    
    p_src = src + p_list->strt;
    
    for (p_str2 = str2; *p_str2 != '\0';)
      *p_src++ = *p_str2++;

      printf("+++++%s\n", src);
    
    for (p_newStr = newStr; *p_newStr != '\0';)
      *p_src++ = *p_newStr++;

    printf("%s\n===%s\n", newStr, src);
  }
  

  
  return src;
}  

int main(void){
  char bob[80] = "bbbbbbeeeeessssssssst3riateriaiajuju";
  char abc[80] = "abcdefghijklmnopqrstuvwxyz";
  char subs[45];
  char finds[] = "ia"; //ia-ria-teria-e--peni
  char f[] = "dda";

  size_t bob_size = sizeof bob / sizeof(char),
    subs_size = sizeof subs / sizeof(char),
    abc_size = sizeof abc / sizeof(char),
    finds_size = sizeof finds / sizeof(char),
    f_size = sizeof f / sizeof(char);
  
  printf("sub\n%s\n", subString(bob, 9, 5, subs, bob_size, subs_size));

  printf("find\n%d\n", findString(bob, finds, bob_size));

  printf("rem\n%s\n", removeString(bob, 11, 10, bob_size));

  printf("ins\n%s\n", insertString(abc, finds, 16, abc_size, finds_size));

  /*printf("rpl\n%s\n", replaceString(bob, finds, f, bob_size, finds_size, f_size));
  i just doesn't work. i should've implemented linked lists before wasting my time in any of this functions.
  */

  return 0;
}
