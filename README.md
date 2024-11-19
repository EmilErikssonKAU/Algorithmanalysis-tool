# Algorithm-analysis tool

## Prerequisites

This tool is to be used within a Linux enviornment.

## Usage

```bash
make
```

```bash
./bin/main
```

## Increasing precision

To increase the precision and accuracy of the tool: 
    - Increase the value of ITERATIONS in analyze.h
    - Increase the value of RESULT_ROWS un ui.h

Any increase in values of these macros will increase the accuracy of the time analysis,
but will also decrease performance of the program.