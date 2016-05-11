# 电话聊天狂人 

给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

**输入格式:**

输入首先给出正整数$N(\le 10^5)$,为通话记录条数。随后N行，每行给出一条通话记录。简单起见，这里
只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

**输出格式:**

在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一
，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

**输入样例:**

```
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832
```

**输出样例:**

```
13588625832 3
```

**Solution:**

``` c++
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class HashTable {
public:
        HashTable (int n): key_(n, std::string()), value_(n, 0), size_(n) { }
        int& operator[] (std::string &key);
private:
        std::vector<int> value_;
        std::vector<std::string> key_;
        int hash(std::string &key);
    int size_;
};

int& HashTable::operator[] (std::string &key) {
        int hash_id = hash(key);
        if (key_[hash_id].empty() || key_[hash_id] == key) {
        key_[hash_id] = key;
        return value_[hash_id];
    }
    for (int i = 1; ; i++) {
        hash_id = (hash_id + i * i) % size_;
        if (key_[hash_id].empty() || key_[hash_id] == key) {
            key_[hash_id] = key;
            return value_[hash_id];
        }
        hash_id = (hash_id - i * i) % size_;
        if (key_[hash_id].empty() || key_[hash_id] == key) {
            key_[hash_id] = key;
            return value_[hash_id];
        }
    }
}

int HashTable::hash(std::string &key) {
        std::string value_part(key.begin() + 5, key.end());
        return atoi(value_part.c_str()) % size_;
}

bool is_primer (int n) {
    if (n <= 3) {
        return n > 1;
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int main(int argc, char* argv[]) {
        int N;
        std::cin >> N;
    int size = 4 * N + 1;
    while (!is_primer(++size)) { }

    HashTable phone_num(size);

        int max_count = 0;
        int parrel_num = 1;
    std::string max_number;

        for (int i = 0; i < 2 * N; i++) {
        std::string number;
                std::cin >> number;
                if (phone_num[number] == 0) {
                        phone_num[number] = 1;
                } else {
                        phone_num[number]++;
                }
                if (phone_num[number] > max_count) {
                        max_count = phone_num[number];
                        max_number = number;
                        parrel_num = 1;
                } else if (phone_num[number] == max_count) {
                        max_number = std::min(max_number, number);
                        parrel_num++;
                }
        }
        if (parrel_num > 1)
                std::cout << max_number << " " << max_count << " " << parrel_num << std::endl;
        else
                std::cout << max_number << " " << max_count << std::endl;

        return 0;

}
```
