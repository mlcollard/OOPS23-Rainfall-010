<!-- {% raw %} -->
# Rainfall II: OOPS23-Rainfall-010

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
13 $
14 ····// input hourly rainfall data$
15 ····std::vector<double> rainfall;$
16 ····double t;$
17 ····double m;$
18 ····double n;$
19 ····while (std::cin >> n) {$
20 ········rainfall.push_back(n);$
21 ····}$
22 ····if (!rainfall.size()) {$
23 ········std::cerr << "Error: no rainfall data\n";$
24 ········return 1;$
25 ····}$
26 $
27 ····// calculate average and heaviest rainfall$
28 ····t = rainfall[0];$
29 ····m = rainfall[0];$
30 ····for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {$
31 ········t += rainfall[i];$
32 ········if (rainfall[i] > m)$
33 ············m = rainfall[i];$
34 ····}$
35 $
36 ····// output the rainfall report$
37 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
38 ····std::cout << "|:----------------|----------------|" << '\n';$
39 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';$
40 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << m << " |" << '\n';$
41 $
42 ····return 0;$
43 }$
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
Add a newline to the error output
Separate each section of code with a single newline
Comment each section of code
Separate each variable into its own declaration statement
Replace float with double
```

## Diff

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```

## Commits

## git checkout a107fe

% git show

```diff
commit a107fecf85d64f1ee535adec1529d94899310856
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 11:39:36 2023 -0500

    Add a newline to the error output

diff --git a/rainfall.cpp b/rainfall.cpp
index 01c22e2..f8f6f1b 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -16,7 +16,7 @@ int main() {
         rainfall.push_back(n);
     }
     if (!rainfall.size()) {
-        std::cerr << "Error: no rainfall data";
+        std::cerr << "Error: no rainfall data\n";
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

## git checkout 9cc881

% git show

```diff
commit 9cc881f5596e9e51967358565175f1862e9b7129
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 11:43:13 2023 -0500

    Separate each section of code with a single newline

diff --git a/rainfall.cpp b/rainfall.cpp
index f8f6f1b..31e31e1 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -19,6 +19,7 @@ int main() {
         std::cerr << "Error: no rainfall data\n";
         return 1;
     }
+
     t = rainfall[0];
     m = rainfall[0];
     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
@@ -26,6 +27,7 @@ int main() {
         if (rainfall[i] > m)
             m = rainfall[i];
     }
+
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
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

## git checkout 4ce04e

% git show

```diff
commit 4ce04e67e96c46d03745b633ebcf39a836fbb4cb
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 11:49:22 2023 -0500

    Comment each section of code

diff --git a/rainfall.cpp b/rainfall.cpp
index 31e31e1..a3c9df1 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -10,6 +10,8 @@
 #include <vector>
 
 int main() {
+
+    // input hourly rainfall data
     std::vector<float> rainfall;
     float t, m, n;
     while (std::cin >> n) {
@@ -20,6 +22,7 @@ int main() {
         return 1;
     }
 
+    // calculate average and heaviest rainfall
     t = rainfall[0];
     m = rainfall[0];
     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
@@ -28,6 +31,7 @@ int main() {
             m = rainfall[i];
     }
 
+    // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
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

## git checkout 232e8d

% git show

```diff
commit 232e8de75ebe96ae1ccdaf653eb7bdea9714a9ee
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 11:54:22 2023 -0500

    Separate each variable into its own declaration statement

diff --git a/rainfall.cpp b/rainfall.cpp
index a3c9df1..569da79 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -13,7 +13,9 @@ int main() {
 
     // input hourly rainfall data
     std::vector<float> rainfall;
-    float t, m, n;
+    float t;
+    float m;
+    float n;
     while (std::cin >> n) {
         rainfall.push_back(n);
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

## git checkout 1ba4ae

% git show

```diff
commit 1ba4ae5a391916c813dc473edccdd1397a2ffdf3
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 11:58:03 2023 -0500

    Replace float with double

diff --git a/rainfall.cpp b/rainfall.cpp
index 569da79..3080a58 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -12,10 +12,10 @@
 int main() {
 
     // input hourly rainfall data
-    std::vector<float> rainfall;
-    float t;
-    float m;
-    float n;
+    std::vector<double> rainfall;
+    double t;
+    double m;
+    double n;
     while (std::cin >> n) {
         rainfall.push_back(n);
     }
@@ -27,7 +27,7 @@ int main() {
     // calculate average and heaviest rainfall
     t = rainfall[0];
     m = rainfall[0];
-    for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
+    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         t += rainfall[i];
         if (rainfall[i] > m)
             m = rainfall[i];
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


<!-- {% endraw %} -->
