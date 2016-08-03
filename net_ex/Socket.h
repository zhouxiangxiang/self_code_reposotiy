#ifndef __SOCKET__
#define __SOCKET__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/fcntl.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "./debug.h"

bool init_addr(struct sockaddr_in *addr, short family, unsigned short port, const char* ipaddr);

bool set_nonblock(int fd);

bool set_reuseAddr(int fd);

int create_socket(int domain, int type, int protocol);

int bind_socket(int fd, const struct sockaddr *paddr, socklen_t len);

#endif // 
