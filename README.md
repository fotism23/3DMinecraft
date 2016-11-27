# 3DMinecraft
A 3D minecraft-type game using OpenGl library implemented in C++.

This game was developed as the first assignment for the undergraduate couse Computer Graphics and Interactive Systems of the Department of Computer Science and Engineering at the University of Ioannina.

![Alt text](https://github.com/fotism23/3DMinecraft/blob/master/preview.PNG "3DMinecraft")

# Student information
Fotios Mitropoulos 2486

# Programming Structure.
- Cube struct holding cube information.
- Camera class with public methods for each function.
- 3d Array holding cube struct objects.

# Functionalities.
- Rotating first person camera mode.
- Orbiting 3d person camera mode.
- Zoom in zoom with mouse wheel.
- Multiple lightning modes.

#Rules.
Rules can be found [here](https://github.com/fotism23/3DMinecraft/blob/master/assignment.pdf).

# Installation.
This game was developed in Microsoft VisualStudio Community 2015 v.14.0.25431.01 and is also full compatible with Unix-based or Linux-based systems.

In order to run and play the game, OpenGl libraries are necessary.
In Ubuntu 16.04LTS you will need to follow the next steps.

1. sudo apt-get install build-essential
2. sudo apt-get install freeglut3 freeglut3-dev
3. Download the library from http://www.rpmseek.com/rpm-pl/libglui2c2.html?hl=com&cs=libgcc1:RE:0:0:0:0:2420 according to your system. Run sudo apt-get -f install. Then run sudo dpkg -i <package_name>.

# How to compile & run.
You have to compile all source files and an executable file "Assignment1.out" will be created.
Make sure that the working directory is the project's directory and run the following commands:
1. make
2. ./Assignment1.out

# How to play.

Keyboard functions.
- Esc 		          : exit program
- a                 : move forwards
- s                 : move backwards
- a                 : rotate camera counter-clockwise
- d                 : rotate camera clockwise
- q                 : destroy the cube in front
- e                 : destroy all cubes in Y-axis in front
- r                 : drop cubes
- spacebar          : increase cube reserve by 1
- switch lightning  : cycle lightning mode (none - spotlight - flashlight)
- switch camera     : cycle camera mode (fps - 3d person shooter)

Mouse functions.
(In order to change the default mouse functions you should modify the main.h file on Mouse Parameters section and set the values of your choise)
- Horizontal Move Right     : rotate camera clockwise
- Horizontal Move Left      : rotate camera counter-clockwise
- Mouse wheel up            : zoom in
- Mouse wheel down          : zoom out
- Left Click                : add cube in front
- Right Click               : cick cube

# Contact
Feel free to contact me for any reason.  
- Personal email  : fotismitropoulos@gmail.com  
- Academic email  : cse32486@cs.uoi.gr  
