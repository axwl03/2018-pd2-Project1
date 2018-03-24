player:
AI.o proj_class.o
g++ -o player AI.o proj_class.o

AI.o:
AI.cpp proj_class.h
g++ -c AI.cpp

proj_class.o:
proj_class.cpp proj_class.h
g++ -c proj_class.cpp

clean:
rm *.o
