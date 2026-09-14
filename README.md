*This project has been created as part of the 42 curriculum by makassa, dkpg-md-.*

# cub3D

## Description

cub3D is a small ray-casting project inspired by Wolfenstein 3D.

The program reads a `.cub` scene file, checks that the file is correctly configured,
and uses the map, textures, floor color, ceiling color, and player start position to
create a first-person view inside a maze.

This project focuses on file parsing, map validation, memory management, MiniLibX,
keyboard events, and basic graphics programming in C.

## Instructions

Compile the project from the `cub3D` directory:

```sh
make
```

Run the program with a scene file:

```sh
./cub3D maps/tester.cub
```

Clean object files:

```sh
make clean
```

Remove object files and the executable:

```sh
make fclean
```

Rebuild the project:

```sh
make re
```

The scene file must use the `.cub` extension. If the file is misconfigured, the
program exits cleanly and prints `Error` followed by an explanatory message.

## Scene File

A valid scene file contains:

- north, south, west, and east texture paths
- floor and ceiling colors in RGB format
- a map made of walls, empty spaces, and exactly one player start position

Example identifiers:

```text
NO ./textures/greystone_north.xpm
SO ./textures/purplestone_south.xpm
WE ./textures/redbrick_west.xpm
EA ./textures/wood_east.xpm
F 220,100,0
C 225,30,0
```

Map characters:

- `1` is a wall
- `0` is an empty walkable space
- `N`, `S`, `E`, or `W` is the player start position and direction
- spaces may appear in the map and must be handled safely

The map must be closed by walls.

## Resources

- 42 cub3D subject
- MiniLibX documentation and examples
- Wolfenstein 3D and ray-casting explanations
- OpenAI (GPT5)

AI was used as a study and review guide; visualizing parser flow, aiding in source file structuring and drafting README doc. 
