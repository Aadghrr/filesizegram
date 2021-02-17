WIP
Compile with gcc filesize.c -lm
Produces a histogram of distribution of file sizes in a given directory

Usage:
$ a.out /path/to/some/dir
10^0 0 	        |>
10^1 0 	        |>
10^2 0 	        |>
10^3 8291 	|==>
10^4 87743 	|============================>
10^5 43479 	|==============>
10^6 12113 	|====>
10^7 1189 	|>
10^8 11 	|>
10^9 0 	        |>

Produces an overview of the sizes of the files in a directory in a few seconds.
Size in bytes on the leftmost column, number of files of size in that order of magnitude, followed by the histogram.
