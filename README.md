# so_long

> A simple 2D game project from 42 school using the MiniLibX graphical library.

## ✅ Description

`so_long` is a small 2D graphical game where the player must collect all items on a map and reach the exit. The project focuses on basic window rendering, image handling, event management, and pathfinding validation.

<br>

## 🎮 Game Objective

- Move the player across a map.
- Collect all collectibles (`C`) on the map.
- Reach the exit (`E`) after collecting all items.
- Avoid invalid moves (like walking into walls `1`).
- Count and display the number of moves.

<br>

## ⚙️ Build

This will generate the executable `so_long`:

```bash
make
```

To execute this program you should use `./so_long` with the map you want to play, as in the example below:

```bash
./so_long maps/map1.ber
```

NOTE: You can create your own map and test it in the executable or you can use the premade maps in the folder `maps`.

<br>

## 📚 Learn more: DeepWiki  
For a deeper explanation of map validation, pathfinding strategy, and image rendering in the so_long project, check out the official 42 article:

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/LuisPM24/so_long)
