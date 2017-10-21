P2.out: Proj2app.o CMaze.o SetLimits.o
	g++ -g -o P2.out Proj2app.o CMaze.o

Proj2app.o: Proj2app.cpp CMaze.h SetLimits.h
	g++ -g -c Proj2app.cpp

CMaze.o: CMaze.cpp CMaze.h
	g++ -g -c CMaze.cpp

SetLimits.o: SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

clean:
	rm *.o P2.out

run : P2.out
	clear
	P2.out

submit : Proj2app.cpp CMaze.h CMaze.cpp makefile README.txt
	rm -rf davidsonP2
	mkdir davidsonP2
	cp Proj2app.cpp davidsonP2
	cp CMaze.h davidsonP2
	cp CMaze.cpp davidsonP2
	cp makefile davidsonP2
	cp README.txt davidsonP2
	tar cfvz davidsonP2.tgz davidsonP2
	cp davidsonP2.tgz ~tiawatts/cs215drop
