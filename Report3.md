<!-- {% raw %} -->
# Rainfall III: OOPS23-Rainfall-010

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
10 #include <iterator>$
11 #include <vector>$
12 $
13 int main() {$
14 $
15 ····// input hourly rainfall data$
16 ····const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),$
17 ········································std::istream_iterator<double>() };$
18 ····if (!rainfall.size()) {$
19 ········std::cerr << "Error: no rainfall data\n";$
20 ········return 1;$
21 ····}$
22 $
23 ····// calculate heaviest rainfall$
24 ····auto heaviest = rainfall[0];$
25 ····for (const auto rain: rainfall) {$
26 ········if (rain > heaviest)$
27 ············heaviest = rain;$
28 ····}$
29 $
30 ····// calculate average rainfall$
31 ····auto total = 0.0;$
32 ····for (const auto rain: rainfall) {$
33 ········total += rain;$
34 ····}$
35 ····const auto average = (total / rainfall.size());$
36 $
37 ····// output the rainfall report$
38 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
39 ····std::cout << "|:----------------|----------------|" << '\n';$
40 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';$
41 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << heaviest << " |" << '\n';$
42 $
43 ····return 0;$
44 }$
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
········································
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
Move local variable declarations to where first used
Rename variable t to total
Rename variable m to heaviest
Replace explicit type with auto
Separate calculation of average and heaviest
Extract average calculation from output
Replace indexed for with range-based for
Add const to average
Replace input loop with std::istream_iterator
```

## Diff

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```

## Commits

## git checkout da91f7

% git show

```diff
commit da91f758c413235f9f8f38a99a3d18760ee7d152
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:22:23 2023 -0500

    Move local variable declarations to where first used

diff --git a/rainfall.cpp b/rainfall.cpp
index 3080a58..bf0f2ef 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -13,8 +13,6 @@ int main() {
 
     // input hourly rainfall data
     std::vector<double> rainfall;
-    double t;
-    double m;
     double n;
     while (std::cin >> n) {
         rainfall.push_back(n);
@@ -25,8 +23,8 @@ int main() {
     }
 
     // calculate average and heaviest rainfall
-    t = rainfall[0];
-    m = rainfall[0];
+    double t = rainfall[0];
+    double m = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         t += rainfall[i];
         if (rainfall[i] > m)
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

## git checkout ed2d48

% git show

```diff
commit ed2d4868ac594ee7c0012198c04f3c3ba36c3ad9
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:25:50 2023 -0500

    Rename variable t to total

diff --git a/rainfall.cpp b/rainfall.cpp
index bf0f2ef..fa42354 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -23,10 +23,10 @@ int main() {
     }
 
     // calculate average and heaviest rainfall
-    double t = rainfall[0];
+    double total = rainfall[0];
     double m = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        t += rainfall[i];
+        total += rainfall[i];
         if (rainfall[i] > m)
             m = rainfall[i];
     }
@@ -34,7 +34,7 @@ int main() {
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
-    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
+    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
     std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
 
     return 0;
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

## git checkout d5ff8a

% git show

```diff
commit d5ff8a10210c046b6c529316001d5ce2c452af90
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:27:11 2023 -0500

    Rename variable m to heaviest

diff --git a/rainfall.cpp b/rainfall.cpp
index fa42354..f2e58ce 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -24,18 +24,18 @@ int main() {
 
     // calculate average and heaviest rainfall
     double total = rainfall[0];
-    double m = rainfall[0];
+    double heaviest = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
-        if (rainfall[i] > m)
-            m = rainfall[i];
+        if (rainfall[i] > heaviest)
+            heaviest = rainfall[i];
     }
 
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
-    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
+    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';
 
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

## git checkout 941a74

% git show

```diff
commit 941a7406d3401085a0deac852dc8c1b4aa721fd5
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:31:11 2023 -0500

    Replace explicit type with auto

diff --git a/rainfall.cpp b/rainfall.cpp
index f2e58ce..1f3735c 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -23,8 +23,8 @@ int main() {
     }
 
     // calculate average and heaviest rainfall
-    double total = rainfall[0];
-    double heaviest = rainfall[0];
+    auto total = rainfall[0];
+    auto heaviest = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
         if (rainfall[i] > heaviest)
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

## git checkout 529861

% git show

```diff
commit 5298618e292f8fb1db26d707a2bebd85ebe6c259
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:37:26 2023 -0500

    Separate calculation of average and heaviest

diff --git a/rainfall.cpp b/rainfall.cpp
index 1f3735c..c109596 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -22,15 +22,19 @@ int main() {
         return 1;
     }
 
-    // calculate average and heaviest rainfall
-    auto total = rainfall[0];
+    // calculate heaviest rainfall
     auto heaviest = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        total += rainfall[i];
         if (rainfall[i] > heaviest)
             heaviest = rainfall[i];
     }
 
+    // calculate average rainfall
+    auto total = rainfall[0];
+    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
+        total += rainfall[i];
+    }
+
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
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

## git checkout e7cfc5

% git show

```diff
commit e7cfc51cc9c0915a5c6c062ab8023aea7cdca417
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:42:09 2023 -0500

    Extract average calculation from output

diff --git a/rainfall.cpp b/rainfall.cpp
index c109596..66fe548 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -34,11 +34,12 @@ int main() {
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
     }
+    auto average = (total / rainfall.size());
 
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
-    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
+    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';
     std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';
 
     return 0;
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

## git checkout 1d2404

% git show

```diff
commit 1d2404b5ed28960b2cf11c214a77433687cc7263
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:48:26 2023 -0500

    Replace indexed for with range-based for

diff --git a/rainfall.cpp b/rainfall.cpp
index 66fe548..351fb48 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -24,15 +24,15 @@ int main() {
 
     // calculate heaviest rainfall
     auto heaviest = rainfall[0];
-    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        if (rainfall[i] > heaviest)
-            heaviest = rainfall[i];
+    for (const auto rain: rainfall) {
+        if (rain > heaviest)
+            heaviest = rain;
     }
 
     // calculate average rainfall
-    auto total = rainfall[0];
-    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        total += rainfall[i];
+    auto total = 0.0;
+    for (const auto rain: rainfall) {
+        total += rain;
     }
     auto average = (total / rainfall.size());
 
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

## git checkout a3b89b

% git show

```diff
commit a3b89bd7a1c9fa0c51a7a5974e8eda991d51709e
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:50:08 2023 -0500

    Add const to average

diff --git a/rainfall.cpp b/rainfall.cpp
index 351fb48..411b5d7 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -34,7 +34,7 @@ int main() {
     for (const auto rain: rainfall) {
         total += rain;
     }
-    auto average = (total / rainfall.size());
+    const auto average = (total / rainfall.size());
 
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
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

## git checkout e02e12

% git show

```diff
commit e02e127c7b4af08d54b8b499bb41def73fb4b46c
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 11:57:36 2023 -0500

    Replace input loop with std::istream_iterator

diff --git a/rainfall.cpp b/rainfall.cpp
index 411b5d7..0508431 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -7,16 +7,14 @@
 
 #include <iostream>
 #include <iomanip>
+#include <iterator>
 #include <vector>
 
 int main() {
 
     // input hourly rainfall data
-    std::vector<double> rainfall;
-    double n;
-    while (std::cin >> n) {
-        rainfall.push_back(n);
-    }
+    const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),
+                                        std::istream_iterator<double>() };
     if (!rainfall.size()) {
         std::cerr << "Error: no rainfall data\n";
         return 1;
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
