1) Erweitere das ROT13-Programm von letzter Stunde so, dass es alle Sonderzeichen
   akzeptiert und nicht verschlüsselt und kleine Buchstaben auf kleine verschlüsselte
   Buchstaben übersetzt.

2) Schreibe das Programm so um, dass es anstatt auf Nutzereingabe mit scanf zu warten,
   die Eingabe von stdin nimmt, verschlüsselt und auf stdout schreibt.

   Hilfe: Dateien kann man folgendermaßen auf stdin übertragen:
          cat lipsum.txt | ./rot13

3) Füge die möglichkeit hinzu Dateien als Kommandozeilenargument zu übergeben.
   Hierbei gibt es folgende Möglichkeiten:
    i)  Ein Argument zum Lesen von dieser Datei und Ausgabe via stdout.
    ii) Zwei, oder mehr Argumente wobei von der ersten gelesen und zur
        zweiten geschrieben werden soll.
   
   Die Fähigkeit von stdin zu lesen soll erhalten bleiben.

