OBJ := go
SRC := testGit

%.o:%.cpp
	g++ -o $@ -c $<

$(OBJ):$(SRC).o
	g++ -o $@ $^

clean:
	rm *.o $(OBJ)

