parser_debug: sanitizer=-fsanitize=address
parser_debug: fpointer=-fno-omit-frame-pointer
parser_debug: parser

parser: src/xml_parser.cpp
	g++ -std=c++17 -c -O3 -Wall -Wextra ${sanitizer} ${fpointer} -I include src/xml_parser.cpp -o xml_parser.o

main: parser
	g++ -std=c++17 -O3 -Wall -Wextra -I include src/main.cpp xml_parser.o -o main

all: main

clean:
	rm -rf *.o; rm -rf main