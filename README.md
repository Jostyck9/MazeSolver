# MazeSolver
This maze solver will save a maze using a A* algorithm

## Exec
./MazeSolver filePath [color]
- filepath : file path of the maze to solve
- color : optional parameter to define if we print in color or not, must be true or false, DEFAULT = true

## Color
If you print in color, you will see :
- The wall in **WHITE**
- The path in **BLUE** if founded
- The node visited in **RED** (closed nodes)
- The potential nodes to visit during the algorithm in **GREEN** (open nodes)

To have the color on windows, you need to execute this command in the terminal with administrator privileges:
- `reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f`

## Sample Maze
Some sample maze with their solutions are provided in the Sample folder.