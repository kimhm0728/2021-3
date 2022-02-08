#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

int main() {
	int n, pid, shmid, semid, *count, status;
	struct sembuf p_op = {0, -1, SEM_UNDO},
		      v_op = {0, 1, SEM_UNDO};

	shmid = shmget(IPC_PRIVATE, sizeof(*count), 0666);
	count = (int*)shmat(shmid, NULL, 0);
	semid = semget(IPC_PRIVATE, 1, 0666); // 세마포어 생성
	semctl(semid, 0, SETVAL, 1); // 세마포어 초기값 (=1)
	*count = 0;
	pid = fork();

	if(pid > 0) { // 부모 프로세스
		for(n=0;n<100000;n++) {
			semop(semid, &p_op, 1); // P 연산
			*count = *count + 1;
			semop(semid, &v_op, 1); // V 연산
		}
		wait(&status);
		printf("count = %d\n", *count);
		shmdt(count);
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, 0, IPC_RMID, NULL); // 세마포어 삭제
	}
	else if(pid == 0) { // 자식 프로세스
		for(n=0;n<100000;n++) {
			semop(semid, &p_op, 1); // P 연산
			*count = *count - 1;
			semop(semid, &v_op, 1); // V 연산
		}
	}
}
