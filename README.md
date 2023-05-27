# my_paint

## CONTEXT

So far, you have created command line (bash) projects. But, you don’t use command line daily, but a _Graphic User Interface_.

Through this project, you will develop your own GUI by creating a _paint_ like software.

The aim is to work on GUI. Menu, scrolling menu, button (radio or check). Use and change tool, and so on.

## REQUIREMENTS

### MANDATORY

#### MUST

- Window that you can minimize, enlarge and close
- Provide at least the _pencil_ and _eraser_ tools
- Buttons must have different states (at least 3 HOVER, PRESSED and CLICKED for example)
- A menu bar, with at least the _file_ , _edit_ and _help_ features. Each item must be a drop-down menu
  - In the _file_ item, the options _new file_ , _open file_ , _save file_.
  - In the _edition_ item, the selection of the _pencil_ and _eraser_ tools
  - In the _help_ item, the options _about_ (which must display your login),and _help_ (which explain show to use the software)
- A new _side-menu_ (tool bar) popping up upon tool selection which allows you modify it
  - For _pencil_ change the line thickness
  - For _eraser_ change the shape (circle or square) and its size
- Be able to make a drawing with the tools using the mouse
- Save the image (.jpg format by default)

#### SHOULD

- User must can enter file name in terminal or in a new window popping up when choosing an option in _file_ menu drop down
- Layer management
- A _side menu_ with the color palette for the _pencil_ tool
- Save the image in other formats (.bmp and .png)
- Add basic shapes (circle, rectangle)
- Possibility to zoom on the image
- Add the _selection_ tool (with a rectangle shape)
- Add the _cut_ / _copy_ / _paste_ options in the _edition_ menu, usable ona part of the image previously selected with the _selection_ tool, AND the _paste_ to another place of the image, or on another layer.

#### COULD

- Layer mask management
- Image import
- Management of _brush_ for the _pencil_ and _eraser_ tools
- Add complex shapes (convex)
- Management of transformations (translation, rotation) of entities
- Add _undo_ and _redo_ operation in edition menu

### BONUS

Take inspiration from software like _GIMP_ , or _Photoshop_.

## AUTHORIZED FUNCTIONS

All the functions from the CSFML and the math library are allowed.
From the libc, here is the full list of authorized functions:

```text
**malloc
free
memset
(s)rand
(f)stat

getline
(f)open
(f)read
(f)close
(f)write

opendir
readdir
closedir
```

```text
Any unspecified functions are de facto banned.
```

## FINAL MARK

### Mark: 24 / 31 (77.4%)

- Preliminary (2 / 2)
- Window management (2 / 2)
- Mouse event (1 / 1)
- Basic button (1 / 2)
- Menu bar (2 / 2)
- Call back on file option (2 / 2)
- Call back on edition option (2 / 2)
- Call back on help option (3 / 3)
- Side menu (2 / 2)
- Drawing feature (1 / 1)
- Save (2 / 2)
- Layer management (0 / 2)
- Other tools and shapes (3 / 6)
- Other options in menu bar (1 / 2)
