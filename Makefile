CXX=g++
SRCS := $(wildcard *.cc)
OBJS := $(SRCS:.cc=.o)
AR := ar rc
INCLUDES := .
TARGET := libbase.a
all:
	$(CXX) -c $(SRCS) -I$(INCLUDES) 
	$(AR)  $(TARGET) $(OBJS)
	

clean:
	rm -rf $(OBJS) $(TARGET)
	

