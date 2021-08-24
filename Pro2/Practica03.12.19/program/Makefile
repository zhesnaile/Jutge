OPCIONS	:= -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
TARGET	:= program
OBJS	:= Fecha.o Fotografia.o Album.o Coleccion.o $(TARGET).o 
HPPS	:= Fecha.hh Fotografia.hh Album.hh Coleccion.hh
CPPS    := *.cc

all:	$(TARGET).exe

%.o:	%.cc
	g++ -c $(OPCIONS) $<
	

$(TARGET).exe:	$(OBJS)
	g++ -o $(TARGET).exe *.o

test:
	./$(TARGET).exe <sample.inp >sample1.out
	diff sample1.out sample.cor

tar:
	tar cvf $(TARGET).tar Makefile $(TARGET).exe $(HPPS) $(CPPS)
clean:
	rm -f *.o
	rm -f *~
	rm -f *stackdump
	chmod a-x *.cc
	chmod a-x *.hh
	chmod a-x Makefile
superclean: clean
	rm -f *.exe
