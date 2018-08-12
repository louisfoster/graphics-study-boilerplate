# graphics-study-boilerplate

boilerplate for testing new ideas, doing tutorials etc. with opengl and sdl2

## Notes

- Top level resources directory should be used for shaders, images, etc.
- Use `cmd + shift + B` from root dir to compile to the build dir
- Run app from root dir with `./Build/app`

## Req

- vscode, w/ ext:
  - C/C++ intellisense
  - Clang-Format
- [glslangValidator](https://github.com/KhronosGroup/glslang) (in `/usr/local/bin/glslangValidator`)
- [clang](http://clang.llvm.org/)
- [clang format](http://clang.llvm.org/docs/ClangFormat.html)
- [GLEW](http://glew.sourceforge.net/)
- [SOIL](https://www.lonesock.net/soil.html)
- [SDL2](https://libsdl.org/)
- OpenGL Framework (if using mac)

## TODO

- Ensure packages are installed:
  - GLEW
  - SOIL
  - SDL2
  - clang
- Copy resources dir to where it's supposed to be

## Research

- [GENie](https://github.com/bkaradzic/genie)
- [VSCode Tools](https://github.com/Microsoft/vscode-cpptools/blob/master/Documentation/Getting%20started%20with%20IntelliSense%20configuration.md)
- [Compiler command tools](https://clang.llvm.org/docs/JSONCompilationDatabase.html)
