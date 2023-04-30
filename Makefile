CXXFLAGS := -std=c++14 -Wall -ggdb -O0

TARGET := DetectU

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:%.cpp=%.o)

.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY : run
run : $(TARGET)
	./$(TARGET)

.PHONY : clean
clean : 
	rm -rf $(TARGET) $(OBJS)

