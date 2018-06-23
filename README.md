# hex2rgb

Hex to RGB

## About

hex2rgb is a program made in C that converts 3 and 6 character long hexadecimal colour codes to values that would be suitable for RGB.
<br>
To give an idea of how this would work, `ff00ff` would become `rgb(255,0,255)`. As this also supports 3 character hex colour codes, `f0f` would expand and produce the same result.

## Compiling

`gcc -o hex2rgb hex2rgb.c`
<br>
Alternatively, both x64 and x86 Linux builds are available in the `releases` section.

## Usage

`./hex2rgb [hex]`
