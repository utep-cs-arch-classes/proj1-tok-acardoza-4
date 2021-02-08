#include <stdio.h>

#define LEN 30
int main (){
  char word[LEN];
  printf("$");
  fgets(word, LEN, stdin);
  printf("%s\n", word);
  return 0;
}
