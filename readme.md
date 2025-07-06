# My Kyria Keymap

This is something like the 3rd iteration of this keymap
I made some adjustments to this one after using my Kyria daily for about 4 years.
I mostly use it for programming on Linux

Features:

- I use a rotary encoder for volume control
- I have luna the animated keyboard pet for 64 width screens
- I made a custom bitmap for my second OLED screen

For now I only use 3 layers:

1. Home layer
2. Symbols / Numbers layer
3. Function / LED layer

## Home layer

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

## My Hardware

### Rotary Encoder

The rotary encoder is on the top right corner, and is programmed to control the volume. I think I installed my encoder backwards, so you might need to adjust the rotation so it works for your Kyria

### OLEDs

I wanted to customize the OLED screens a bit, I found luna the animated dog that runs when you type and barks when you hold shift, but it was originally made for 32 width screens, so I had to find a way to adapt it for my 64 pixel landsape screen => https://gist.github.com/louckousse/74cd3f5cacf04fa585c127d89a149cfc

I also made a custom bitmap of the villian from Over the Garden wall for the second OLED

### Underglow

My Kyria is equipped with underglow and has the settings on the F-Key layer
