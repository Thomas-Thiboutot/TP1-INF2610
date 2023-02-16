/*
 * processlab - part1.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
*/

#include "libprocesslab/libprocesslab.h"

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

void question1()
{
    // TODO
    int i,z,w;
    registerProc(getpid(),getppid(), 0, 0);
    if ( fork() == 0) {
        registerProc(getpid(),getppid(),1,1);
        if ( fork() == 0) {
            registerProc(getpid(),getppid(), 2, 1);
            _exit(1);
        }
        wait(&i);
        _exit(WEXITSTATUS(i) + 1);    
    } 
    wait(&i); 
    //printf("%d \n", WEXITSTATUS(i));
    if ( fork() == 0 ) {
        registerProc(getpid(),getppid(),1,2);
        if ( fork() == 0) {
            registerProc(getpid(),getppid(), 2, 2);
            _exit(1);
        }
        wait(&i);
        _exit(WEXITSTATUS(i)+1);
    };
    wait(&z);
    if ( fork() == 0 ) {
        registerProc(getpid(),getppid(),1, 3);
        if ( fork() == 0) { 
            registerProc(getpid(),getppid(), 2, 3);
            _exit(1);
        }
        wait(&i);
        int x = WEXITSTATUS(i);
        if ( fork() == 0) { 
            registerProc(getpid(),getppid(), 2, 4);
            _exit(1);
        }
        wait(&i);
        int s = WEXITSTATUS(i);
        if ( fork() == 0) { 
            registerProc(getpid(),getppid(), 2, 5);
            _exit(1);
        }
        wait(&i); 
        int u = WEXITSTATUS(i); 
        if ( fork() == 0) { 
            registerProc(getpid(),getppid(), 2, 6);
            _exit(1);
        }
        wait(&i);
        int q = WEXITSTATUS(i);
        w = s + u + q + x; 
        _exit(++w);
    }
    int g; wait(&g);
    printf("%d \n", WEXITSTATUS(g)+ WEXITSTATUS(z)+ WEXITSTATUS(i));
        while(wait(&i)>0) {};
    printProcRegistrations();
    execlp("ls","ls", "-l", NULL);
    
}

