target: median.o
	g++ -g -o median median.cc

median.o: median.cc
	g++ -g -c median.cc

clean:
	\rm *.o median
	\rm -rf *.dSYM
