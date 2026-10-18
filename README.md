# XML Attribute Parser

## English

### Overview
This project provides a small C++ XML parser focused on:
- reading XML tags recursively
- extracting attributes into a key/value map
- validating that opening and closing tag names match

If a closing tag does not match its opening tag, the parser throws a `ParseException`.

### Project structure
- `xml_parser/include/xml_parser.hpp` – parser interface
- `xml_parser/include/parse_exception.hpp` – custom exception
- `xml_parser/src/xml_parser.cpp` – parser implementation
- `xml_parser/src/main.cpp` – executable entry point
- `xml_parser/CMakeLists.txt` and `xml_parser/makefile` – build files

### Build
From `/home/runner/work/xml_attribute_parser/xml_attribute_parser/xml_parser`:

#### With Make
```bash
make all
```

#### With CMake
```bash
cmake -S . -B build
cmake --build build
```

### Run
You can provide XML input through standard input:

```bash
./main
```

or, for the CMake target:

```bash
./build/xml_parser
```

The program prints parsed attributes as:
`attribute_name: attribute_value`

---

## Italiano

### Panoramica
Questo progetto fornisce un piccolo parser XML in C++ focalizzato su:
- lettura ricorsiva dei tag XML
- estrazione degli attributi in una mappa chiave/valore
- validazione della corrispondenza tra tag di apertura e chiusura

Se un tag di chiusura non corrisponde al relativo tag di apertura, il parser lancia una `ParseException`.

### Struttura del progetto
- `xml_parser/include/xml_parser.hpp` – interfaccia del parser
- `xml_parser/include/parse_exception.hpp` – eccezione personalizzata
- `xml_parser/src/xml_parser.cpp` – implementazione del parser
- `xml_parser/src/main.cpp` – punto di ingresso dell'eseguibile
- `xml_parser/CMakeLists.txt` e `xml_parser/makefile` – file di build

### Build
Da `/home/runner/work/xml_attribute_parser/xml_attribute_parser/xml_parser`:

#### Con Make
```bash
make all
```

#### Con CMake
```bash
cmake -S . -B build
cmake --build build
```

### Esecuzione
Puoi fornire l'input XML tramite standard input:

```bash
./main
```

oppure, per il target CMake:

```bash
./build/xml_parser
```

Il programma stampa gli attributi nel formato:
`nome_attributo: valore_attributo`
