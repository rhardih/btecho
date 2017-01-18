# btecho

Write integer arguments as a binary tree to the standard output.

## Installation

```bash
$ make && make install
```

## Examples

```bash
$ echo 7 3 2 9 10 4 5 1 8 6 | btecho
|- 7
   |- 9
   |  |- 10
   |  |- 8
   |- 3
      |- 4
      |  |- 5
      |     |- 6
      |- 2
         |- 1
```

```bash
$ seq 5 | gshuf | tee /dev/tty | btecho
3
4
1
2
5
|- 3
   |- 4
   |  |- 5
   |- 1
      |- 2
```
