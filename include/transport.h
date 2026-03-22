#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <stddef.h>

void transport_send(const unsigned char *data, size_t len, unsigned char src_port, unsigned char dest_port);
void transport_receive(const unsigned char *segment, size_t len);

#endif