#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>

#define THREADNUM 4

void *updaterThread(void *arg){
  register int i = (int)arg;

  int a = 10;
  for(int j=0; j<a; j++) {
    i^=2;
  }

  fprintf(stderr,"child thread: %d\n", i); 
  return NULL;
}

int main(int argc, char *argv[]){
  fprintf(stderr,"start program\n"); 

  pthread_t pid[THREADNUM];
  int i;
  for(i=0; i<THREADNUM; i++)
  {
    pthread_create(&pid[i], NULL, updaterThread, (void*)i);
  }

  for(i=0; i<THREADNUM; i++) 
    pthread_join(pid[i],NULL);

  fprintf(stderr,"end program\n"); 
}
