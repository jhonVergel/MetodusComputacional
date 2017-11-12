imagenes: Plots.py datos.dat datos1.dat
	python Plots.py 
datos.dat: Ondas
	rm -rf perturbada/
	rm -rf fijas/
	./Ondas.x > datos.dat
Ondas: Ondas.c
	gcc Ondas.c -lm -o Ondas.x
clean:
	rm -rf graficas/
	
	
