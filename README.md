# lorenzattractor

**Auteur(s):** Hyuse & T2

## Description

Décrivez brièvement le projet ici.

## Structure du projet

```
lorenzattractor_HYUSE_T2/
├── CMakeLists.txt
├── README.md
├── doc/
│   ├── CMakeLists.txt
│   ├── analyse.txt
│   └── doxyfilerc
├── include/
│   └── *.hxx
├── src/
│   ├── CMakeLists.txt
│   └── *.cxx
├── test/
│   ├── CMakeLists.txt
│   └── *.cxx
├── demo/
│   ├── CMakeLists.txt
│   └── *.cxx
└── build/
```

## Compilation

```bash
cd build
cmake ..
make
```

## Documentation

```bash
cd build
cmake ..
make doc
# Documentation générée dans doc/html/index.html
```

## Tests

```bash
cd build
cmake ..
make
./test/lorenzattractor_test
```
