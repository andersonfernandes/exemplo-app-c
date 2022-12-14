DEPS=dados.c menus.c tratadores.c
ifeq ($(OS),Windows_NT)
	OUTPUT_FILENAME=main.exe
else
	OUTPUT_FILENAME=main
endif

compile:
	gcc $(DEPS) main.c -o $(OUTPUT_FILENAME)
