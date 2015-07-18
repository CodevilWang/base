CXX=g++
SRCS := $(wildcard *.cc)
OBJS := $(SRCS:.cc=.o)
AR := ar rc
INCLUDES := .
LIBS := -lpthread
TARGET := libbase.a
DEF_FLAGS := 
all:
	$(CXX) -c $(SRCS) -I$(INCLUDES) $(LIBS) $(DEF_FLAGS)
	$(AR)  $(TARGET) $(OBJS)
	

clean:
	rm -rf $(OBJS) $(TARGET)
	

