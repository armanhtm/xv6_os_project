#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE 4096

int
thread_create(void (*fn) (void *), void *arg)
{
  void* stack = malloc(PGSIZE * 2);
  
  if((uint)stack % PGSIZE)
    stack = stack + (4096 - (uint)stack % PGSIZE);

  int threadId = clone(stack);

  if (threadId == -1)
    return -1;

  if (threadId == 0) //Child Code
  {
    fn(arg);
	free(stack);
    exit();
  }
  else //Parent Code
  {
    return threadId;
  }

  return -1;
}