#include "physical.h"
#include <stdio.h>
#include <string.h>

#define PHYSICAL_BUFFER_SIZE 2048
static unsigned char physical_buffer[PHYSICAL_BUFFER_SIZE];
static size_t buffer_len = 0;

extern void datalink_receive(const unsigned char *frame, size_t len);

void physical_send(const unsigned char *data, size_t len) {
  if (len + buffer_len > PHYSICAL_BUFFER_SIZE) {
    printf("[Physical] Buffer overflow, dati scartati\n");
    return;
  }

  memcpy(physical_buffer + buffer_len, data, len);
  buffer_len += len;

  printf("[Physical] Sending %zu bytes: ", len);
  for (size_t i = 0; i < len; i++) printf("%02X ", data[i]);
  printf("\n");

  physical_receive(data, len);

  printf("\n");
  return;
}

void physical_receive(const unsigned char *data, size_t len) {
  printf("[Physical] Received %zu bytes\n", len);
  datalink_receive(data, len);

  printf("\n");
  return;
}