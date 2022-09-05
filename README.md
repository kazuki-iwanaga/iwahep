# uthic

## Required:
- `CMake>=3.11`
- `gcc>=5`
- `gsl>=?2.7`

## How to Use
```
git clone https://github.com/kazuki-iwanaga/uthic.git
cd iwahep
docker compose up -d
docker compose exec gcc bash
(docker)# mkdir build && cd build
(docker)# cmake ..
(docker)# make
(docker)# ctest
docker compose down
```

## Use uthic in your CMake project
```
include(FetchContent)
FetchContent_Declare(
  uthic
  GIT_REPOSITORY https://github.com/kazuki-iwanaga/uthic
  GIT_TAG v0.1
)

# FetchContent_MakeAvailable(uthic) # Available for CMake>=3.14
FetchContent_GetProperties(uthic)
if(NOT uthic_POPULATED)
  FetchContent_Populate(uthic)
  add_subdirectory(${uthic_SOURCE_DIR} ${uthic_BINARY_DIR})
endif()
```

## GCC
```
cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/g++
```