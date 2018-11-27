CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o persona.o myconnection.o

LIBS =		-lmysqlcppconn -lmysqlcppconn-static

TARGET =	TP2

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
