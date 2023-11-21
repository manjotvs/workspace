#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


////////////////////////////////////////////////////////////////////////////////
/* TESLA MOTORS FIRMWARE TEST
 * You have 120 minutes to complete the test. There are 100 points total.
 *
 * All solutions should compile in Coderpad.io without error or warnings
 *
 * Penalties:
 * -1 / minute over time
 * -3 for 1 or more compilation errors
 * -2 for 1 or more compilation warnings
 *
 * Do not use outside aid or share the content of this test
 *
 * A main() function is provided at the bottom for your use
 */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// 1) Macro (10 points)
//    Create a macro (named C_TO_F) to convert from degrees Celsius to Fahrenheit
//    Macro should work for integer or floating point types
//    Note: degF = degC * (9/5) + 32
#define C_TO_F(degC) (degC * (9.0/5.0) + 32)


////////////////////////////////////////////////////////////////////////////////
// 2) Bit Manipulation (5 points)
//    Write a function that inverts (0 -> 1 or 1 -> 0) the most significant and
//    least significant bits of the data value pointed to by b.


void flip_hi_lo(uint8_t* b)
{
	*b =(uint8_t)(~(*b) & 0x81) | (*b & 0x7E);
}

////////////////////////////////////////////////////////////////////////////////
// 3) Debugging (5 points)
//    The function computeSquareADC() has not been producing correct
//    output consistently. Please describe all issues with the function.
// Answer: TODO

volatile uint8_t ADC_RESULT;
uint8_t computeSquareADC(void)
{
    uint16_t retval = ADC_RESULT * ADC_RESULT;
    return retval;
}
// Possible Issues:
// ADC_RESULT is declared as volatile variable whose value can change unexpectldy
// from outside the function.
// For example, at time t1 ADC_RESULT was 10 and time t2 ADC_RESULT is 20;
// There is a possibilty that by the time processor computes the retval, ADC_RESULT
// can change from 10 to 20. And,user will 200 instead of 100.


////////////////////////////////////////////////////////////////////////////////
4) Memory dump (10 points)
   The following memory dump was taken while debugging an issue.

Memory Dump:
Address:  Byte:
0x1000    0xA0
0x1001    0x0A
0x1002    0xBA
0x1003    0x48
0x1004    0x2C
0x1005    0xB7
0x1006    0x3B
0x1007    0x82
0x1008    0x9C
0x1009    0xE5
0x100A    0x17
0x100B    0x40
0x100C    0xEF
0x100D    0x47
0x100E    0x0F
0x100F    0x98
0x1010    0x6F
0x1011    0xD5
0x1012    0x70
0x1013    0x9E
0x1014    0x94
0x1015    0x99
0x1016    0x4A
0x1017    0xBA
0x1018    0xCA
0x1019    0xB2
0x101A    0x32
0x101B    0xE6
0x101C    0x8E
0x101D    0xB9
0x101E    0xC5
0x101F    0x2E
0x1020    0xC3

System is 32-bit, little-endian.
A variable called myPacket is of type packet_S (typedef below).
(Default compiler options; unpacked, naturally aligned.)
The address of myPacket is 0x1010.

typedef struct
{
    uint8_t count;
    uint16_t data[2];
    uint32_t timestamp;
} packet_S;

packet_S packet_p;


Print the values for the data members of the packet_p;
count = 
data[0] = 
data[1] = 
timestamp = 

// a) What are the values of each member of myPacket?
// count = 0x6F
// data[0] = 0x9E70
// data[1] = 0x9994
// timestamp = 0xE632B2CA


// b) If the system was big-endian, what would the values of each member of
//    myPacket be?
// count = 0x6F
// data[0] = 0x709E
// data[1] = 0x9499
// timestamp = 0CAB232E6

////////////////////////////////////////////////////////////////////////////////
// 5) State Machine (20 points)
//
//    Complete the function below to implement the state machine shown in the
//    diagram below for an electronic gumball vending machine.
//     * The initial state of the state machine should be IDLE
//     * The function should output the current state of the state machine
//     * Unexpected or invalid input should not cause a state transition
//     * GENERIC_FAULT may be received in any state and should put the machine
//       into the FAULT state
//
//
//          COIN      +---------+
//   +--------------->|         |   BUTTON
//   |                |  READY  | ---------+
//   |    COIN_RETURN |         |          |
//   |   +----------- +---------+          |
//   |   |                                 |
//   |   V                                 V
// +---------+                        +---------+
// |         |     VEND_COMPLETE      |         |
// |  IDLE   |<-----------------------| VENDING |
// |         |                        |         |
// +---------+                        +---------+
//
//                                 +---------+
//                                 |         |
//                GENERIC_FAULT    |  FAULT  |
//             +------------------>|         |
//                                 +---------+
//

typedef enum
{
    IDLE,
    READY,
    VENDING,
    FAULT
} state_E;

typedef enum
{
    COIN,
    COIN_RETURN,
    BUTTON,
    VEND_COMPLETE,
    GENERIC_FAULT
} input_E;


