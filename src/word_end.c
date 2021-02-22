#include "tokenizer.h"

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if 
   str does not contain any space characters. */

int *word_end(char *str){
  int count = 0;
  while (non_space_char(*str[count]) && *str[count] != '\0'){
    count++;
  }
  if (*str[count] == '\0'){
    return NULL;
  }
  else{
    return *(*str[count]);
  }
}
