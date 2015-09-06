#include <stdio.h>
#include "librandn.h"

void main() {
	printf("test Go 1.5 shared library: %lli\n", RandN(100ll));
}