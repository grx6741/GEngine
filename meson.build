project('GEngine', 'cpp')

inc_dir = include_directories('include')

src_files = [
  'main.cpp',
  'src/base.cpp',
  'src/ui.cpp',
  'src/imgui.cpp',
  'src/imgui_demo.cpp',
  'src/imgui_draw.cpp',
  'src/imgui_impl_glfw.cpp',
  'src/imgui_impl_opengl3.cpp',
  'src/imgui_tables.cpp',
  'src/imgui_widgets.cpp'
]

dep = [
  dependency('glfw3'),
  dependency('GLEW'),
  dependency('xrandr'),
  dependency('xi'),
  dependency('X11'),
  dependency('GL')
]

executable('GEngine', src_files, include_directories : inc_dir, dependencies : dep, cpp_args : '-g')
