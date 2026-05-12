#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void) {
  size_t sz = (size_t)100 * 1024 * 1024 * 1024; // 100 GB virtual
  void *p =
      mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
  if (p == MAP_FAILED) {
    perror("mmap");
    return EXIT_FAILURE;
  }

  printf("Mapped 100 GB at %p, PID %d\n", p, getpid());
  printf(
      "Press enter after running 'vmmap -summary %d' in another terminal...\n",
      getpid());
  getchar();

  munmap(p, sz);
  return 0;
}
