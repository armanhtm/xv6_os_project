#include "types.h"
#include "stat.h"
#include "user.h"

void *sum(int a,int b){
    printf(1,"%d\n",a + b);
}
int main(){
    int pid;
    int* a = (int*)malloc(2 * sizeof(int));
    char* b = (char *)malloc(12 * sizeof(char*));
    a[0] = 1;
    a[1] = 2;
    print(b);
    pid = thread_create(sum(a[0],a[1]),a);
    printf(1,"%d\n",pid);
    exit();
}
