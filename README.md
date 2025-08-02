## dwm

My personal fork of [dmw](https://dwm.suckless.org/) (dynamic window manager).

<img width="2880" height="1800" alt="Arch linux with dwm" src="https://github.com/user-attachments/assets/31eb7d8d-a922-458c-9398-93d1bc1cb89d" />

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
