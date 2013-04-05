PrintTestResults:
	;Print out CTRIS, DTRIS, COUT, DOUT in hex
	PrintL	' '
	PrintFHH	LastCT
	PrintFHL	LastCT
	PrintL	' '
	PrintFHH	LastDT
	PrintFHL	LastDT
	PrintL	' '
	PrintFHH	LastCO
	PrintFHL	LastCO
	PrintL	' '
	PrintFHH	LastDO
	PrintFHL	LastDO

	;Go to LCD line 2
	movlw	0x40
	movwf	Output
	call	LCDGoto

	;Print out CEXP, DEXP, CIN, DIN, FailFlag
	PrintFHH	CEXP
	PrintFHL	CEXP
	PrintL	' '
	PrintFHH	DEXP
	PrintFHL	DEXP
	PrintL	' '
	PrintFHH	LastCI
	PrintFHL	LastCI
	PrintL	' '
	PrintFHH	LastDI
	PrintFHL	LastDI
	PrintL	' '
	PrintFHH	FailFlag
	PrintFHL	FailFlag

	return
