Show Me The Key
===============

A screenkey alternative that works under Wayland via libinput.
--------------------------------------------------------------

A SUSE Hack Week 20 Project: [Show Me The Key: A screenkey alternative that works under Wayland via libinput](https://hackweek.suse.com/20/projects/a-screenkey-alternative-that-works-under-wayland-via-reading-evdev-directly).

# Feature

[screenkey](https://gitlab.com/screenkey/screenkey) is a popular project for streamers or tutorial recorders because it can make your typing visual on screen, but it only works under X11, not Wayland because it uses X11 functions to get keyboard event.

This program, instead, reads key events via libinput directly, and then put it on screen, so it will not depend on X11 or special Wayland Compositors and will work across them.

# Project Structure

## CLI

This part exists because of Wayland's security policy, which means you cannot run a GUI program with `sudo` (see <https://wiki.archlinux.org/index.php/Running_GUI_applications_as_root#Wayland>). It's suggested to split your program into a GUI frontend and a CLI backend that do privileged operations, and this is the backend, a custom re-write of <https://gitlab.freedesktop.org/libinput/libinput/-/blob/master/tools/libinput-debug-events.c>, based on [libinput](https://www.freedesktop.org/wiki/Software/libinput/), [libudev](https://www.freedesktop.org/software/systemd/man/libudev.html) and [libevdev](https://www.freedesktop.org/wiki/Software/libevdev/).

It generates JSON in lines like `{"event_name": "KEYBOARD_KEY", "event_type": 300, "device_name": "USB Keyboard USB Keyboard", "time_stamp": 39869802, "key_name": "KEY_C", "key_code": 46, "state_name": "PRESSED", "state_code": 1}`.

## GTK

A GUI frontend based on GTK, will run CLI backend as root via `pkexec`.

# Name

As I want some clear name that hints its usage, but `screenkey` is already taken and I think `visualkey` sounds like `Visual Studio` and it's horrible. My friend [@LGiki](https://github.com/LGiki) suggests `Show Me The Key` which sounds like "Show me the code" from Linus Torvalds. At first I think it's a little bit long, but now it is acceptable so it's called `showmethekey` or `Show Me The Key`.