# Inventory Data Program - C/C++

This is a simple Inventory Management System that was built using C/C++ -- TEST DATA

<br>
<br>
Tasks:

<p style="font-weight: bold; text-decoration: underline">Initialize Inventory Data</p>

1. Create an Inventory struct that allows for storage of data:
    - Initialize Inventory struct with data read in from the i_Data.txt file

    - Calculate and store each Inventory Item's total value as part of the Item record

2. Create an array called InventoryItems that stores records of the Inventory struct


<p style="font-weight: bold; text-decoration: underline">Menu Operations</p>

3. Display Inventory Data 

    ```
    INFORMATION OF DATA
    Item#          Name        Unit Price            Min Lev            Opt Level              Qty on Hand                 Total Values
    1003       Flour-Bak          13.45                210                   500                     410                     5514.50
    1005          Coffee          57.85                 50                    60                      41                     2371.85
    1007  Detergent-500G          36.75                 50                    75                      64                     2352.00
    1002         Milk-1L          12.85                100                   150                      83                     1066.55
    1009        Flour-AP          21.95                 20                    60                      47                     1031.65
    1001          Butter           9.45                 50                   100                      74                      699.30
    1004        Eggs/Doz          21.75                 25                    40                      18                      391.50
    1006       Spaghetti           6.95                 40                    75                       0                        0.00
    1008        Flour-WW          17.85                 20                    40                       0                        0.00
    1010     Juice-750ML          24.35                 40                    50                       0                        0.00
    ```

4. Search and display details of an Inventory

    ```
        Search Bar (Enter Item#) : 1001

        Name         Unit Price              Min Lev              Opt Level             Qty on Hand             Total Values 
        Butter         9.45                   50                    100                      74                    699.30
    ```

5. View Inventory Reports (displays a secondary menu of Report options)
    - Display Inventory Statistics Report

        ```
            ------- Stats
            Total Value of All Inventory = 13427.35
            Average Value of All Inventory = 1342.73
        ```

    - Display Out of Stock Inventory Items Report

        ```
            Item#             Name          Unit Price             Qty on Hand               Total Value
            1006         Spaghetti                 6.95                      0                     0.00
            1008          Flour-WW                17.85                      0                     0.00
            1010       Juice-750ML                24.35                      0                     0.00
        ```

    - Print Items for Reorder Report (Creates a file called Orders.txt) - View Orders.txt file for results

6. Quit

<br>
<br>

# Run Program

Compile: 
```
g++ inventory.cpp
```

Run Code:
```
./a.out
```

Compile and Run:
```
g++ inventory.cpp && ./a.out
```