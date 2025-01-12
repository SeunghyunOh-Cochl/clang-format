#!/bin/bash
# search recursivly for files with a specific extension (.cc, .h, .cpp, .hpp)
# and run clang-format on them
find . -type f -name "*.cc" -o -name "*.h" -o -name "*.c" -o -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i --verbose
