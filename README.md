Based on the 2D Game Engine with C++ and Lua Pikuma course.

- To install required dependencies on Fedora Linux:

```bash
sudo dnf install @development-tools SDL2-devel SDL2_image-devel SDL2_ttf-devel SDL2_mixer-devel lua-devel
```
- Lua and Sol2:
  - Lua version: 5.4.8 — header files included in libs/lua
  - Sol2 (sol.hpp): Latest version downloaded from https://github.com/ThePhD/sol2/releases
  
- Modifications:
  - Updated includes in sol.hpp to reference the local libs/lua header files.
  - Replaced line 6755 with the following fix:
    ```cpp
    new (static_cast<void*>(this)) optional(std::in_place, std::forward<Args>(args)...);
    return **this;
    ```

- Build and run instructions:
  - To build from a linux terminal, run the `make` command
  - To run from a linux terminal, run th `make run` command