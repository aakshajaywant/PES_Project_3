# PES_Project_3
AUTHORS: Aaksha Jaywant and Rucha Borwankar

PES-Project-3
Project By: Aaksha Jaywant and Rucha Borwankar
The project consists of a C code which executes memory tests running on the NXP freedom board KL25Z and running on the computer i.e- FB_Run and PC_Run.
The memory test is a set of functions that are performed on the dynamically allocated memory. The test begins with dynamic memory allocation using malloc function followed by writing a pattern in the allocated memory. The pattern is generated with the help of random pattern generator that takes seed value for randomization. The memory test then displays the pattern after it is stored in the heap.In order to verify the pattern with stored pattern Verify function is used. There is an offset and modify functions that help user to change values at certain location and then again verify with the same seed pattern from pattern generator. If the pattern doesn’t match it shows an error. Then invert function is performed to invert the number using XOR function and store it in the memory.After Invert function,the pattern is verified again.At the end of the verification,the allocated memory is freed.
In FB_Run version, we switch on LED BLUE when the memory test begins and LED GREEN when the memory test ends successfully.The LED RED is on when there is error condition in the test.
The logger is used to print messages on the console.We use log enable and disable functions to enable or disable the logger.The logger has various other functions like log integer(prints integer),log data(prints data in memory) and log string(prints string). 
Installation and Execution notes:
For the above project, we used Freedom Board KL25Z and MCUXpresso IDE v11. We used arm-gcc and gcc compiler for the two different platforms. Make files were manually generated on the same IDE.
Please delete and create a new debug folder before executing the PC_Run version for checking results.


