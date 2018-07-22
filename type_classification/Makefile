TARGET = test
CC = g++ -std=c++11

CPP_FILES = $(shell ls *.cc)
BASE = $(basename $(CPP_FILES))
OBJS = $(addsuffix .o, $(BASE))

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
 
$(OBJS): $(CPP_FILES)
	$(CC) $(CPP_FILES) -c

clean:
	rm -rf *.o