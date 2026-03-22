#ifndef NETWORK_H
#define NETWORK_H
#include <stddef.h>

void network_send(const unsigned char *data, size_t len, unsigned char src, unsigned char dest);
void network_receive(const unsigned char *packet, size_t len);

#endif