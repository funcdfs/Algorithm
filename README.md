# 万物皆虚



#### cpp setup backup

`gcc version 14.1.0+`


pre compile stdc++.h

```c++
g++ -std=gnu++2a -D LOCAL -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -H stdc++.h
```

pre compile dbg.h

```c++
g++ -std=gnu++2a -D LOCAL -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -H dbg.h
```

Local run 

```c++
-std=gnu++2a -D LOCAL -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align
```

or 

```c++
-std=gnu++2a -D LOCAL
```

dbg.h file: [gist.github.com/funcdfs/algo/dbg.h](https://gist.github.com/funcdfs/093ea21e3e3d033298191a5f4c635069)


fake bits/stdc++.h

```c++
#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
```