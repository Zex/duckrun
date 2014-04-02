CC			= gcc
CXX			= g++
INCLUDES	= include
CFLAGS		= -Wall -O $(shell mysql_config --cflags --libs)
ELFS		= $(shell find . -exec file {} \;|grep ELF|cut -d: -f1)

%:%.cpp
	$(CXX) $(CFLAGS) $(SYMBOLS:%=-D%) $(INCLUDES:%=-I%) $(LDPATH:%=-L%) $(LIBS:%=-l%) $< -o $@

%:%.c
	$(CC) $(CFLAGS) $(SYMBOLS:%=-D%) $(INCLUDES:%=-I%) $(LDPATH:%=-L%) $(LIBS:%=-l%) $< -o $@

clean:
	rm -f $(ELFS)

