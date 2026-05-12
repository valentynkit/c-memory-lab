
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

void print_rss(const char *label) {
  struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  // macOS reports ru_maxrss in BYTES (Linux reports in KB!)
  printf("%-40s RSS = %ld bytes (%.1f MB)\n", label, r.ru_maxrss,
         r.ru_maxrss / 1024.0 / 1024.0);
}

int main(void) {
  print_rss("start");

  void *ptrs[1000];
  for (int i = 0; i < 1000; i++)
    ptrs[i] = malloc(100 * 1024);
  print_rss("after 1000 × malloc(100KB)");

  for (int i = 0; i < 1000; i++)
    memset(ptrs[i], 0xAA, 100 * 1024);
  print_rss("after touching all bytes");

  for (int i = 0; i < 1000; i++)
    free(ptrs[i]);
  print_rss("after freeing everything");

  sleep(1);
  print_rss("1 second later");
  sleep(10);
  print_rss("10 second later");
  return 0;
}
