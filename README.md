# advent-of-code-2019


[![CircleCI](https://circleci.com/gh/yourgithubhandle/advent-of-code-2019/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/advent-of-code-2019/tree/master)


**Contains the following libraries and executables:**

```
advent-of-code-2019@0.0.0
│
├─test/
│   name:    TestAdventOfCode2019.exe
│   main:    TestAdventOfCode2019
│   require: advent-of-code-2019.lib
│
├─library/
│   library name: advent-of-code-2019.lib
│   namespace:    AdventOfCode2019
│   require:
│
└─executable/
    name:    AdventOfCode2019App.exe
    main:    AdventOfCode2019App
    require: advent-of-code-2019.lib
```

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
 esy x Advent.exe -d 1 day1.txt
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
