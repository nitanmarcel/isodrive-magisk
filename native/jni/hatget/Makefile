CC = g++
CFLAGS = -I./src/include
SRCS = src/util.cpp src/configfsisomanager.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = hatget
INSTALL_DIR = /usr/local/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	install $(TARGET) $(INSTALL_DIR)

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all install clean

