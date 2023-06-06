motdedyck: motdedyck.c
	gcc -o motdedyck -std=c11 motdedyck.c

test: motdedyck
	bats check.bats

clean:
	rm -r motdedyck
	rm -r *.html

.PHONY: html

html: 
	pandoc --metadata pagetitle="TP1: Chemins de Dyck" README.md -o README.html -sc pandoc.css
	pandoc --metadata pagetitle="TP1: Chemins de Dyck" sujet.md -o sujet.html -sc pandoc.css
	


