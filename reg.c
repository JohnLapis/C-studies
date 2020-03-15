#include <stdio.h>

struct entry {int c; struct entry *next;};

void insEntry(struct entry* toNewEntry, struct entry* newEntryEnd,
	    struct entry* prevEntry){
  newEntryEnd->next = prevEntry->next;
  prevEntry->next = toNewEntry;
}

void remEntry(struct entry* entry){
  entry->next = entry->next->next;
}



main(){
  struct entry list[7], *p_list = list;

  for (int i = 0; i < 6; i++, p_list++){
    p_list->next = p_list + 1;
    p_list->c = i;
  }
    
  p_list->next = (struct entry*) 0;
  p_list->c = (p_list-1)->c + 1;

  struct entry new = {89, 0}, *p_new = &new,
    new2 = {90, 0}, *p_new2 = &new2;

  p_new->next = &new2;
  
  insStr(p_new, p_new2, (list + 3)->next);
  
  for(p_list = list; p_list->next != (struct entry*) 0; p_list = p_list->next)
    printf("%d----%d\n", p_list->c, p_list->next->c);
  
  return 0;
}
