
imagenes: Plots.py datos.dat datos1.dat
	python Plots.py 
	pdflatex Resultados_hw4.tex
datos.dat: Ondas
	rm -rf perturbada/
	rm -rf fijas/
	./Ondas.x > datos.dat
Ondas: Ondas.c
	gcc Ondas.c -lm -o Ondas.x

	

	
	
