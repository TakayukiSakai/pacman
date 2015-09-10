#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int client_fd, listen_fd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    // create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    // bind
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9374;
    server_len = sizeof(server_address);
    bind(listen_fd, (struct sockaddr *) &server_address, server_len);

    // listen
    listen(listen_fd, 5);
    while(1) {
        char ch;
        printf("server waiting\n");

        client_fd = accept(listen_fd, (struct sockaddr *)&client_address, &client_len);

        // read
        read(client_fd, &ch, 1);
        ch++;
        write(client_fd, &ch, 1);

        // TCP connection close
        close(client_fd);
    }
}
