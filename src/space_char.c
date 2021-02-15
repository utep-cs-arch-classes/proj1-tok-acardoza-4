#include "tokenizer.h"
/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if (c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}
