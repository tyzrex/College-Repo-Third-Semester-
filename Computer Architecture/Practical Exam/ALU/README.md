## ALU IN VHDL

The process of running the vhdl program is same for all the programs only thing thats different is the input providing procedure for each of the circuitary implementations. The guide for running the vhdl program is given at the readme of the main practical folder 

## PROCEDURE

Firstly run the program as it should be by creating the project file and then compiling the program. Then simulate the program then you will be welcomed with a screen as shown below

![statrt](./assets/start.png)

---

After this then right click on alu on the left side of the screen and add the wave

![addwave](./assets/addwave.png)

---

Then now the msgs part appears on the wave 

![msg](./assets/msgs.png)

---

Now force the inputs as per your requirement 

![force](./assets/force.png)

---

Give the ALU signal lines which is of 3 bits that signify the procedure that is to be done in the ALU. The following table shows all the possibilities

| Selection Input | Operation performed |
| --------------- | ------------------- |
| 000             | A+B                 |
| 001             | A-B                 |
| 010             | A-1                 |
| 011             | A+1                 |
| 100             | A and B             |
| 101             | A or B              |
| 110             | Not A               |
| 111             | A xor B             |

Now suppose we want to do addition then on the selection line we force the input 000 which indicates addition as shown in the table above

![sum](./assets/000.png)

And also give the desired inputs

![inp1](./assets/inp1.png)

![inp2](./assets/inp2.png)

---

Now run the program to get the output

![output](./assets/output.png)

From this example we can see that we gave the outputs 0001 and 0010 and the selection line was 000 which indicates addition procedure so the output is justified as the sum which is 0011 so we performed the addition operation. Similarly we can do other operations by changing the selection line codes.

---

