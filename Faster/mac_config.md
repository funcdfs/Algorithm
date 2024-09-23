
## use finder to open the c++ header folder 

```sh

copy pwd

cd pwd

then:

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

sudo cp -f /Users/wei/code/Algorithm/Faster/stdc++_simplify.h ./bits/stdc++.h

sudo cp -f /Users/wei/code/Algorithm/Faster/dbg.h ./algo/dbg.h
```

3: under code is useless for clangd

```sh
cd algo
sudo g++ '-std=c++23' -D LOCAL -H dbg.h
cd ../
```



```sh
cd bits
sudo g++ '-std=c++23' -D LOCAL -H stdc++.h
cd ../
```