#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#define DELIM " \t\n" // 공백, 탭, 개행으로 이루어진 구분자 선언
#define INPUT_SIZE 100
#define BUF_SIZE 250
int main() {
	char* args[10]; // exevp() 인자로 넣을 배열
	char input[INPUT_SIZE]; // 명령을 입력받을 배열
	char path[BUF_SIZE]; // 경로 출력할 배열
	int argn, pid;
	char* s;
	char* next; // strtok_r()의 포인터
	while(1) {
		getcwd(path, BUF_SIZE);
		printf("%s>>$ ", path); 
		fgets(input, INPUT_SIZE - 1, stdin); // 명령 입력 
		argn = 0; // args의 인덱스
		s = strtok_r(input, DELIM, &next);
		while(s) { // 명령 [옵션] [인자] 분리
			args[argn++] = s;
			s = strtok_r(NULL, DELIM, &next);
		}
		args[argn] = (char*)NULL; // 인수의 끝에 NULL 추가
		if (argn == 0) // 명령이 없으면 루프 계속
			continue;
		if(!strcmp(args[0], "quit")) // quit 입력 시  while 벗어남
			break;
		pid = fork();
		if(pid > 0) // 부모 프로세스
			wait(NULL); 
		else if(pid == 0) // 자식 프로세스
			execvp(args[0], args);
		else if(pid == -1) // 자식 프로세스 생성 실패
			printf("fork failed\n");
	}
	exit(0);
}
