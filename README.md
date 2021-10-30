# ISPC-Programming
&nbsp;
## Intel SPMD Program Compiler (ISPC) 활용 병렬프로그래밍
SPMD : Single Program Multiple Data
&nbsp;
기존의 스칼라 방식은 한번에 한개의 연산을 수행하기 때문에 실행시간이 길어져 비효율적인 측면이 있다.

이를 해결하기 위해 SPMD 프로그래밍을 활용한다.

&nbsp;

> Call to ISPC function spawns "gang" of ISPC "program instances"
>
> All instances run ISPC code concurrently
>
> Each instance has its own copy of local variables

ISPC language keywords

- programCount : number of simultaneously executing instances in the gang (uniform value)
- programIndex : id of the current instance in the gang (non-uniform value: varing)
- uniform : A type modifier. All instances have the same value for this variable. Its use is purely an optimization.

&nbsp;

"gang"이라고 불리는 인스턴스들의 모음을 통해 동일한 연산을 동시에 수행한다.

gang의 크기 : programCount

gang 내에서의 programIndex 범위 : 0 <= programIndex < programCount

&nbsp;

## What's in this repository?

- 1029_sca_vec
  - 스칼라 연산과 벡터 연산의 비교
- 1029_inter_block
  - interleaved 방식과 blocked 방식의 비교
- 1029_minmax
  - 최대 최소 값을 구할 때 스칼라 방식과 벡터 방식의 비교

&nbsp;

## How to compile?

```bash
$ ls
main.cpp program.ispc

$ ispc program.ispc -o program_ispc.o
$ ispc program.ispc -h program_ispc.h
$ g++ -c main.cpp -o main.o
$ g++ main.o program_ispc.o -o program
$ ./program
```

