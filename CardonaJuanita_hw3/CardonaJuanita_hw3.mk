CardonaJuanita_Resultados_hw3.pdf: CardonaJuanita_Resultados_hw3.tex *.png
	pdflatex CardonaJuanita_Resultados_hw3.tex
CardonaJuanita_Resultados_hw3.tex: *.png
	pdflatex CardonaJuanita_Resultados_hw3.tex
*.png : CardonaJuanita_Plots_hw3.py
	python3 CardonaJuanita_Plots_hw3.py
CardonaJuanita_Plots_hw3.py : datosODE.txt datosPDE.txt
	python3 CardonaJuanita_Plots_hw3.py
datosODE.txt : ODE
	./ODE > datosODE.txt
ODE: CardonaJuanita_ODE.cpp
	g++ -o ODE CardonaJuanita_ODE.cpp
datosPDE.txt : PDE
	./PDE > datosPDE.txt
PDE : CardonaJuanita_PDE.cpp
	g++ -o PDE CardonaJuanita_PDE.cpp
