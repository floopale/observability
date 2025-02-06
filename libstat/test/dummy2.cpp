#include "libstat.hpp"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {
    
    stat_init();
    stat_update();
    const char *stat=get_stat_str();
    printf("at start: %s\n",stat);
    for (int i=0;i<1000000;i++) {
        stat_update();
    }
    stat_update();
    printf("at end start: %s\n",stat);
    return 0;
}
