<!-- {% raw %} -->
# Rainfall I: OOPS23-Rainfall-010

## Source

Space: `·` Tab: `-` [EOL](https://en.wikipedia.org/wiki/Newline) `$`

```C++
 1 /*$
 2 ····rainfall.cpp$
 3 $
 4 ····Rainfall report. Inputs are rain amounts per hour. Output is the average$
 5 ····and heaviest hourly rainfall.$
 6 */$
 7 $
 8 #include <iostream>$
 9 #include <iomanip>$
10 #include <vector>$
11 $
12 int main() {$
13 ····std::vector<float> rainfall;$
14 ····float t, m, n;$
15 ····while (std::cin >> n) {$
16 ········rainfall.push_back(n);$
17 ····}$
18 ····if (!rainfall.size()) {$
19 ········std::cerr << "Error: no rainfall data";$
20 ········return 1;$
21 ····}$
22 ····t = rainfall[0];$
23 ····m = rainfall[0];$
24 ····for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {$
25 ········t += rainfall[i];$
26 ········if (rainfall[i] > m)$
27 ············m = rainfall[i];$
28 ····}$
29 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
30 ····std::cout << "|:----------------|----------------|" << '\n';$
31 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';$
32 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << m << " |" << '\n';$
33 $
34 ····return 0;$
35 }$
```

## Style

Changed files:

```console
rainfall.cpp
```

Indentation Patterns for rainfall.cpp

```console
····
········
············
```

## Build
% mkdir build; cd build; cmake ..

```console
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check output uses diff: /usr/bin/diff
-- Configuring done
-- Generating done
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```


## Commit Messages

```console
Add a header comment
Add a final return to main()
Remove using namespace std
Change error output from standard output to standard error
```

## Commits
## git checkout 503a75

% git show

```diff
commit 503a75c161ae132b14a2ded3f83794e31ad3d27c
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 11:46:46 2023 -0500

    Add a header comment

diff --git a/rainfall.cpp b/rainfall.cpp
index 3b0651c..57decdb 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -1,3 +1,10 @@
+/*
+    rainfall.cpp
+
+    Rainfall report. Inputs are rain amounts per hour. Output is the average
+    and heaviest hourly rainfall.
+*/
+
 #include <iostream>
 #include <iomanip>
 #include <vector>
```


% cmake ..

```console
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check output uses diff: /usr/bin/diff
-- Configuring done
-- Generating done
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
lstat /Users/collard/Library/Mobile Documents/com~apple~CloudDocs/ClassS23/Rainfall-01-12-2023-12-32-52/oracle/rainfall.cpp: no such file or directory

```diff
diff: /Source/rainfalloracle.cpp: No such file or directory
```

## git checkout 382944

% git show

```diff
commit 382944e5e3eee867e0eff6c67d8c2b3abc64e53d
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 11:52:52 2023 -0500

    Add a final return to main()

diff --git a/rainfall.cpp b/rainfall.cpp
index 57decdb..0a3469a 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -32,4 +32,6 @@ int main() {
     cout << "|:----------------|----------------|" << '\n';
     cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
     cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';
+
+    return 0;
 }
```


% cmake ..

```console
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check output uses diff: /usr/bin/diff
-- Configuring done
-- Generating done
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp

```diff
34a35,36
> 
>     return 0;
```

## git checkout 280e43

% git show

```diff
commit 280e4363ac325f3268678e6f72d16fa9db61681b
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 11:57:04 2023 -0500

    Remove using namespace std

diff --git a/rainfall.cpp b/rainfall.cpp
index 0a3469a..e855a9a 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -9,29 +9,27 @@
 #include <iomanip>
 #include <vector>
 
-using namespace std;
-
 int main() {
-    vector<float> rainfall;
+    std::vector<float> rainfall;
     float t, m, n;
-    while (cin >> n) {
+    while (std::cin >> n) {
         rainfall.push_back(n);
     }
     if (!rainfall.size()) {
-        cout << "Error: no rainfall data";
+        std::cout << "Error: no rainfall data";
         return 1;
     }
     t = rainfall[0];
     m = rainfall[0];
-    for (vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
+    for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
         t += rainfall[i];
         if (rainfall[i] > m)
             m = rainfall[i];
     }
-    cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
-    cout << "|:----------------|----------------|" << '\n';
-    cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
-    cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';
+    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
+    std::cout << "|:----------------|----------------|" << '\n';
+    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
+    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
 
     return 0;
 }
```


% cmake ..

```console
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check output uses diff: /usr/bin/diff
-- Configuring done
-- Generating done
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp

```diff
12,13d11
< using namespace std;
< 
15c13
<     vector<float> rainfall;
---
>     std::vector<float> rainfall;
17c15
<     while (cin >> n) {
---
>     while (std::cin >> n) {
21c19
<         cout << "Error: no rainfall data";
---
>         std::cout << "Error: no rainfall data";
26c24
<     for (vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
---
>     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
31,34c29,32
<     cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
<     cout << "|:----------------|----------------|" << '\n';
<     cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
<     cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';
---
>     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
>     std::cout << "|:----------------|----------------|" << '\n';
>     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
>     std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
```

## git checkout 89f12f

% git show

```diff
commit 89f12f8571b902676cf13e9fa0463baf97295d67
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 12:00:27 2023 -0500

    Change error output from standard output to standard error

diff --git a/rainfall.cpp b/rainfall.cpp
index e855a9a..01c22e2 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -16,7 +16,7 @@ int main() {
         rainfall.push_back(n);
     }
     if (!rainfall.size()) {
-        std::cout << "Error: no rainfall data";
+        std::cerr << "Error: no rainfall data";
         return 1;
     }
     t = rainfall[0];
```


% cmake ..

```console
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check output uses diff: /usr/bin/diff
-- Configuring done
-- Generating done
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp

```diff
19c19
<         std::cout << "Error: no rainfall data";
---
>         std::cerr << "Error: no rainfall data";
```


<!-- {% endraw %} -->
