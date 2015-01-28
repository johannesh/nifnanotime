# Purpose
Determine the nanosecond cost for a call into a NIF.

## Usage
Tested on Linux only.

``` bash
$ script/rebar compile
==> nifnanotime (compile)

$ erl -pa ./ebin/
Erlang R15B01 (erts-5.9.1) [source] [64-bit] [smp:4:4] ...

Eshell V5.9.1  (abort with ^G)
1> nifnanotime:measure_nifinvoke_cost().
19.6920992
2>
```

## TODO
Repeat, plot results, compare common Erlang datastructures with those in C++.
