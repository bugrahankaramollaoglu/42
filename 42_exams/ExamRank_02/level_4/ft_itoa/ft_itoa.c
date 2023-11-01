#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *repeat_str(size_t count, const char *src)
{
// allocate a string on the heap
  char *s = malloc(strlen(src)*count+1);
  if(!s)
    return NULL;
  for(size_t i=0; i<count; ++i) {
    s = strcpy(s, src);
    s += strlen(src);
  }
  printf("%s\n", s);
  return s;
}

int main() {
  repeat_str(3, "abc");
}
