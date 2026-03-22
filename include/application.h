#ifndef APPLICATION_H
#define APPLICATION_H

#include <stddef.h>

void application_send(const unsigned char *data, size_t len);
void application_receive(const unsigned char *data, size_t len);

#endif