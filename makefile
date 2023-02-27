main: main.o plane.o  
	g++ -o Air main.o plane.o 
clean:
	$(RM) Air