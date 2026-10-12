/*
 * Independent C11 oracle for Uniswap V3 SqrtPriceMath next-sqrt (uint64 / Q32).
 * Original C11 at Q32=2^32 (not Q96). Proofs live in kbelludoo/lin-open.
 */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Q32 4294967296ULL
/* Full oracle: see kbelludoo/lin-open test/oracles/uniswap_v3_next_sqrt_c11.c */
int main(void) {
  puts("see lin-open test/oracles/uniswap_v3_next_sqrt_c11.c");
  return 0;
}
