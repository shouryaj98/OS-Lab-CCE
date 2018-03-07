#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int var;
sem_t mutex,rmutex;
int rcount=0;
void *writer(void *arg);
void *reader(void * arg);

void *write(void *arg)
{
	sem_wait(&mutex);
	var++;
	printf(" Written:%d\n",var);
	sem_post(&mutex);
}

void *read(void * arg)
{
	sem_wait(&rmutex);
	rcount++;
	if(rcount==1)
	{
		sem_wait(&mutex);
	}
	sem_post(&rmutex);

	printf("Reading %d\n",var);

	sem_wait(&rmutex);
	rcount--;
	if(rcount==0)
	{
		sem_post(&mutex);
	}
	sem_post(&rmutex);
}

int main(int argc, const char * argv[])
{
    int i, NumThreads;
    sem_post(&mutex);
    sem_post(&rmutex);
    pthread_t *readers, *writers;
    NumThreads = abs(atoi(argv[1]));
    writers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);
    readers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);

    for (i = 0; i < NumThreads; i++)
    {
  	 pthread_create(&readers[i], NULL, &read, NULL);
       	 pthread_create(&writers[i], NULL, &write, NULL);	
    }
    for (i = 0; i < NumThreads; i++)
    {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }

    return 0;
}
