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

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  int i;
  char *word_list;
  word_list = (char *)malloc(sizeof(char) * (len + 1));
  for (i = 0; i < len; i++) {
    word_list[i] = inStr[i];
  }
  word_list[i] = '\0';
  return word_list;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i;
  int j;
  for(i = 0; tokens[i] != NULL; i++) {
    for(j = 0; tokens[i][j] != '\0'; j++) {
      printf("[%c]", tokens[i][j]);
    }
    printf("\n");
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int word_count = count_words(str);
  char **word_array = (char **)malloc(sizeof(char*) * (word_count + 1));

  int i;
  int length;
  for (i = 0; i < word_count - 1; i++) {
    str = word_start(str);
    length = word_end(str) - str;
    word_array[i] = copy_str(str, length);
    str = word_end(str);
  }
  word_array[i] = '\0';
  return word_array;
}

/* Tests some of the functions in tokenizer.c */
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
