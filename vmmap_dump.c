#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int *heap = malloc(100);
  int stack = 1;

  pid_t pid = getpid();
  printf("PID: %d \n", pid);
  printf("heap @ %p, stack @ %p \n", (void *)heap, (void *)&stack);

  char cmd[64];
  snprintf(cmd, sizeof(cmd), "vmmap -summary %d", pid);
  system(cmd);
  free(heap);
  return 0;
}
