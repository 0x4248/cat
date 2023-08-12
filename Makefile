SRC = src
MAIN = main.cpp
OUTPUT = build

all: build

build:
	[ -d $(OUTPUT) ] || mkdir $(OUTPUT)
	g++ -o $(OUTPUT)/cat $(SRC)/$(MAIN)

clean:
	rm -rf $(OUTPUT)

run:
	./$(OUTPUT)/cat