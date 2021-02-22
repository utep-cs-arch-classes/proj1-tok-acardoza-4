#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t' || c == '\n'){
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
  if (c == '\0' || space_char(c)){
    return 0;
  }
  else{
    return 1;
  }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  while (space_char(*str)){
    str++;
  }
  return str;
}

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if 
   str does not contain any space characters. */
char *word_end(char *str)
{
  while (non_space_char(*str)){
    str++;
  }
  return str;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int word_num = 0;  /* number of words in the string */
  while (*str != '\0') {
    str = word_start(str);
    str = word_end(str);
    word_num++;
  }
  return word_num;
}
/*
  /* Tests the various functions in tokenizer.c */
int main()
{
  /* Testing space_char. */
  char test_char1 = 'M';
  char test_char2 = ' ';
  if (space_char(test_char1))
    printf("%c is a whitespace!\n", test_char1);
  else{
    printf("%c is a char!\n", test_char1);
  }
  
  /* Testing word_start */
  char *sp, *ep;
  char s[] = "   This string has five words";
  sp = word_start(s);
  printf("%c is the first char\n", *sp);

  /* Testing word_end */
  ep = word_end(s);
  printf("%c is the last char\n", *(ep - 1));

  /* Testing word_count */
  sp = s;
  printf("There are %d words in the string\n", count_words(sp));
}
