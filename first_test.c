#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    char* a = (char*)malloc(12 * sizeof(char));
    print(a);
    clone();
    exit();
}
