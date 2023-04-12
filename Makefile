CC      = g++

CFLAGS  = -std=c++11 -Wall -Werror -Wextra -pedantic -O3

LDFLAGS = 

TARGET  = yryr

SRCDIR  = ./src

SRCS    = $(wildcard $(SRCDIR)/*.cpp)

OBJDIR  = ./obj

OBJS    = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

INCDIR  = -I./inc $(shell pkg-config --cflags opencv4)

LIBDIR  =

LIBS    = -lm $(shell pkg-config --libs --static opencv4)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
