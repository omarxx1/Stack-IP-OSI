#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <stddef.h>

void presentation_send(const unsigned char *data, size_t len);
void presentation_receive(const unsigned char *data, size_t len);

#endif