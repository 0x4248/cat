OUTPUT = build

all: build

build:
	[ -d $(OUTPUT) ] || mkdir $(OUTPUT)
	g++ -o $(OUTPUT)/cat main.cpp

clean:
	rm -rf $(OUTPUT)

run:
	./$(OUTPUT)/cat