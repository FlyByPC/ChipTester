
====================
TTL 74xx Chip Tester
====================

M. Eric Carr
Drexel University Engineering Technology
mec82@drexel.edu

This project is designed to test 74xx TTL chips, using a
test vector approach. For now, vectors are manually programmed.

The DUT (a DIP14 TTL chip) is connected to the PIC as follows:
(C0 is PORTC, bit 0 etc.)

		 ----------------------------
		| 5V  D5  D4  D3  D2  D1  D0 |
		|                            |
		| C0  C1  C2  C3  C4  C5  0V |
		 ----------------------------

Core functionality: Call macro TestVector as follows:

TestVector CTRIS, DTRIS, COUT, DOUT, CEXPECTED, DEXPECTED    , where:
	- CTRIS is the value to send to TRISC;
	- DTRIS is the value to send to TRISD;
	- COUT is the value to place on PORTC (subject to TRIS register);
	- DOUT is the value to place on PORTD (subject to TRIS register);
	- CEXPECTED is the value expected back from PORTC (input & output);
	- DEXPECTED is the value expected back from PORTD (input & output);
	(Pass all of the above as literals; they will be copied using MOVLW.)

