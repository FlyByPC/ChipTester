Pass:
	call	Cls
	PrintL	'P'
	PrintL	'A'
	PrintL	'S'
	PrintL	'S'
	call	PrintTestResults
	;Wait for a short while
	call	Delay_50ms

	return

Fail:
	call	Cls
	PrintL	'F'
	PrintL	'A'
	PrintL	'I'
	PrintL	'L'
	call	PrintTestResults
	;Wait for a while
	call	Delay_5s
	return