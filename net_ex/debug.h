#ifndef __DEBUG_SOCKET_ERROR__
#define __DEBUG_SOCKET_ERROR__

#include <sys/types.h>
#include <sys/socket.h>

const char* get_errnoStr(const int no) {
    switch (no) {
    case EAGAIN:
        return "EAGAIN";
    case EBADF:
        return "EBADF";
    case ECONNABORTED:
        return "ECONNABORTED";
    case EFAULT:
        return "EFAULT";
    case EINTR:
        return "EINTR";
    case EINVAL:
        return "EINVAL";
    case EMFILE:
        return "EMFILE";
    case ENFILE:
        return "ENFILE";
    case ENOBUFS:
        return "ENOBUFS";
    case ENOMEM:
        return "ENOMEM";
    case ENOTSOCK:
        return "ENOTSOCK";
    case EOPNOTSUPP:
        return "EOPNOTSUPP";
    case EPROTO:
        return "EPROTO";
    case EPERM:
        return "EPERM";
    default:
        return "unknown";
    }
}

#endif // 
