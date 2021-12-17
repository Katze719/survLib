# Surveying_Math
- Surveying_Library
- Static_Library
*******************************************************
# functions:

- isDouble(String) -> checks if a string is convertible to a double
- dist(Point, Point) -> calculates the distance between two points
- is_near(Point, Point) -> used to compare points, the precision can be changed with (#define IS_NEAR VALUE)
- sort(T) -> sorts your std::vector or array or whatever you give it as long as it has type .size() and returns a number
- reverse(T) -> inverts your list
- print(T) -> uses std::cout with a line break at the end
- printl(T) -> uses print(T) (see above) to output arrays or std::vectors
- intercept(Line, Line) -> calculates the intersection of two lines
- area(std::vector<Point>) -> calculates the area from points that have to be sorted clockwise or counterclockwise
- polar_attachment(Point, Angle, Track) -> calculates a new point with angle and track
*******************************************************

# concepts:

- iterable -> type must have .size()
- Streamable -> type must be convertible to a std::ostream with the operator <<
*******************************************************

# classes:

- Point -> has x,y,z,index, constructor can be used with strings
	- operator+ -> returned a point calculated from two points
	- operator+= -> adds the values of another point to a point
	- operator- -> returned a point calculated from two points
	- operator-= -> decreases a point by the values of another point
	- operator< -> index < index
	- operator> -> index > index
	- operator<< -> outputs x,y,z,index in a format

- Line -> consists of 2 points and a distance

- Direction_angle -> is the direction angle from one point to another point
	- .get_value() -> returns the angle
	- operator<< -> returns the angle in GON

- Triangle -> general triangle
	- .set_angles() -> calculates the angles
	- .set_sites() -> calculates the sides
	- .set_area() -> calculates the area
	- .set_circumference() -> calculates the circumference
	- .calc() -> executes the methods .set_angle(), .set_sites(), .set_area(), .set_circumference()

- Square -> inherits from Triangle
	-
