#include <stdio.h>
#include <stdlib.h>

int global_init = 42;             // .data segment
int global_uninit;                // .bss segment
const char *string_lit = "hello"; // .rodata

int main(void) {
  int stack_var = 1;
  int *heap_var = malloc(sizeof(int));

  printf("code (main)        : %p\n", (void *)main);
  printf("code (printf)      : %p\n", (void *)printf);
  printf("rodata (literal)   : %p\n", (void *)string_lit);
  printf("data (init global) : %p\n", (void *)&global_init);
  printf("bss (uninit global): %p\n", (void *)&global_uninit);
  printf("heap (malloc)      : %p\n", (void *)heap_var);
  printf("stack (local)      : %p\n", (void *)&stack_var);
  free(heap_var);
  return 0;
}
