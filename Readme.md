# HW0
This is a readaption of update_location.py into c++ version. The corresponding data structure used in c++ is array. The c++ project has only one header file and one .cpp file. To avoid confusion, the test files done separately using std::vector in c++ is omitted. 
## Part 1
a.The total number of additions involved (not considering checksum) is sizex3xiter. For comparability we want to adjust the arguments so that this number is constant across executions. Since we are multiplying the size by 2, I choose to divide the iteration steps by 2 each time.

b. I chose to pick the average of three observations. Because of the limited sample size, choosing medium might introduce some bias.

c.
![Plot of time consumption](https://github.com/QwertyQwh/389HW0/blob/master/Plot.png?raw=true)


## Part 2

![enter image description here](https://github.com/QwertyQwh/389HW0/blob/master/plotpc.png?raw=true)

c++ is on average 50 times faster. Strangely, when I tried to use std::vector instead of array, the performance drops dramatically to about the same level of python. 

## Part 3
![enter image description here](https://github.com/QwertyQwh/389HW0/blob/master/comparedata_t.png?raw=true)

No matter what the array size is, the 'larger' the data type, the more time it consumes to run the iterations.

## Part 4
Using size = 2^20 and iter = 32 in both cases, python version costs approximately 0.217us and 206 Mb, whereas c++ version costs approximately 0.00514us and 28 Mb.
