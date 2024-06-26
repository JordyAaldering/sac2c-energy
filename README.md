
# SaC energy module

## Prerequisites

Install `rapl-energy-c` from https://github.com/JordyAaldering/rapl-energy.

## Example

Running `sudo ./a.out` gives the following output for me.

```
[10404, 10404, 1606, 1606, 3532, 3532, 8465, 8465, 2277, 2277, 7408, 7408, 6419, 6419, 3923, 3923]
[5323242]
```

Note that `sudo` is required in order to access model-specific registers (MSR), which we need for the first line.
The second line comes from RAPL, for which `sudo` is not required given that the permissions are set correctly.
