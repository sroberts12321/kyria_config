# Steve's Kyria Keymap

This is something like the 3rd iteration of this keymap
Hardware features of the Kyria such as OLEDs, rotary encoders and underglow are toggled on.

The three different layers are the following:

1. Home layer (QWERTY, Colemak-DH or Dvorak)
2. Symbols/Numbers layer
3. Function / LED layer

## Home layer(s)

```
Home Layer: -

  ,-------------------------------------------.                              ,-------------------------------------------.
  |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  MUTE  |
  |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  | LShift |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | Enter  |
  |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
  `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
                         | ` ~  | LAlt |  ESC | BkSp | LCtrl|  | Sym  | Space| DEL  | \ |  | PRNT |
                         |      |      | /WIN |      |      |  |      |      |      |      | SCRN |
                         `----------------------------------'  `----------------------------------'

```

The ESC / WIN key will register as an ESC if you tap it, and a Windows/Meta key if you hold it down

---

```
Symbols Layer: -

  ,-------------------------------------------.                              ,-------------------------------------------.
  |    ~   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  MUTE  |
  |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  | LShift |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |   :  |   '  |   "    |
  |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  | LCtrl  |  [   |   ]  |  (   |   )  |   +  |      |      |  |      |      |   =  |   {  |   }  |   <  |   >  |  ` ~   |
  `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
                         |FKEYS | LAlt | PRNT |  -   |  _   |  | Pass |   ←  |  ↓   |   ↑  |   →  |
                         |      |      | SCRN |      |      |  |      |      |      |      |      |
                         `----------------------------------'  `----------------------------------'
```

---

```
F-Keys Layer: -

  ,-------------------------------------------.                              ,-------------------------------------------.
  |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  |  F10 |        |
  |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  |        |      |      |      |      |      |                              |UGSPD+|UG nxt|HUE + |SAT + | BRI +|  F11   |
  |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  |        |      |      |      |      |      |      |      |  |      |      |UGSPD-|UG prv|HUE - |SAT + | BRI -|  F12   |
  `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
                         |      |      |      |      |      |  | Light|  Und |      |      |      |
                         |      |      |      |      |      |  | TOGG |  Glo |      |      |      |
                         `----------------------------------'  `----------------------------------'
```

```c
enum layers {
    _HOME = 0,
    _SYMBOLS,
    _FUNCTION,
};
```

## Hardware Features

### Rotary Encoder

The rotary encoder is on the top right corner, and is programmed to control the volume

### OLEDs

I found luna the keyboard pet adapted for the landscape screens => https://gist.github.com/louckousse/74cd3f5cacf04fa585c127d89a149cfc
I also made a custom bitmap of the villian from Over the Garden wall for the second oled

### Underglow

Lots of options for underglow
