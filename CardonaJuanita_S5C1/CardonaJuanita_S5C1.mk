#Mi primer MakeFile

resultados.pdf : resultados.tex plot.pdf plot1.pdf
	pdflatex resultados.tex
plot.pdf : plotdatos.py
	python plotdatos.py
plot1.pdf : plotdatos1.py
	python plotdatos1.py
plotdatos.py : makedatos.py
	python makedatos.py > datos.dat
plotdatos1.py : makedatos1.py
	python makedatos1.py > datos1.dat



