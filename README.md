## Frequency Extractor
A program that analyses a text file for changes in the signal defined by the file format.

#### Usage

FE &lt;Input FileName&gt;

#### File Format

The program will expect a file format where each line has two decimal numbers. The first being the time that the data was observed, and the second being the value of the data.

For the program to work the data MUST be centered around 1.

##### The Makefile

The Makefile was designed to be used on windows systems and uses NMake to run it. Also the compiler uses cl.exe and link.exe to compile and link the objects respectively. These programs can be acquired by downloading installing Microsoft Visual Studio or the free version, Microsoft Visual Studio Express.

##### Additional Notes

The txt file, dumpdata.txt is a sample version of what all input files accepted by this program will look like.