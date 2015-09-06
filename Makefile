all: so test_c test_dlopen_c test_dlopen_go

so:
	go build -buildmode=c-shared -o librandn.so librandn.go
test_c:
	gcc -o randn_test randn_test.c -lrandn -L.
	LD_LIBRARY_PATH=. ./randn_test || true
test_dlopen_c:
	gcc -o randn_test_dlopen randn_test_dlopen.c -ldl
	LD_LIBRARY_PATH=. ./randn_test_dlopen || true
test_dlopen_go:
	LD_LIBRARY_PATH=. go run randn_test_dlopen.go