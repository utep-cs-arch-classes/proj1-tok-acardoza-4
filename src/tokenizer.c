#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if (c == ' ' || c == '\t'){
    return 0;
  }
  else{
    return 1;
  }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */

int *word_start(char *str)
{
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

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if 
   str does not contain any space characters. */
int *word_end(char *str)
{
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

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int word_num = 0;  /* number of words in the string */
  while (*str != '\0') {
    str = word_start(str);
    str = word_end(str) + 1;
    word_num++;
  }
  return word_num;
}
