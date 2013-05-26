CPP=g++
CPPFLAGS= -Wall -g
CLEAN= rm -f

cmatch3: main.o zapovn.o zmina.o zsuv.o pole10x10.o
	$(CPP) $(CPPFLAGS) -o $@ $^

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c $^

zapovn.o: zapovn.cpp
	$(CPP) $(CPPFLAGS) -c $^

zmina.o: zmina.cpp
	$(CPP) $(CPPFLAGS) -c $^

zsuv.o: zsuv.cpp
	$(CPP) $(CPPFLAGS) -c $^

pole10x10.o: pole10x10.cpp
	$(CPP) $(CPPFLAGS) -c $^

clean:
	$(CLEAN) *.o cmatch3