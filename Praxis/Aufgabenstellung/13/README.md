Aufgabe 3.2.6:

Gegeben seien die folgenden Typ- und Variablenvereinbarungen für binäre Bäume: siehe 326.h

(a) Schreiben Sie in C eine boolsche Funktion int blatt(node t), die für einen beliebigen Baumknoten des angegeben Typs ermittelt, ob es ein Blatt ist oder nicht. Liefern Sie als Funktionswert eine 1, wenn es sich um ein Blatt handelt, sonst den Wert 0.

(b) Gehen Sie davon aus, dass eine boolsche Funktion int blatt(node t) gemäß Aufgabe (a) existiert. Schreiben Sie in C eine rekusive Funktion int anzahl(node t), die von einem gegebenen Baum des angegeben Typs unter Verwendung der Funktion blatt die Anzahl derjenigen Knoten als Ergebnis liefert, welche keine Blätter als (unmittelbaren) Nachfolger haben und selbst keine Blätter sind. Geben Sie anschließend ein Beispiel für einen Funktionsaufruf an.

Aufgabe 3.2.7:

Geben sei die folgende Typendefinition zum Aufbau von Binärbäumen: siehe 327.h

Schreiben Sie in C eine rekursive Funktion, die einen Zeiger auf einen Baum dieses Typs als Argument nimmt und die dann für jeden Knoten des Baumes die folgenden Operationen ausführt:
* der Schlüsselwert des aktuellen Knotens wird durch die Summe der Schlüsselwerte seiner beiden unmittelbaren Nachfolgeknoten zuzüglich des eigenen Schlüsselwertes ersetzt
* ist der neu berechnete Schlüsselwert geradezahlig, so sind die beiden Nachfolgebäume zu vertauschen.

Hinweis: Ist ein Nachfolgeknoten nicht vorhanden, so ist für diesen der Schlüsselwert "0" anzunehmen.

Aufgabe 3.2.8:

Gegeben sie die folgende Deklaration für Elemente eines Binärbaumes: siehe 328.h

(a) Schreiben Sie in C eine Funktion void insert (...), die folgendes leistet:
* Für einen als Parameter übergebenen Integerwert n ist ein neuer Knoten mit dem Schlüsselwort (key) n so in einen ebenfalls als Parameter übergebenen binären Suchbaum des oben definierten Typs einzufügen, dass die Suchbaumeigenschaft erhalten bleibt.

* Als Wert für pos ist -1 (bzw. 1) einzutragen, wenn der neue Knoten der linke (bzw. rechts) Nachfolger seines Vorgängerknotens ist. Der Wurzelknoten des Baumes soll für pos den Wert 0 erhalten.

Geben Sie einen beispielhaften Aufruf der Funktion void insert(...) an, deklarieren Sie die hierzu erforderlichen Bezeichner.

(b) Schreiben Sie in C eine Funktion int linke(...), die als Parameter mindestens einen beliebigen Baum des oben genannten Typs hat und für diesen ermittelt, wie viele Knoten direkte linke Nachfolger ihres unmittelbaren Vorgängers sind.
