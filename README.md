## dwm

My personal fork of `dwm` (dynamic window manager). Clean, patched, and tuned to my setup. No guarantees :^)

### patches included
- `colorbar`
- `hide_vacant_tags`
- `vanitygaps`
- `xrdb`

### how to use
Clone, build, install:

```sh
git clone https://github.com/eoSalinas/dwm
cd dwm
sudo make clean install
```

- Basic ~/.xinitrc requirement: exec dwm
* Configure settings (fonts, bindings, gap pixels, etc) in **config.def.h** before compiling.
  - Defaults: Mod is bound to the windows key
  - ```mod + enter``` to open terminal
  - ```mod + q``` to quit window
  - ```mod + shift + backspace``` to fully exit

### notes
If you aren't using ```~/.Xresources``` with or without [pywal16](https://github.com/eylles/pywal16), default color palette is a variant of Kanagawa.

I use [dwmblocks](https://github.com/eoSalinas/dwmblocks) for my statusbar.
