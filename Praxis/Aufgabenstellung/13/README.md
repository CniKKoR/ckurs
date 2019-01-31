Aufgabe 3.2.6:

Gegeben seien die folgenden Typ- und Variablenvereinbarungen für binäre Bäume: siehe 3_2_6.h

(a) Schreiben Sie in C eine boolsche Funktion int blatt(node t), die für einen beliebigen Baumknoten des angegeben Typs ermittelt, ob es ein Blatt ist oder nicht. Liefern Sie als Funktionswert eine 1, wenn es sich um ein Blatt handelt, sonst den Wert 0.

(b) Gehen Sie davon aus, dass eine boolsche Funktion int blatt(node t) gemäß Aufgabe (a) existiert. Schreiben Sie in C eine rekusive Funktion int anzahl(node t), die von einem gegebenen Baum des angegeben Typs unter Verwendung der Funktion blatt die Anzahl derjenigen Knoten als Ergebnis liefert, welche keine Blätter als (unmittelbaren) Nachfolger haben und selbst keine Blätter sind.

Aufgabe 3.2.7:

Geben sei die folgende Typendefinition zum Aufbau von Binärbäumen: siehe 3_2_7.h

Schreiben Sie in C eine rekursive Funktion, die einen Zeiger auf einen Baum dieses Typs als Argument nimmt und die dann für jeden Knoten des Baumes die folgenden Operationen ausführt:
* der Schlüsselwert des aktuellen Knotens wird durch die Summe der Schlüsselwerte seiner beiden unmittelbaren Nachfolgeknoten zuzüglich des eigenen Schlüsselwertes ersetzt
* ist der neu berechnete Schlüsselwert geradezahlig, so sind die beiden Nachfolgebäume zu vertauschen.

Hinweis: Ist ein Nachfolgeknoten nicht vorhanden, so ist für diesen der Schlüsselwert "0" anzunehmen.

Aufgabe 3.2.9:

Die folgende Typdeklaration für Elemente eines Binärbaumes sei gegeben: siehe 3_2_9.h

(a) Geben Sie in C eine rekusive Funktion void teilsummen(B_Ptr t) an, die bei jedem Knoten eines beliebigen Binärbaumes Tree des oben aufgeführten Typs in weight die Summe aller Schlüsselwerte des Unterbaums einträgt, der diesen Knoten als Wurzelknoten hat.

(b) Schreiben Sie in C eine rekusive Funktion void gewicht(B_Ptr t), die bei jedem Knoten eines beliebigen Binärbaumes Tree des oben aufgeführten Typs in weight einträgt:
* 0, falls die Summe der Schlüsselwerte beider Unterbäume gleich aufsteigend
* 1, falls die Summe der Schlüsselwerte im rechten Baum größer sind als die im linken
* -1, falls die Summe der Schlüsselwerte im linken Baum größer sind als die im rechten

Aufgabe 3.2.11:

Gegeben sei die folgende Typdefinition für Elemente einer Binärbaums: siehe 3_2_11.h

(a) Schreiben Sie in C eine Funktion einfuegen(...), die einen neuen Knoten mit dem Schlüsselwert z in einen Suchbaum einfügt, so dass die Suchbaumeigenschaft erhalten bleibt.

(b) Schreiben Sie in C eine Funktion summen(...), welche sowohl die Summen der geradezahligen als auch der ungeradzahligen Schlüsselwerte eines Baumes des angegebenen Typs ermittelt.

Aufgabe 3.2.24:

(a) Geben Sie in C eine Funktion int prim(int x) an, die als Funktionswert 1 liefert, wenn x eine Primzahl ist, ansonsten den Wert 0.

(b) Gegeben seien die folgenden Typdefinitionen für Elemente einer verketteten Liste: siehe 3_2_24.h
Schreiben Sie unter der Annahme das eine Funktion int prim(int x) gegeben sei, in C eine rekursive Funktion void prim_ex(l_Ptr l), welche aus einer Liste obrigen Typs alle die Listenelemente entfernt, deren Schlüssel Primzahlen sind.

Aufgabe 3.2.25:

Gegeben seien die Typendefinition sowie Variablendeklarationen: siehe 3_2_25.h

Weiterhin existiere eine Funktion LPtr create_element(int n), die ein Listenelement mit dem Schlüsselwert n für ein gegebenes n erzeugt, dessen next-Zeiger auf NULL zeigt.

(a) Schreiben Sie in C eine Funktion void append(LPtr l, int n), die an eine beliebige Liste des o.g. Typs ein neues Listenelement mit dem Schlüsselwert n hinten anfügt, aber nur dann, wenn der einzufügende Schlüssel in den bisherigen Listenelementen noch nicht enthalten ist.

(b) Schreiben Sie in C eine rekusive Funktion void listinsert(LPtr l, LPtr ele), die ein Listenelement ele in eine aufsteigend sortierte Liste des o.g. Typs einfügt, dass die Liste weiterhin sortiert bleibt. Sie können davon ausgehen, dass der Schlüssel von ele von den bereits vorhandenen Schlüsseln der Liste verschieden ist.
