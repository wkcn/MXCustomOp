all:
	g++ test.cpp -I include -I 3rdparty/dmlc-core/include -I 3rdparty/tvm/include -I 3rdparty/dlpack/include -o test
run:
	./test
