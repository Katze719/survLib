# survLib

survLib is a library for surveyors and people working with DXF files.

## Installation

Use the GitHub clone feature [clone](https://github.com/Katze719/survLib.git) to download survLib.
simply include the header Surveying_Math.h and the corresponding lib from the x86 or x64 folder. 


## getting started

### let's quickly read in some DXF file
reading in DXF files is multithread supported, if you have 30 files it creats 30 threads

```c++
#include <Surveying_Math.h>
#include <vector>

using namespace surv;

std::vector<std::string> File_Names = {"Test0.dxf","Test1.DXF","Test2.Dxf",...};
DXF_STORAGE DXF_S(File_Names);
```
#### and print them out in the console
```c++
printl(DXF_S.at(0).get_Entities());
/* or use */
printl(DXF_S.at("Test0.dxf").get_Entities());
```
#### we can also convert them to points
```c++
Points PS; // std::vector<surv::Point>
for (auto& elem : DXF.at(0).get_Entities())
	PS.push_back(elem.to_Point());
```
#### or let's say we have some points and we want to calculate the area
first we have to store all points clockwise or counterclockwise in a std::vector.
```c++
Point P0(2,6,4);
/* or with strings */
Point P1("5","4","2");

Points myPoints = {P0,P1,...};

double area = c_area(myPoints);
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
