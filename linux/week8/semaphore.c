#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t	s;
int count = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
void *thread(void* unused) {
	int i, j;
	for(i=0;i<10000;i++)
		for(j=0;j<10000;j++) {
			sem_wait(&s);
			count++;
			count--;
			sem_post(&s);
		}
}

void main() {
	int n;
	sem_init(&s, 0, 1); // 세마포어 변수 초기값 = 1
	pthread_t tid[10];
	for(n=0;n<10;n++)
		pthread_create(&tid[n], NULL, &thread, NULL);
	for(n=0;n<10;n++)
		pthread_join(tid[n], NULL);

	printf("count = %d\n", count);
}
