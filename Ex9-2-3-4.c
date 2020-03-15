#include <stdio.h>

struct  date {int  month; int  day; int  year;}
  d1 = {8,8,2004}, d2 = {2,22,2005};
struct  time {int  sec; int  min; int  hour;}
  a = {0,0,0}, b = {0,0,0};

int distDates(struct date a, struct date b){
  int aa, bb;
  
  if (a.month <= 2)
    aa = 1461 * (a.year - 1) / 4 + 153 * (a.month + 13) / 5 + a.day;
  else
    aa = 1461 * a.year / 4 + 153 * (a.month + 1) / 5 + a.day;
  if (b.month <= 2)
    bb = 1461 * (b.year - 1) / 4 + 153 * (b.month + 13) / 5 + b.day;
  else
    bb = 1461 * b.year / 4 + 153 * (b.month + 1) / 5 + b.day;

  return  aa > bb? aa - bb : bb - aa;
}

struct time elapsedTime(struct time a, struct time b){
  struct time c = {0,0,0};

  if (a.hour > b.hour){
    c.hour = a.hour - b.hour;
    c.min = a.min - b.min;
    c.sec = a.sec - b.sec;
  }else if (a.hour < b.hour){
    c.hour = b.hour - a.hour;
    c.min = b.min - a.min;
    c.sec = b.sec - a.sec;
  }else
    if (a.min > b.min){
      c.hour = a.hour - b.hour;
      c.min = a.min - b.min;
      c.sec = a.sec - b.sec;
    }else if (a.min <  b.min){
      c.hour = b.hour - a.hour;
      c.min = b.min - a.min;
      c.sec = b.sec - a.sec;
    }else
      if (a.sec > b.sec){
	c.hour = a.hour - b.hour;
	c.min = a.min - b.min;
	c.sec = a.sec - b.sec;
      } else{
	c.hour = b.hour - a.hour;
	c.min = b.min - a.min;
	c.sec = b.sec - a.sec;
      }
      
  if (c.sec < 0){
    c.min--;
    c.sec = 60 + c.sec;
  }
    
  if (c.min < 0){
    c.hour--;
    c.min = 60 + c.min;
  }

  if (c.hour < 0)
    c.hour = 24 + c.hour;
  
  return c;
}

main(){
  int j = distDates(d1,d2);
  char* weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  
  printf("%d days.\n", j);
  printf("It falls on a %s.\n\n", weekDays[(j - 621049) % 7]);  

  scanf("%d %d %d", &a.hour, &a.min, &a.sec);
  scanf("%d %d %d", &b.hour, &b.min, &b.sec);

  struct time c = elapsedTime(a,b);
  printf("%d:%d:%d\n", c.hour, c.min, c.sec);

}
