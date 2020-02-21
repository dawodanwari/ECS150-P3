#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "queue.h"
#include "sem.h"
#include "thread.h"

struct semaphore 
{
    size_t count;
	queue_t queue;
};

// allocates and initialize a semaphore, creates subsequent queue, and returns NULL for allocation failure
sem_t sem_create(size_t count) 
{
	sem_t sem = (sem_t) malloc (sizeof(sem_t));
	queue_t queue = (queue_t) malloc (sizeof(queue_t));
	sem->queue; 
	queue = queue_create();
	if(!sem_create)
	{
	    perror("Failed to allocate memory for sem_crete");
	    return NULL;
	}
	return sem;
}

 //deallocates a semaphore, returns -1 if sem is NULL or threads are blocked
 //returns 0 is semaphore is destroyed
int sem_destroy(sem_t sem) 
{
	if (sem == NULL || queue_length(sem->queue) >= 1) 
	{
	    perror("Failed to allocate sem_destroy");
		return -1;
	}
	
	if (sem != NULL)
	{
	    queue_destroy(sem->queue); 
		free(sem);
		return 0;
	}
}

 //initialize a thread id
 //returns -1 if semaphore is NULL and 0 if semaphore is taken
 //thread is blocked if taking unavailable semaphore
int sem_down(sem_t sem) 
{
    pthread_t thread_id;
    thread_id = pthread_self();
    
	if(sem == NULL) 
	{
	    perror("Allocation error");
		return -1;
	}
	
	enter_critical_section();
	while(sem->count == 0) 
	{
		queue_enqueue(sem->queue, (void*) thread_id);
		thread_block();
	}	
	sem->count--;
	exit_critical_section(); 
	return 0;
}

 //initialize a thread tid
 //returns -1 if semaphore is NULL and 0 if semaphore is released
 //thread is unblocked if semaphore is not empty
int sem_up(sem_t sem) 
{
    pthread_t tid;
	if(sem == NULL || queue_length(sem->queue) == 0) 
	{
	    perror("Allocation error");
		return -1;
	}
	
	enter_critical_section();
	sem->count++;
	if(queue_length(sem->queue) != 0) 
	{ 
	    queue_dequeue(sem->queue, (void*) &tid);
		thread_unblock(tid);
	}	
    exit_critical_section();
	return 0;
}

 //returns -1 if semaphore or sval is NULL and 0 if semaphore was inspected correctly
 //if semaphore count is equal to zero then assign a negative number whose absolute value is the count of the number of threads currently blocked
 //if semaphore count is greater than 0, assign count to sval pointer
int sem_getvalue(sem_t sem, int *sval) 
{
    void* thread_id;
    thread_id = sem->queue;
    
	if((sem || *sval) == NULL);
	{
	    perror("Allocation error");
		return -1;
	} 
	
	if(sem == 0) 
	{
		*sval = (queue_length(thread_id)) * -1;
	}
	
	else if(sem->count > 0) 
	{
		*sval = sem->count;
	}
	
	return 0;
}
