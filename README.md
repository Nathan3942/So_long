# So_long

A small 2D game built in C with the MiniLibX, as part of 42's common core curriculum.

## About

So_long is an introduction to 2D graphics programming and game logic. Given a map file describing a level, the game loads and displays it using sprites, lets the player move around, collects collectibles, and reach an exit — all while validating that the map is well-formed before the game even starts.

The project focuses less on gameplay depth and more on rigor: proper map parsing, clean sprite rendering, memory management, and a stable game loop.

## Features

- Parsing and validation of a custom `.ber` map file:
  - Rectangular map, fully enclosed by walls
  - Exactly one player starting position
  - Exactly one exit
  - At least one collectible
  - The map must be solvable (a path exists from the player to the exit, passing through at least one collectible)
- Rendering of the map using distinct sprites for walls, floor, player, collectibles, and exit
- Player movement in four directions, with collision detection against walls
- Move counter, printed to the terminal each time the player moves
- Collectible pickup logic — the exit only becomes usable once all collectibles are collected
- Clean window closing (`ESC` key, red cross) with proper memory deallocation, checked against leaks

### Bonus (if implemented)
- Movement/idle animations for the player
- Enemies with basic movement patterns
- Multiple levels

*(Check/remove bonus features depending on what you actually implemented.)*

## Build

```bash
make
```

This generates the `so_long` executable at the root of the project.

Other available targets:
```bash
make clean    # removes object files
make fclean   # removes object files and the executable
make re       # rebuilds the project from scratch
```

## Usage

```bash
./so_long maps/map.ber
```

Example:
```bash
./so_long maps/valid_map.ber
```

### Controls

| Key | Action |
|---|---|
| `W` `A` `S` `D` (or arrow keys) | Move the player |
| `ESC` | Quit the game |

*(Adjust this table to match your actual controls.)*

## Map file format (.ber)

```
1111111111
10C0000001
1000P00001
1000000E01
1111111111
```

- `1`: wall
- `0`: floor
- `P`: player starting position
- `C`: collectible
- `E`: exit
- The map must form a closed rectangle, with no gaps in the outer walls

*(Adjust this example to match the exact format you implemented.)*

## Project structure

```
so_long/
├── src/
│   ├── main.c
│   ├── parsing/
│   ├── render/
│   ├── game/
│   └── events/
├── includes/
├── textures/
├── maps/
├── libft/          # personal library reused across projects
├── minilibx/
├── Makefile
└── README.md
```

*(Adjust this tree to match your actual project structure.)*

## What I learned

- Loading, parsing, and validating a custom file format representing a 2D grid
- Working with sprites and image buffers using MiniLibX
- Structuring a basic game loop and handling keyboard events
- Careful memory management in a graphical application (textures, structures, window/display cleanup)
- Path validation (checking that a level is actually solvable before letting the player start)

## Authors

- [Nathan Jeanbourquin](https://github.com/Nathan3942) — 42

## License

Project built as part of the 42 curriculum. Educational use.
