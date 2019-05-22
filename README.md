# Huffman Codes

> Author: [@037](https://twitter.com/037)

### Compile
```
sudo g++ -std=c++11 -o Huffman.exe Huffman.cpp
```

### Description
Suppose that we have to store a sequence of symbols (a file) efficiently, namely we want to minimize the amount of memory needed. For the sake of simplicity we assume that the symbols are restricted to the first 6 letters of the alphabet.

### Input structure
The input consists of 6 integers, one per each line. Each integer represents the frequency of characters, A, B, C, D, E, and F, in this order.

### Output structure
Output is the the decision about which tree goes to the left and which one goes to the right. The final tree is unique.

### Example

*Input*
```
15
11
5
1
2
4
```

*Output*
```
A:0
B:10
C:110
D:11100
E:11101
F:1111
```