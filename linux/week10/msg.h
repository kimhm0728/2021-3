#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
	long m_type;
	char m_data[1024];
}Mesg;
