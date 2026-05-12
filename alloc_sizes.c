
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void) {
  printf("PID: %d. Press enter after each step.\n", getpid());

  getchar();
  void *small[100];
  for (int i = 0; i < 100; i++)
    small[i] = malloc(40);
  printf("After 100 × malloc(40). vmmap now.\n");

  getchar();
  void *big = malloc(64 * 1024 * 1024); // 64 MB
  printf("After malloc(64MB). big @ %p.  vmmap now.\n", big);

  getchar();
  free(big);
  for (int i = 0; i < 100; i++)
    free(small[i]);
  printf("After freeing everything. vmmap now.\n");
  getchar();
  return 0;
}
