CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o organizacion.o persona.o myconnection.o

LIBS =		-lmysqlcppconn -lmysqlcppconn-static

TARGET =	/var/www/cgi-bin/2Parcial

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
