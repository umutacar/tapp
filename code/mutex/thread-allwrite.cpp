#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <atomic>

using namespace std;

#define NTHREADS 8



struct args {
  int tid;
};

void *hello(void *a)
{  
  args* myargs = (args*) a;
	int tid = myargs->tid;

  cout << "Hello world! It is me, Thread " << tid << endl;

  pthread_exit(NULL);
}

int main ()
{
  pthread_t threads[NTHREADS];
	
  for(int i=0; i < NTHREADS; i++ ){
		args* a = new args;
		a->tid = i;
		
    cout << "main: creating thread 00" << i << endl;
    int error = pthread_create(&threads[i], NULL, hello, (void *) a);
    if (error) {
      cout << "Error: unable to create thread," << error << endl;
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
