#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//print hello world
int 
sys_print(char *a){
   return print(a); 
}

//clone function that get a stack and assign it to child thread stack
int 
sys_clone(void){
    char* stack;
    if(argptr(0, &stack, sizeof(char *)) < 0)
        return -1;
    return clone((void*)stack);
}

int
sys_join(void){
  return join();
}

int
sys_lock(void)
{
	char* l;
	if (argptr(0, &l, sizeof(char*)) < 0)
		return -1;
	return lock((int*) l);
}

int
sys_unlock(void)
{
	char* l;
	if (argptr(0, &l, sizeof(char*)) < 0)
		return -1;
	return unlock((int*) l);
}