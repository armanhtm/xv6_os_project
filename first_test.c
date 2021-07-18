#include "types.h"
#include "stat.h"
#include "user.h"
int stack[4096] __attribute__ ((aligned (4096)));
int x = 0;
int main(int argc, char *argv[]) {
  printf(1, "Stack is at %p\n", stack);
  // int tid = fork();
  int tid = clone(stack);
	
  if (tid < 0) {
    printf(2, "error!\n");
  } else if (tid == 0) {
    // child
    printf(1, "child addr: %p\n", &x);
    for(;;) {
      x++;
      sleep(100);
	  exit();
    }
  } else {
    // parent
    printf(1, "parent addr: %p\n", &x);
    while(x < 1) {
      printf(1, "x = %d\n", x);
      sleep(100);
      join();
    }
  }
    exit();
}