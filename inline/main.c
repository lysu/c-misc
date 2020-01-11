#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SIZE  1023*1024*1024

int main(int argc, char *argv[]) {
    char *p;
    if ((p = (char *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0)) ==
        (void *) -1) {
        perror("mmap");
    }
    memset(p, 'c', SIZE);
    int r = madvise(p, SIZE, MADV_FREE);
    if (r < 0) {
        perror("madvise");
    }
    printf("Get 1 GB...\n");
    sleep(3000);
    return 0;
}