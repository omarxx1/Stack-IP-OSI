#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <stddef.h>
void physical_send(const unsigned char *data, size_t len);
void physical_receive(const unsigned char *data, size_t len);

#endif