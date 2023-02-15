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
    int i;

    registerProc(getpid(),getppid(), 0, 0);
    if ( fork() == 0) {
        registerProc(getpid(),getppid(),1,1);
        if ( fork() == 0) {
            registerProc(getpid(),getppid(), 2, 1);
            _exit(1);
        }
        wait(&i);
        printf("%d \n", WEXITSTATUS(i)); 
        int y = WEXITSTATUS(i);
        _exit(++y);    
    } 
    wait(&i);
    int z = WEXITSTATUS(i);  
    if ( fork() == 0 ) {
        registerProc(getpid(),getppid(),1,2);
        if ( fork() == 0) {
            registerProc(getpid(),getppid(), 2, 2);
            _exit(1);
        }
        wait(&i);
        printf("%d \n", WEXITSTATUS(i)); 
        int y = WEXITSTATUS(i);
        z+= ++y;
        _exit(z);
    };
    int x; wait(&x);
    printf("%d \n", WEXITSTATUS(x));
    while(wait(&i)>0) {};
    printProcRegistrations();
   //if ( fork() == 0 ) {
   // i++;
   // registerProc(getpid(),getppid(),1, 3);
   // if ( fork() == 0) { 
      //  i++;
     //   registerProc(getpid(),getppid(), 2, 3); _exit(0);
    //     }   
    //if ( fork() == 0) { 
    //    i++;
    //    registerProc(getpid(),getppid(), 2, 4); _exit(0);
    //     }
    //if ( fork() == 0) { 
    //    i++;
    //    registerProc(getpid(),getppid(), 2, 5); _exit(0); 
    //    }   
    //if ( fork() == 0) { 
    //    i++;
    //    registerProc(getpid(),getppid(), 2, 6); _exit(0); 
    //    }
    //wait(&i); wait(&i); wait(&i); wait(&i);

    //_exit(0);
   //}
    
}

