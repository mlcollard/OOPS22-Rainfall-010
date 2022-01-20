<!-- {% raw %} -->
# Rainfall I: OOPS22-Rainfall-010

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
16 ····double n;$
17 ····while (std::cin >> n) {$
18 ········rainfall.push_back(n);$
19 ····}$
20 ····if (!rainfall.size()) {$
21 ········std::cerr << "Error: no rainfall data\n";$
22 ········return 1;$
23 ····}$
24 $
25 ····// calculate average rainfall$
26 ····auto total = rainfall[0];$
27 ····for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {$
28 ········total += rainfall[i];$
29 ····}$
30 $
31 ····// calculate heaviest rainfall$
32 ····auto max = rainfall[0];$
33 ····for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {$
34 ········if (rainfall[i] > max)$
35 ············max = rainfall[i];$
36 ····}$
37 $
38 ····// output the rainfall report$
39 ····std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " hundreds of inches" << '\n';$
40 ····std::cout << "Heaviest Hourly Rainfall: " << max << " hundreds of inches" << '\n';$
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
....
........
............
```

## Build
% mkdir build; cd build; cmake ..


```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```


## Commit Messages

```console
Separate calculation of average and max
Replace explicit type with auto
Rename variable m to max
Rename variable t to total
Move local variable declarations to where first used
Replace float with double
Comment each section of code
Separate each section of code with a single newline
Add a newline to the error output
Change error output from standard output to standard error
Remove using namespace std
Add a final return to main()
Add a header comment
Initial commit
```

# Commits
## git checkout 126656

% git show

```diff
commit 126656ae80abe233d4aad90ecbd4ff9188c6116a
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:31:09 2022 -0500

    Add a header comment

diff --git a/rainfall.cpp b/rainfall.cpp
index 90cce04..7788973 100644
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
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 33717d

% git show

```diff
commit 33717d86d6fee4c7e516e1f415c782e00478a2be
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:34:23 2022 -0500

    Add a final return to main()

diff --git a/rainfall.cpp b/rainfall.cpp
index 7788973..93ec421 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -32,4 +32,6 @@ int main() {
     }
     cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
     cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
+
+    return 0;
 }
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 79f8d9

% git show

```diff
commit 79f8d9c20a07a2be9842f667c909a81495140123
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:39:00 2022 -0500

    Remove using namespace std

diff --git a/rainfall.cpp b/rainfall.cpp
index 93ec421..0a5e3b2 100644
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
     float t;
     float m;
     float n;
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
-    cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
-    cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
+    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
+    std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
 
     return 0;
 }
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 3440dd

% git show

```diff
commit 3440dd0d161779bb9166fdbbd901af666483a233
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:41:04 2022 -0500

    Change error output from standard output to standard error

diff --git a/rainfall.cpp b/rainfall.cpp
index 0a5e3b2..8df9bfd 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -18,7 +18,7 @@ int main() {
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
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout ec5032

% git show

```diff
commit ec50327033371c0ff89351f09a60667e785fccd9
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:44:08 2022 -0500

    Add a newline to the error output

