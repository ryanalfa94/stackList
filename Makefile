PJ1	:main.o util.o ListStack_study.o ListStack_write.o
	 g++ -Wall -o PJ1 main.o util.o ListStack_study.o ListStack_write.o

main.o	:main.cpp structs.h util.h ListStack_study.h ListStack_write.h
	 g++ -Wall -c main.cpp

util.o	:util.cpp structs.h util.h
	 g++ -Wall -c util.cpp

ListStack_study.o	:ListStack_study.cpp structs.h ListStack_study.h
	 g++ -Wall -c ListStack_study.cpp

ListStack_write.o	:ListStack_write.cpp structs.h ListStack_write.h
	 g++ -Wall -c ListStack_write.cpp

clean	:
	rm *.o PJ1
