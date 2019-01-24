Das folgende Programm wird mit folgendem Ausdruck kompiliert: gcc main.c -lm

Zum Ausführen des Programms muss ein Subordner "img" am selben Ort angelegt
werden. Dort werden die generierten PNG-Dateien gespeichert.

Ändere die Funktion mandelbrot_et in mand.h so, dass es in den For-Schleifen
mithilfe von OpenMP Multithreading ausnutzt, um so die Laufzeit zum rendern
der Frames zu verbessern.
Vergleiche die Laufzeiten.