diff --git a/rainfall.cpp b/rainfall.cpp
index 8df9bfd..67ed42c 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -18,7 +18,7 @@ int main() {
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
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 74ddc5

% git show

```diff
commit 74ddc5ba08691aa1a41e601d7cdcc3dc836c1841
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:46:32 2022 -0500

    Separate each section of code with a single newline

diff --git a/rainfall.cpp b/rainfall.cpp
index 67ed42c..8d323e4 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -10,6 +10,7 @@
 #include <vector>
 
 int main() {
+
     std::vector<float> rainfall;
     float t;
     float m;
@@ -21,6 +22,7 @@ int main() {
         std::cerr << "Error: no rainfall data\n";
         return 1;
     }
+
     t = rainfall[0];
     m = rainfall[0];
     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
@@ -28,6 +30,7 @@ int main() {
         if (rainfall[i] > m)
             m = rainfall[i];
     }
+
     std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
     std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
 
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 0da730

% git show

```diff
commit 0da730b6776cda9c7f9fa1ed47a5fc242e950468
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:50:19 2022 -0500

    Comment each section of code

diff --git a/rainfall.cpp b/rainfall.cpp
index 8d323e4..6ad2f78 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -11,6 +11,7 @@
 
 int main() {
 
+    // input hourly rainfall data
     std::vector<float> rainfall;
     float t;
     float m;
@@ -23,6 +24,7 @@ int main() {
         return 1;
     }
 
+    // calculate average and heaviest rainfall
     t = rainfall[0];
     m = rainfall[0];
     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
@@ -31,6 +33,7 @@ int main() {
             m = rainfall[i];
     }
 
+    // output the rainfall report
     std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
     std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
 
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 2ade84

% git show

```diff
commit 2ade8413964185530ec79ec593b669be1e9a528b
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:55:37 2022 -0500

    Replace float with double

diff --git a/rainfall.cpp b/rainfall.cpp
index 6ad2f78..1a427c4 100644
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
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 8f7430

% git show

```diff
commit 8f743053614b8db97ea1bf659a0c60a86a027059
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 14:59:13 2022 -0500

    Move local variable declarations to where first used

diff --git a/rainfall.cpp b/rainfall.cpp
index 1a427c4..a6b2b5c 100644
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
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 949ef2

% git show

```diff
commit 949ef259b95065ec2d68a371bdb8dc9e66ab18b2
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 15:01:38 2022 -0500

    Rename variable t to total

diff --git a/rainfall.cpp b/rainfall.cpp
index a6b2b5c..410ac7c 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -23,16 +23,16 @@ int main() {
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
 
     // output the rainfall report
-    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
+    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " hundreds of inches" << '\n';
     std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
 
     return 0;
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 49d397

% git show

```diff
commit 49d39767730fe7c9ca6271db9d791edb52384d3f
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 15:02:29 2022 -0500

    Rename variable m to max

diff --git a/rainfall.cpp b/rainfall.cpp
index 410ac7c..30844b0 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -24,16 +24,16 @@ int main() {
 
     // calculate average and heaviest rainfall
     double total = rainfall[0];
-    double m = rainfall[0];
+    double max = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
-        if (rainfall[i] > m)
-            m = rainfall[i];
+        if (rainfall[i] > max)
+            max = rainfall[i];
     }
 
     // output the rainfall report
     std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " hundreds of inches" << '\n';
-    std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';
+    std::cout << "Heaviest Hourly Rainfall: " << max << " hundreds of inches" << '\n';
 
     return 0;
 }
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout efd4c0

% git show

```diff
commit efd4c0e350cc3601f1312e83b2de6517c2a2abb8
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 15:05:44 2022 -0500

    Replace explicit type with auto

diff --git a/rainfall.cpp b/rainfall.cpp
index 30844b0..8bfb947 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -23,8 +23,8 @@ int main() {
     }
 
     // calculate average and heaviest rainfall
-    double total = rainfall[0];
-    double max = rainfall[0];
+    auto total = rainfall[0];
+    auto max = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
         if (rainfall[i] > max)
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```

## git checkout 03c22c

% git show

```diff
commit 03c22c580d1c0229cf9c5f1446abe98e77ab7d69
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 13 16:14:53 2022 -0500

    Separate calculation of average and max

diff --git a/rainfall.cpp b/rainfall.cpp
index 8bfb947..d2a0b5c 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -22,11 +22,15 @@ int main() {
         return 1;
     }
 
-    // calculate average and heaviest rainfall
+    // calculate average rainfall
     auto total = rainfall[0];
-    auto max = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
+    }
+
+    // calculate heaviest rainfall
+    auto max = rainfall[0];
+    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         if (rainfall[i] > max)
             max = rainfall[i];
     }
```


% cmake ..

```console
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
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
Consolidate compiler generated dependencies of target rainfall
[100%] Built target rainfall
Average Hourly Rainfall: 0.04 hundreds of inches
Heaviest Hourly Rainfall: 1.04 hundreds of inches
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp
```diff
```


<!-- {% endraw %} -->
