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
CCFLAGS := -Wall -gdwarf-3 -O0 $(INCL)


#------------------------------------------------------------------
#	Generació d'arxius.
#------------------------------------------------------------------
build/fpbook.exe : sources/back_functions.c sources/interface_functions.c sources/main.c \
			 include/back_functions.h include/interface_functions.h include/estructures.h
	gcc $(CCFLAGS) sources/back_functions.c sources/interface_functions.c sources/main.c \
		-o build/fpbook.exe


#------------------------------------------------------------------
#	run command
#------------------------------------------------------------------
run : build/fpbook.exe
	build/fpbook.exe


#------------------------------------------------------------------
#	debug command
#------------------------------------------------------------------



#------------------------------------------------------------------
#	clean command
#------------------------------------------------------------------
clean:
	@echo Eliminant arxius build...
	@sleep 1
	@rm -fv build/*
	@echo Arxius build eliminats.