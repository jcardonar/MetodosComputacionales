#Mi primer MakeFile

resultados.pdf : resultados.tex plotdatos.py plotdatos1.py
	pdflatex resultados.tex
plotdatos.py : makedatos.py
	python makedatos.py > datos.dat
plotdatos1.py : makedatos1.py
	python makedatos1.py > datos1.dat



