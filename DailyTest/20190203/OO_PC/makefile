INC_DIR:= ./
SRC_DIR:= ./
SRCS:= $(wildcard $(SRC_DIR)*.cc)
CC:= g++
CXXFLAGS:= -g -Wall $(addprefix -I, $(INC_DIR))
LIBS:= -lpthread
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
BIN_EXE:= TestPC.exe


$(BIN_EXE): $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)


%.o:%.cc
	$(CC) -o $@ -c $< $(CXXFLAGS) $(LIBS)

clean:
	rm -r $(OBJS) $(BIN_EXE)
