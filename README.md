# advent-of-code-2019

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x Advent.exe --help

Help:
  -o output data
  -d day problem
  -help  Display this list of options
  --help  Display this list of options
```

i.e.: problem of day1 with input file "day1.txt" and out to the stdout:

```
 esy x Advent.exe -d 1 day1.txt 
```