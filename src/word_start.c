#include "tokenizer.h"

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */

int *word_start(char *str){
  int count = 0;
  while (non_space_char(*str[count]) && *str[count] != '\0'){
    count++;
  }
  if(*str[count] == '\0'){
    return NULL;
  }
  else{
    return *(*str[count]);
  }
}
