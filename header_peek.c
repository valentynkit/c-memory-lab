#include <malloc/malloc.h>
#include <stdio.h>
#include <stdlib.h>

/* The header trick that makes free(ptr) work */

int main(void) {
  for (size_t n = 1; n <= 256; n *= 2) {
    char *p = malloc(n);
    printf("malloc(%4zu) -> ptr=%p, malloc_size=%4zu, alignments=%zu\n", n, p,
           malloc_size(p), (uintptr_t)p % 16);
    free(p);
  }
  return 0;
}
