all:
	g++ -fpic -c adddata.cpp -o ../build/adddata.o -I .
	g++ -fpic -c bytearray.cpp -o ../build/bytearray.o -I .
	g++ -fpic -c setsize.cpp -o ../build/setsize.o -I .
	g++ -fpic -c setdata.cpp -o ../build/setdata.o -I .
	g++ -shared ../build/*.o -o ../build/libbytearray.so.0
