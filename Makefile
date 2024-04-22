#------------------------------------------------------------------
#	FPbook - Pràctica assignatura FP II
#	Integrants:
#		-	Eric García Castro.
#		-	Iván Molinero Moreno.
#		-	Óscar López Canas.
#	Makefile del projecte
#------------------------------------------------------------------

#------------------------------------------------------------------
#	Flags
#------------------------------------------------------------------
INCL := -I./include
CCFLAGS := -Wall -g -O0 $(INCL) -std=c11


#------------------------------------------------------------------
#	Generació d'arxius.
#------------------------------------------------------------------
build/fpbook.exe : sources/back_functions.c sources/interface_functions.c sources/main.c \
			 include/back_functions.h include/interface_functions.h include/estructures.h
	gcc $(CCFLAGS) sources/back_functions.c sources/interface_functions.c sources/main.c \
		-o build/fpbook.exe

build/tests.exe : sources/tests.c sources/interface_functions.c sources/back_functions.c \
			 include/back_functions.h include/interface_functions.h include/estructures.h
	gcc $(CCFLAGS) sources/tests.c sources/interface_functions.c sources/back_functions.c \
		-o build/tests.exe


#------------------------------------------------------------------
#	run commands
#------------------------------------------------------------------
run : build/fpbook.exe
	build/fpbook.exe

run_tests : build/tests.exe
	build/tests.exe


#------------------------------------------------------------------
#	debug command
#------------------------------------------------------------------
debug : build/fpbook.exe
	gdb build/fpbook.exe

debug_tests : build/tests.exe
	gdb build/tests.exe


#------------------------------------------------------------------
#	clean command
#------------------------------------------------------------------
clean:
	@echo Eliminant arxius build...
	@sleep 1
	@rm -fv build/*
	@echo Arxius build eliminats.