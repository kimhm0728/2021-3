#include "msg.h"
#include <stdio.h>
#include <string.h>

int main() {
	int msgqid;
	Mesg msg;

	strcpy(msg.m_data, "God bless you !!!");
	msg.m_type = 10L;
	msgqid = msgget(1235L, 0600|IPC_CREAT);
	msgsnd(msgqid, &msg, 1024, 0);
}
