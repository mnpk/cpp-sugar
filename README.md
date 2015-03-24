# cpp-sugar

trivial but useful things in c++.

### case-insensitive map
case-insensitive string key map is very useful.

```c++
sugar::imap<string> map;
map["hello"] = "world!";
cout << map["hello"] << endl;  //  print "world!"
cout << map["HELLO"] << endl;  //  also, print "world!"
```

### chrono::time_point to string with msec
strftime not support msec, and put_time has not implemented in g++ yet.

```c++
auto now = chrono::system_clock::now();
cout << sugar::to_hhmmssfff(now) <<  endl;  // print "HH:MM:SS.fff" formatted current time
```
