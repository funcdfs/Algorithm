
## use finder to open the c++ header folder

```sh

copy pwd

such as: /Library/Developer/CommandLineTools/SDKs/MacOSX15.0.sdk/usr/include/c++/v1/

cd {pwd}
```


## copy file to mac and pre compiled this two header:


1:

```sh
sudo rm -rf algo
sudo rm -rf bits
```


2:

```sh
sudo mkdir ./bits
sudo mkdir ./algo

sudo touch ./bits/stdc++.h
sudo touch ./algo/dbg.h

sudo cp -f /Users/w/code/Algorithm/Faster/stdc++_simplify.h ./bits/stdc++.h

sudo cp -f /Users/w/code/Algorithm/Faster/dbg.h ./algo/dbg.h
```

3: under code is useless for clangd

```sh
cd algo
sudo g++ -std=c++2b -D LOCAL -Wno-string-compare -Wno-deprecated-array-compare -fno-omit-frame-pointer -fno-inline -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -fsanitize=undefined -fsanitize=address -fstack-protector -Wall -Wextra -H dbg.h
cd ../
```



```sh
cd bits
sudo g++ -std=c++2b -D LOCAL -Wno-string-compare -Wno-deprecated-array-compare -fno-omit-frame-pointer -fno-inline -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -fsanitize=undefined -fsanitize=address -fstack-protector -Wall -Wextra -H stdc++.h
cd ../
```