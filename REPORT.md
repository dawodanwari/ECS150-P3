# ECS150-P3 Report

## Phase 1: Semaphore API
- Implemented the semaphore API as defined in sem.h
- Created "struct semaphore" and defined the queue and internall count. 
- Implemented "sem_create" that allocates and initialize a semaphore, creates subsequent queue, and returns NULL for allocation failure.
- Implemented "sem_destroy" which deallocates a semaphore, returns -1 if sem is NULL or threads are blocked and returns 0 is semaphore is   destroyed.
- Implemented "sem_down" which initializes a thread id and will try to take a semaphore, if the semaphore is unavailable then the thread     is blocked. This should return -1 if an error occurs or 0 if the semaphore is taken.
- Implemented "sem_up" that will release a semaphore/unblock a thread if the thread waiting list or queue is not empty
- Implemented "sem_getvalue" that will return 0 if the semaphore is inspected correctly. This will assign negative number whose absolute      value is the count of the number of threads currently blocked if the sem count is equal to 0. If the sem count is greater than zero,      then assigns the internal count to *sval.



## Phase 2:
- We were not able to work on phase 2 during the alloted time.
