#include <stdio.h>
#include <dlfcn.h>

void main() {
	void *handle;
	long long int (*RandN)(long long int);
	char *error;
	handle = dlopen ("librandn.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "load err: %s\n", dlerror());
		return;
	}
	RandN = dlsym(handle, "RandN");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "load err: %s\n", dlerror());
		return;
	}
	printf("randn(100) = %lli\n", (*RandN)(100ll));
	RandN = NULL;
}