#ifndef DATALINK_H
#define DATALINK_H

#include <stddef.h>

void datalink_send(const unsigned char *data, size_t len);
void datalink_receive(const unsigned char *frame, size_t len);
#endif