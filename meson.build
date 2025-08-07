project('carsgame', 'cpp',
         default_options : 'cpp_std=c++20')

deps = [
    dependency('sdl3'),
    dependency('sdl3-image'),
]

src = [
  'src/Car.cpp',
  'src/Game.cpp',
  'src/main.cpp',
  'src/Math.cpp'
]

executable('carsgame', src, include_directories : 'src', dependencies : deps)
