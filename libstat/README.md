# a short PoC how to read your own stats out of /proc filesystem


# limitations
- parsing of the stats might fail if:
  - your application name contains the ")"  character
  - your application is longer than ~600 charcters
- the precision is assumed millsec, calling stat_update() more often will cause errors
- if you are running a kernel with strange jiffis-setup, the converion will fail

# build

run

```
bash make.sh
```

it is not a real library yet

# tests
## dummy1
  showing some cpu,memory,io waste and shows how the respective counters go up
## dummy2
  soak / speed test. run with valgrind, strace, gdb, ....
