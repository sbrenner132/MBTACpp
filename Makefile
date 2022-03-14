.PHONEY: compile

compile:
	g++ -o ./bin/$(name) ./src/$(name).cpp