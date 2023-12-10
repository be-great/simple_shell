# Simple Shell - Automated Testing Script

## The test files structure

```
/
├── README.md
├── checker
├── run
└── tests/
    └── task/
        └── test_case.sh
```

## How To Use

```sh
$ ./run <hsh executable> <the checker file> <the tests ...>
```

```sh
Usage: ./run <hsh> <checker_script> <tests...>

Args:
  hsh: is the shell executable
  checker_script: is the downloaded checker script file
  tests[]: can be any number of: test_script/dirs or dirs of dirs contains test scripts

Example: ./run ./hsh ./checker ./tests
Example: ./run ./hsh ./checker ./tests/task
Example: ./run ./hsh ./checker ./tests/task/test_case.bash
Example: ./run ./hsh ./checker ./test_case1.bash ./tests/task2/

```

### Examples

- To execute task test case only

```sh
$ ./run ./hsh ./checker ./task/test_case.sh
```

- To execute all task test cases

```sh
$ ./run ./hsh ./checker ./tests/task
```

- To execute all tasks test cases

```sh
$ ./run ./hsh ./checker ./tests
```

- You can test picked test cases mixed with picked tasks too

```sh
$ ./run ./hsh ./checker ./tests/task1 ./tests/task2/test1.bash ./tests/task2/test2.bash
```

> Note: on arch distro you need to export an environment variable while testing
> to prevent valgrind problems
> By default the tool auto detects arch systems and export the var for you
> but in case of manual testing you should do it manually
>
> ```sh
> $ export DEBUGINFOD_URLS="https://debuginfod.archlinux.org"
> ```
