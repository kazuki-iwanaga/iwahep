# iwahep

## Required:
- `CMake>=3.11`
- `gcc>=5`

## How to Use
```
git clone https://github.com/kazuki-iwanaga/iwahep.git -b cmake-3.11
cd iwahep
docker compose up -d
docker compose exec gcc bash
(docker)# mkdir build && cd build
(docker)# cmake ..
(docker)# make
(docker)# ctest
docker compose down
```