/*
	pinmode.h - Header file for declaring multiple pins as input/output.
	Created by Plaban Mohapatra & Anshul Jindal, June 30, 2018.
	Only for VSSUT Robotics Club Members.
*/

#ifndef MotorTest_h
	#define MotorTest_h
#endif

#include "Arduino.h"
#define Fban(a, b, c) for(a = b; a < c; a++)
#define FFban(a, b, c) for(a = b; a < c/2; a++)
int vansh, pinul[20];
class MotorTest
{
	private:
		int ipla;

	public:
		void motor_run(byte Mspeed, bool Mdir, int time_delay, int num_out, ...);
};
void MotorTest::motor_run(byte Mspeed, bool Mdir, int time_delay, int num_out, ...)
{Serial.println(Mdir);
	va_list outputPin_List;
  va_start (outputPin_List, num_out);

  Fban(ipla, 0, num_out)
  {
    vansh = va_arg(outputPin_List, int);
    pinul[ipla] = vansh;
  }
  va_end(outputPin_List);


  FFban(ipla, 0, num_out)
  {
    analogWrite(pinul[ipla], Mspeed);
    digitalWrite(pinul[ipla + num_out / 2], Mdir);
  }
  delay(time_delay);

  FFban(ipla, 0, num_out)
  {
    analogWrite(pinul[ipla], 0);
    digitalWrite(pinul[ipla + num_out / 2], Mdir);

  }
  delay(time_delay);
}