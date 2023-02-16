/*
 * processlab - part2.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
*/

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

#include "./libprocesslab/libprocesslab.h"

#define m 1000000
// question2 calcule la somme des m premiers nombres naturels 1+2+...+m

// nb est le nombre de threads qui vont contribuer au calcul
#define nb 8

//tableau somme est utilisé pour le calcul des sommes patielles par les threads
long somme[nb];


// fonction exécutée par chaque thread créé
void*contribution(void* p)
{
  // TODO
  int *no= (int *)p;
  long s = 0;
  long start = (*no * m/nb) + 1;
  long end = (*no+1) * m/nb;

  for(long i = start; i<= end; i++ ) {
    s+= i;
  }
  somme[*no] = s;
  return NULL;
}


void question2( )
{
    // TODO
    pthread_t thread_id;
    for(int i = 0; i < nb; i++ ) {
      pthread_create(&thread_id, NULL, contribution, (void *)&i);
      pthread_join(thread_id, NULL);
    }
    long long resultat = 0; 
    for(int j = 0; j < nb; j++){
      resultat += somme[j];
    }
    printf("%llu \n", resultat);
    long long multGauss = (m+1)/2;
    printf("%llu \n",m * multGauss);
    
}

