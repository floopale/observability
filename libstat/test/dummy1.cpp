#include "libstat.hpp"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>

void *waste_pointer[100];
unsigned long dumb_fibonacci(unsigned long xth) {
    if (xth<2) { return 1;}
    return dumb_fibonacci(xth-1)+dumb_fibonacci(xth-2);
}

void waste_memory(unsigned long mb_to_waste) {
    for (int i=0;i<100;i++) {
        waste_pointer[i]=malloc(mb_to_waste*1024*1024);
        memset(waste_pointer[i],1,mb_to_waste*1024*1024);
    }
}

int main (int argc, char **argv) {
    
    stat_init();
    stat_update();
    const char *stat=get_stat_str();
    printf("at start: %s\n",stat);
    printf("now doing some cpu intensive stuff\n");
    for (int i=0;i<100;i++) {
        if (i%10==0) printf("round %i\n",i);
        dumb_fibonacci(35);
    }
    stat_update();
    printf("stats after dumb fibonacci: %s\n",stat);
    waste_memory(5);
    stat_update();
    printf("stats after wasting memory, 500 MB RSS should be wasted: %s\n",stat);

    for (int i=0;i<50;i++) {
        free(waste_pointer[i]);
    }
    stat_update();
    printf("stats after release half of memory:%s\n",stat);

    FILE *f=fopen("/tmp/x","wb");
    for (int i=0;i<5;i++) {
        fwrite(waste_pointer[99],1024*1024,5,f);
    }
    fclose(f);
    stat_update();
    printf("stats after writing 5 mb to disk:%s\n",stat);

    f=fopen("/tmp/x2","wb");
    for (int i=0;i<5;i++) {
        fwrite(waste_pointer[99],1024*1024,5,f);
        fwrite(waste_pointer[99],1024,5,f);
        ftruncate(fileno(f),1024*1024);
        fwrite(waste_pointer[99],1024,5,f);
    }
    fclose(f);
    stat_update();
    printf("stats after writing 5 mb to disk and truncate around:%s\n",stat);

    for (int i=50;i<100;i++) {
        free(waste_pointer[i]);
    }
    stat_update();
    printf("stats after release all wasted_memory:%s\n",stat);

 
    printf("now doing some cpu intensive stuff again\n");
    for (int i=0;i<100;i++) {
        if (i%10==0) printf("round %i\n",i);
        dumb_fibonacci(35);
    }
    stat_update();
    printf("stats after dumb fibonacci: %s\n",stat);
    return 0;
}
