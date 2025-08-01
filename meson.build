project('carsgame', 'cpp',
         default_options : 'cpp_std=c++20')

deps = [
    dependency('sdl3'),
]

src = [
  'src/main.cpp',
]

executable('carsgame', src, include_directories : 'src', dependencies : deps)
