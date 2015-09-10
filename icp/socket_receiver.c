#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <poll.h>
#include <stdio.h>
#include <errno.h>

#define UNIXDOMAIN_PATH "/tmp/server.sock"

int main(int argc, char *argv[]){
    struct sockaddr_un addr;
    int srvfd;

    srvfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(srvfd < 0){
        fprintf(stderr, "socket error errno[%d]\n", errno);
        exit(-1);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, UNIXDOMAIN_PATH);

    if(connect(srvfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) < 0){
        fprintf(stderr, "connect error errno[%d]\n", errno);
        exit(-1);
    }

    if(write(srvfd, "hello world", strlen("hello world")) < 0){
        fprintf(stderr, "write error errno[%d]\n", errno);
        exit(-1);
    }

    close(srvfd);

    return 0;
}
