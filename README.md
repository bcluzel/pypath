# pypath : A* pathfinding algorithm wrote in C++ for python

The goal of this project is to provide a fast and efficient python library that can find a path given a list of obstacle.

This module was originally developed for EIRBOT the robotic club of the engineer school Enseirb-Matmeca(French school).


## REQUIREMENTS 

You will need g++ in order to install pypath-fpa!

## Avaliables constructors 

 - Coordinates(x,y)
 - Size(width,height)
 - Rectangle(Coordinates,Size)
 - Castar()
 - Field()
 - Field(int robot_diameter_mm)
 - Field(int width_mm, int height_mm, int robot_diameter_mm)

## Documentation

Click [HERE](https://htmlpreview.github.io/?https://github.com/bcluzel/pypath/doc/index.html) !
## How to use

Here is a simple example :
```python
    field = Field(200)
    castar = Castar()
    field.add_obstacle(Rectangle(Coordinates(60,20), Size(2,40)))
    field.add_obstacle(Rectangle(Coordinates(150,40), Size(10,40)))
    field.add_obstacle(Rectangle(Coordinates(80,80), Size(200,2)))
    err, path = castar.find_path_simplified(Coordinates(10,10), Coordinates(10,100), field)
    if err == 0:
        foo(path)
    field.delete_obstacle(Coordinates(10,40))
```
## Author

CLUZEL Baptiste


