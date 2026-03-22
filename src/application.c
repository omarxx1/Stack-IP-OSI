#include "application.h"
#include "presentation.h"
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1024
static unsigned char receive_buffer[MAX_MESSAGE_SIZE];
static size_t receive_len = 0;

void application_send(const unsigned char *data, size_t len) {
  printf("[Application] Sending message: %.*s\n", (int)len, data);
  presentation_send(data, len);
  printf("\n");
  return;
}

void application_receive(const unsigned char *data, size_t len) {
  if (receive_len + len > MAX_MESSAGE_SIZE) {
    printf("[Application] Message too big, discarded\n");
    receive_len = 0;
    return;
  }

  memcpy(receive_buffer + receive_len, data, len);
  receive_len += len;

  printf("[Application] Received segment: %.*s\n", (int)len, data);

  if (len < 8) { // last segment
    printf("\n[Application] Full message received (%zu bytes):\n%.*s\n", receive_len, (int)receive_len, receive_buffer);
    receive_len = 0;
  }
  printf("\n");
  return;
}