# Surveying_Math
- Surveying_Library
- Static_Library
*******************************************************
# Funktionen:

- isDouble(String) 			            -> überprüft ob ein string konvertiebar zu einen Double ist
- dist(Point, Point) 					-> berechnet die entfernung zwischen zwei punkten
- is_near(Point, Point) 				-> wird benutzt um punkte zu vergleichen, die genauigkeit dafür kann beliebig geändert werden mit (#define IS_NEAR WERT)
- sort(T) 								-> sortiert deinen std::vector oder array oder was auch immer du ihm gibst solange der Typ .size() besitzt und eine zahl returned
- reverse(T) 							-> invertiert deine liste
- print(T) 								-> verwendet std::cout mit einem zeilenumbruch am ende
- printl(T) 							-> verwendet print(T) (siehe oben) um arrays auszugeben oder std::vectoren
- intercept(Line, Line) 				-> berechnet den schnittpunkt von zwei Linien
- area(std::vector<Point>) 				-> berechnet die fläche aus Punkten die aber Im- oder Gegen den Uhrzeigersinn sortiert sein müssen
- polar_attachment(Point, Angle, Track)	-> errechnet einen neuen Punkt mit Winkel und strecke
*******************************************************

# concepts:

- iterable 								-> Typ muss .size() besitzen
- Streamable 							-> Typ muss in einen std::ostream konvertierbar sein mit dem operator <<
*******************************************************

# Klassen:

- Point 								-> besitzt x,y,z,index, konstruktor kann mit strings verwendet werden
	- operator+ 						-> returned einen Punkt errechnet aus zwei Punkten
	- operator+= 						-> fügt einem Punkt die werte eines anderen Punktes hinzu
	- operator- 						-> returned einen Punkt errechnet aus zwei Punkten
	- operator-= 						-> verringert einem Punkt die werte eines anderen Punktes hinzu
	- operator< 						-> index < index
	- operator> 						-> index > index
	- operator<< 						-> gibt x,y,z,index aus in einem format

- Line 									-> besteht aus 2 Punkten und einer Strecke

- Direction_angle 						-> ist der richtungwinkel von einem Punkt zu einem anderem
	- .get_value() 						-> returned den Winkel
	- operator<< 						-> gibt den Winkel in GON aus

- Triangle 								-> allgemeines Dreieck
	- .set_angles() 					-> rechnet die winkel
	- .set_sites() 						-> rechnet die seiten
	- .set_area() 						-> rechnet die Fläche
	- .set_circumference() 				-> rechnet den Umfang
	- .calc() 							-> führt die methoden .set_angle(), .set_sites(), .set_area(), .set_circumference() aus

- Square 								-> erbt von Triangle
	-
