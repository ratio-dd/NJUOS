/* test gdb debug glibc source code*/

#include <stdio.h>
#include <unistd.h>

int main(){
    /*gdb can't find write().
    It shows in io directory, but glibc source code don't have that. */
    write(1,"Hello world!\n",12);
    printf("%d + %d = %d",1,1,1+1);
}