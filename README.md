# MazeSolver
This maze solver will save a maze using a A* algorithm

## Compilation
The project use cmake. To compile you need to be at the root of the project and execute the following commands :

### For Windows
```powershell
mkdir build; cd build; cmake ..
```
(You can also use cmake-gui)

A Microsoft Visual Studio Solution will be created, open it and compile it to after execute it.

Check the color section for the color parameters. 

### Linux
```shell
mkdir build && cd build && cmake .. && make
```

## Exec

- filepath : file path of the maze to solve
- color : optional parameter to define if we print in color or not, must be true or false, DEFAULT = true

### Windows
./MazeSolver.exe filePath [color]

### Linux
./MazeSolver filePath [color]

## Color
If you print in color, you will see :
- The wall in **WHITE**
- The path in **BLUE** if founded
- The node visited in **RED** (closed nodes)
- The potential nodes to visit during the algorithm in **GREEN** (open nodes)

To have the color on **Windows**, you need to execute this command in the terminal with administrator privileges:
```powershell
reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f
```

## Sample Maze
Some sample maze with their solutions are provided in the Sample folder.