state_E stateMachine(input_E input)
{
   static state_E currentState = IDLE;

   if(input == GENERIC_FAULT)
   {
      currentState = FAULT;
   }
   switch(currentState)
   {
     case IDLE:
          if(input == COIN)
            currentState = READY;
          break;
     case READY:
          if(input == COIN_RETURN)
            currentState = IDLE;
          else if(input == BUTTON)
            currentState = VENDING;
          break;
     case VENDING:
          if(input == VEND_COMPLETE)
            currentState = IDLE;
          break;
     case FAULT:
          break;
     default:
          break;
   }

  return currentState;
}


////////////////////////////////////////////////////////////////////////////////
// 6) Unit Testing (10 points)
//    Write a unit test for validatePointerAndData that exercises all code paths
//    and branch conditions

// @param dataPtr - int32_t pointer to data to be used
//
// @return TRUE if pointer is non-NULL, data value is positive, non-zero and not
//         equal to the sentinel value 0x7FFFFFFF, FALSE otherwise
//
bool validatePointerAndData(int32_t* dataPtr)
{
    bool status = false;
    if ((dataPtr != NULL) &&
        (*dataPtr > 0)    &&
        (*dataPtr != 0x7FFFFFFF))
    {
        status = true;
    }
    return status;
}

//
// @return TRUE if all tests pass, FALSE otherwise
//
bool test_validatePointerAndData(void)
{
    int32_t *data = NULL;
    int32_t val = 0x12345;
    data = &val;
    if(validatePointerAndData(data))
      return true;



    return false;
}


////////////////////////////////////////////////////////////////////////////////
// 7) Low Pass Filter (10 points)
//    Implement a function that will be called at 10hz (every 100 ms) and returns
//    an exponentially weighted average. The latest sample is given 1/10 weighting
//    and previous filtered value a weighting of 9/10. The function should
//    initialize the filter to the first sample value received if it is the first
//    time the function has run.

float lowPassSamples_10hz(float sample)
{
    static float filtered_value = 0.0f;
    static bool first_time_flag = 1;

    if(first_time_flag)
    {
      filtered_value = sample;
      first_time_flag = 0;
    }
    else
    {
      filtered_value = filtered_value * 0.9f + sample * 0.1f;
    }


    return filtered_value;
}

////////////////////////////////////////////////////////////////////////////////
// 8a) Buffer (20 points: 8a + 8b)
//     Create a function to push a char into a FIFO. The FIFO should be implemented
//     as a circular buffer of length 20. The FIFO will be used to cache the most
//     recent data from a data stream, therefore, drop the oldest value if the
//     buffer is full.

#define BUFFER_SIZE 20
int read_index = 0;
int write_index = 0;
int buffer_length = 0;
void disableInterrupts();
void enableInterrupts();
char circular_buffer[BUFFER_SIZE];

bool circular_buf_isempty()
{
    return((buffer_length==0)?1:0);
}

bool circular_buf_isfull()
{
    return((buffer_length==BUFFER_SIZE)?1:0);
}

void circular_buf_push(char data)
{

    fifoBuffer[write_index] = data;
    write_index = (write_index+1)%BUFFER_SIZE;
    if(write_index == read_index)
    {
        read_index +=1;
        buffer_length-=1;
    }
    buffer_length+=1;
    if(buffer_length>=BUFFER_SIZE)
    {
        buffer_length = BUFFER_SIZE;
    }
}

char circular_buf_pop()
{
    if(circular_buf_isempty)
    {
        return -1;
    }
    char data = fifoBuffer[read_index];
    read_index = (read_index + 1)%BUFFER_SIZE;
    buffer_length-=1;
    return data;
}



void bufferPush_ISR(char data)
{
   disableInterrupts();

   circular_buf_push(data);

   enableInterrupts();
}

////////////////////////////////////////////////////////////////////////////////
// 8b) Create a function to print out and empty the data buffer.
//     Data should be printed in order from oldest to newest, active elements only.

void printAndEmptyBuffer(void)
{
    disableInterrupts();
    while(!circular_buf_isempty())
    {
      printf("%d\n",circular_buf_pop());
    }
    enableInterrupts();
}

////////////////////////////////////////////////////////////////////////////////
// 8c) Interrupts (10 points)
//     The function bufferPush_ISR() will be called from an interrupt service
//     routine whenever new data is available to be buffered.
//     The function printAndEmptyBuffer() will be called from a periodic task.
//     The functions disableInterrupts() and enableInterrupts() are available
//     for disabling and enabling interrupts, respectively.
//
//     In your implementations of bufferPush_ISR() and printAndEmptyBuffer(),
//     determine whether or not it is necessary to disable/enable interrupts.
//     If so, add comments where the calls are necessary. If not required,
//     briefly comment why not.
//
// All circular buffer related routines are sharing the critical data so in order to
// avoid any overwrite user should protect them by disabling and enabling the
// interrupts.


int main()
{

    return 0;
}
