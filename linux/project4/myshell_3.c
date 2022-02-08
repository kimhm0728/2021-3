#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define DELIM " \t \n" // 공백, 탭, 개행으로 이루어진 구분자 선언
#define INPUT_SIZE 100

int main() {
        char* args[10]; // execvp() 인자로 넣을 배열
        char input[INPUT_SIZE]; // 명령을 입력받을 배열
        int argn, pid;
        char* s;
        char* next; // strtok_r()의 포인터
        int type;
        int pipefd[2];
	int k;
	char *command1[10];
	char *command2[10];
        while(1) {
                int status;
                int i;
                int fd;
                printf("shell>> ");
                fgets(input, INPUT_SIZE - 1, stdin); // 명령 입력
                argn = 0; // args의 인덱스
                s = strtok_r(input, DELIM, &next);
                while(s) { // 명령 [옵션] [인자] 분리
                        args[argn++] = s;
                        s = strtok_r(NULL, DELIM, &next);
                }
                args[argn] = NULL; // 인수의 끝을 의미하는 문자 추가 
                if (argn == 0) // 명령이 없으면 루프 계속
                        continue;
                if (!strcmp(args[0], "quit")) // quit 입력 시  while 벗어남 
                        break;

                for(i = 0; i < argn; i++) {
                        if (!strcmp(args[i], ">")) { // 입력받은 명령에 >가 있을 경우 
                                type = 1;
                                break;
                        }
                        else if (!strcmp(args[i], "<")) { // 입력받은 명령에 <가 있을 경우
                                type = 2;
                                break;
                        }
			else if (!strcmp(args[i], "|")) { // 입력받은 명령에 |가 있을 경우
                                type = 3;
				command1[i] = NULL;
                                break;
                        }
                        else // 입력받은 명령에 특수문자가 없을 경우
                                type = 0;
			command1[i] = args[i];
                }
		if(type == 1) {
			pid = fork();
			if(pid > 0)
				wait(&status);
			else if(pid == 0) {
				fd = open(args[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
                       		dup2(fd, 1);
                       		close(fd);
				args[i] = NULL; // 명령어 이후부터 NULL로 채우기
                                args[i+1] = NULL;
                                for(i = i; args[i] != NULL; i++)
                                                args[i] = args[i+2];
                                args[i] = NULL;
				execvp(args[0], args); // 명령 실행
			}
			else
				printf("fork() error !!!\n");
		}
		else if(type == 2) {
			pid = fork();
                        if(pid > 0)
                                wait(&status);
                        else if(pid == 0) {
                                fd = open(args[i + 1], O_RDONLY);
                                dup2(fd, 0);
                                close(fd);
                                args[i] = NULL; // 명령어 이후부터 NULL로 채우기
                                args[i+1] = NULL;
                                for(i = i; args[i] != NULL; i++)
                                                args[i] = args[i+2];
                                args[i] = NULL;
				execvp(args[0], args); // 명령 실행
                        }
			else
				printf("fork() error !!!\n");

		}
		else if(type == 3) {
			k = 0;
			for(int j=i+1; args[j] != NULL; j++) {
				command2[k] = args[j];
				k++;
			} 
			command2[k] = NULL;
			pipe(pipefd);
			if(fork() == 0) { // 명령1 처리
				close(1);
				dup2(pipefd[1], 1);
				close(pipefd[0]);
				close(pipefd[1]);

				execvp(command1[0], command1);
				exit(0);
			}
			if(fork() == 0) { // 명령2 처리
				close(0);
				dup2(pipefd[0], 0);
				close(pipefd[0]);
				close(pipefd[1]);

				execvp(command2[0], command2);
				exit(0);
			}

			close(pipefd[0]);
			close(pipefd[1]);
			wait(&status);
		}
		else if(type == 0) {
			pid = fork();
			if(pid > 0) 
				wait(&status);
			else if(pid == 0)
				execvp(args[0], args);
			else
				printf("fork() error !!!\n");
		}
	}
}
