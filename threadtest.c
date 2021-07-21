#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h> 

int value = 10;
void test_func(void* param);
int main(){
    thread_create(test_func, NULL);
    exit();
}
void test_func(void* param){
    value += 10;
    printf(1,"value in child thread is %d\n",value);
    return;
}