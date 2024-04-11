# Cat
# Remake of cat with a few different features.
# Github: https://www.github.com/0x4248/cat
# Licence: GNU General public licence V3.0
# By: 0x4248

SRC = src
MAIN = main.cpp
OUTPUT = build

all: build

build:
	[ -d $(OUTPUT) ] || mkdir $(OUTPUT)
	g++ -o $(OUTPUT)/cat $(SRC)/$(MAIN)

cliean:
	rm -rf $(OUTPUT)

run:
	./$(OUTPUT)/cat
