//
//  main.c
//  RNG
//
//  Created by Илья Юхновский on 15.06.14.
//  Copyright (c) 2014 Phreebie. All rights reserved.
//

#include <stdio.h>
#include <signal.h>

volatile int x, quit, capture;
void sighandle(int signo);

void sighandle(int signo) {
    capture = x;
    quit = 1;
}

int main(int argc, const char * argv[])
{
    int y;
    signal(SIGALRM, sighandle);
    for (y = 0; y < 16; y++) {
        quit = 0;

        while (!quit) {
            x ^= 1;
        }
        printf("%d", capture);
        fflush(stdout);
    }
    
    printf("__________________________\n");
    return 0;
}

