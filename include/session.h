#ifndef SESSION_H
#define SESSION_H

#include <stddef.h>

void session_send(const unsigned char *data, size_t len);
void session_receive(const unsigned char *data, size_t len);

#endif