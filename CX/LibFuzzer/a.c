#include <stdint.h>
#include <stdlib.h>
// fuzzer generates random input and calls LLVMFuzzerTestOneInput
// use the input to try crashing a function under test (with help of ASAN, UBSAN)
// 0 means accept the input
// -1 means reject the input
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	if (size == 5 && data[4] == 'c') { // simulate a vulnerability
		abort();
	}
	return 0;
}
