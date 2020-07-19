#pragma once
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

void write_0x12345678(uint8_t *b1, uint8_t *b2);
void run(char *n1, char *n2);