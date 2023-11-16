# Cat
# Remake of cat with a few different features.
# Github: https://www.github.com/lewisevans2007/cat
# Licence: GNU General public licence V3.0
# By: Lewis Evans

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
