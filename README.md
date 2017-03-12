# Accelerometer

# Conversion.c : 

The C program converts the raw data of each axis from the individual files uploaded data_x.txt, data_y.txt,
data_z.txt into usable angles in degree.

# Acc_output.txt : 

This is the output after the compilation of Conversion.c program. It contains value in degrees of X and Y axis respectively

# Compilation:
````
gcc -std=c99 -Wall Conversion.c -lm -o conversion
````
