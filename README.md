
# SaC energy module

## Prerequisites

Install `rapl-energy-c` from https://github.com/JordyAaldering/rapl-energy.

## Example

Running `sudo ./a.out` gives the following output for me.

```
[79735, 79735, 82606, 82606, 108378, 108378, 5662642, 5662642, 65302, 65302, 105730, 105730, 35141, 35141, 94500, 94500]
                                             ^^^^^^^^^^^^^^^^
[139786106]
```

Without multi-threading we see that one core (which consists of 2 threads) has a much greater energy consumption.
In multi-threaded mode this number increases, as expected.

```
$ sudo ./a.out -mt 2
[241721, 241721, 230090, 230090, 166633, 166633, 3497632, 3497632, 139798, 139798, 172235, 172235, 86118, 86118, 3295277, 3295277]
                                                 ^^^^^^^^^^^^^^^^                                                ^^^^^^^^^^^^^^^^
[143585714]
```

```
$ sudo ./a.out -mt 4
[27792, 27792, 1652755, 1652755, 15358, 15358, 23199, 23199, 20047, 20047, 1725755, 1725755, 1549669, 1549669, 1689274, 1689274]
               ^^^^^^^^^^^^^^^^                                            ^^^^^^^^^^^^^^^^  ^^^^^^^^^^^^^^^^  ^^^^^^^^^^^^^^^^
[104487929]
```

Note that `sudo` is required in order to access model-specific registers (MSR), which we need for the first line.
The second line comes from RAPL, for which `sudo` is not required given that the permissions are set correctly.
