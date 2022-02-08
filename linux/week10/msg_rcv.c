#include "msg.h"
#include <stdio.h>

int main() {
        int msgqid;
        Mesg msg;

        msgqid = msgget(1235L, 0);
        msgrcv(msgqid, &msg, 1024, 10L, 0);
        printf("%s\n", msg.m_data);
        msgctl(msgqid, IPC_RMID, 0);
}
