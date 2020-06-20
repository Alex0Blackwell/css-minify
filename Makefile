output: minify.o
	g++ minify.o -o output -Wall

minifiy.o:
	g++ -c minify.cpp

clean:
	rm *.o output ./files/*.min.css
