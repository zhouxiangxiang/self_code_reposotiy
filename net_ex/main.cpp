#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/fcntl.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "./debug.h"

bool init_addr(struct sockaddr_in *addr, short family, unsigned short port, const char* ipaddr) {
    memset((void*)addr, 0, sizeof(struct sockaddr));
    addr->sin_family = family;
    addr->sin_port = htons(port);
    inet_aton(ipaddr, &(addr->sin_addr));

    return true;
}

bool set_nonblock(int fd) {
    fcntl(fd, F_SETFL, O_NONBLOCK);
    return true;
}

bool set_reuseAddr(int fd) {
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, "1", strlen("1"));
    setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, "1", strlen("1"));
    return true;
}

int create_socket(int domain, int type, int protocol) {
    return socket(domain, type, protocol);
}

int bind_socket(int fd, const struct sockaddr *paddr, socklen_t len) { 
  return bind(fd, paddr, len);
}

int main() {
    int fd = -1;
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    int cfd = -1;
    struct sockaddr_in caddr;
    socklen_t  clen = sizeof(caddr);

    init_addr(&addr, AF_INET, 8888, "127.0.0.1");

    if ( (fd = create_socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("error: %s\n", strerror(errno));
        return -1;
    }

    set_nonblock(fd);
    set_reuseAddr(fd);

    if ( bind_socket(fd, (struct sockaddr*)&addr, len) < 0) {
        printf("error: %s\n", strerror(errno));
        return -1;
    }

    if (listen(fd, 10) != 0) {
        printf("error: %s\n", strerror(errno));
        return -1;
    }

    cfd = accept(fd, (struct sockaddr*)&caddr, &clen);
    if (cfd < 0) {
        printf("-- error: %s : %s\n", get_errnoStr(errno), strerror(errno));
    }

    return 0;
}
