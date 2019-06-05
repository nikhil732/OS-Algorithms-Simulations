#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int N;
#define WAITING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

int state[100];
int phil[100];

sem_t mutex;
sem_t S[100];

void test(int phnum)
{
    if (state[phnum] == HUNGRY
        && state[LEFT] != EATING
        && state[RIGHT] != EATING) {
        
        state[phnum] = EATING;



        printf("Philosopher %d takes fork %d and %d\n",
                      phnum + 1, LEFT + 1, phnum + 1);

        printf("Philosopher %d is Eating\n", phnum + 1);
        sem_post(&S[phnum]);
    }
}

void take_fork(int phnum)
{

    sem_wait(&mutex);

   
    state[phnum] = HUNGRY;

    printf("Philosopher %d is Hungry\n", phnum + 1);

    
    test(phnum);

    sem_post(&mutex);

        sem_wait(&S[phnum]);


}
void put_fork(int phnum)
{

    sem_wait(&mutex);

   
    state[phnum] = WAITING;

    printf("Philosopher %d putting fork %d and %d down\n",
           phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is waiting\n", phnum + 1);

    test(LEFT);
    test(RIGHT);

    sem_post(&mutex);
}

void* philospher(void* num)
{

    while (1) {

        int* i = num;



        take_fork(*i);



        put_fork(*i);
    }
}

int main()
{

    int i;
    printf("Enter the no.of philosophers\n");
    scanf("%d",&N);
    printf("Enter the ID's of philosophers  :\n");
    printf("Please start their ID's with  0  \n");
    for(i=0;i<N;i++)
        scanf("%d",&phil[i]);

    pthread_t thread_id[N];

    
    sem_init(&mutex, 0, 1);

    for (i = 0; i < N; i++)

        sem_init(&S[i], 0, 0);

    for (i = 0; i < N; i++) {

        
        pthread_create(&thread_id[i], NULL,
                       philospher, &phil[i]);

        printf("Philosopher %d is waiting\n", i + 1);
    }

    for (i = 0; i < N; i++)

        pthread_join(thread_id[i], NULL);
}
