#include "presentation.h"
#include "session.h"
#include <stdio.h>

static void simple_encode(const unsigned char *input, unsigned char *output, size_t len) {
  for(size_t i=0;i<len;i++) output[i]=input[i]^0xAA;
  return;
}

static void simple_decode(const unsigned char *input, unsigned char *output, size_t len) {
  for(size_t i=0;i<len;i++) output[i]=input[i]^0xAA;
  return;
}

void presentation_send(const unsigned char *data, size_t len) {
  unsigned char encoded[len];
  simple_encode(data, encoded, len);
  printf("[Presentation] Sending encoded data\n");
  session_send(encoded, len);

  printf("\n");
  return;
}

void presentation_receive(const unsigned char *data, size_t len) {
  unsigned char decoded[len];
  simple_decode(data, decoded, len);
  printf("[Presentation] Decoded data\n");
  extern void application_receive(const unsigned char *data, size_t len);
  application_receive(decoded, len);

  printf("\n");
  return;
}