TestVector macro	CTRIS, DTRIS, COUT, DOUT, CEXPECTED, DEXPECTED

	;Copy the given literals into the variable locations
	movlw	CTRIS
	movwf	LastCT

	movlw	DTRIS
	movwf	LastDT

	movlw	COUT
	movwf	LastCO

	movlw	DOUT
	movwf	LastDO

	movlw	CEXPECTED
	movwf	CEXP

	movlw	DEXPECTED
	movwf	DEXP


	;Run the test
	call	RunTest


	endm

