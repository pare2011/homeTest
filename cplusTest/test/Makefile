OBJ := testGit 

%.o:%.cpp
	g++ -o $@ -c $<

$(OBJ):*.o
	g++ -o $@ $^

clean:
	rm *.o $(OBJ)

