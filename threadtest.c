#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h> 

int value = 10;
void test_func1(void* param);
void test_func2(void* param);
int main(){
    thread_create(test_func1, NULL);
    //sleep(100);
    thread_create(test_func2, NULL);
    exit();
}
void test_func1(void* param){
    value += 10;
    printf(1,"value in child thread fun1 is %d\n",value);
    return;
}
void test_func2(void* param){
    value += 10;
    printf(1,"value in child thread func2 is %d\n",value);
    return;
}