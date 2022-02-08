#include <stdio.h>
#include <pthread.h>

struct th_param {
	char ch;
	int count;
};

void *thread(void* param) {
	struct th_param *p = (struct th_param*)param;
	int i;
	for(i=0;i<p->count;i++)
		fputc(p->ch, stderr);
	printf("\n");
}

int main() {
	pthread_t tid1, tid2;
	struct th_param tid1_arg, tid2_arg;
		tid1_arg.ch = 'O';
		tid1_arg.count = 300;
		pthread_create(&tid1, NULL, &thread, &tid1_arg);
		tid2_arg.ch = 'X';
		tid2_arg.count = 300;
		pthread_create(&tid2, NULL, &thread, &tid2_arg);

		pthread_join(tid1, NULL);
		pthread_join(tid2, NULL);
}
