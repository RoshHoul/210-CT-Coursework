/*PSEUDOCODE
input sizeM
input mA
input mB

ADD(sizeM, mA, mB)
	for i<-0 to sizeM
		for j<-0 to sizeM
			addResult <- mA[i,j] + mB[i,j]
SUB(sizeM, mA, mB)	
	for i<-0 to sizeM
		for j<-0 to sizeM
			subResult <- mA[i,j] - mB[i,j]
MULN(num, m)
	for i<-0 to sizeM
		for j<-0 to sizeM
			mulnumResult <- num * m[i,j]
	

MUL(sizeM, mA, mB) 
	for i <- 0 to sizeM	
		for j<-0 to sizeM
			for k<-0 to sizeM
				mulResult[i,j] += mA[i][k] * mB[k][j]

 
addResult <- ADD(sizeM, mA, mB)
MULN(sizeM, 2, addResult)
mulResult <- MUL(sizeM, mA, mB)
finalResult <- SUB(sizeM, mulResult, addResult)*/

//The runtime of functions ADD, SUB and MULNUM will be O(n^2), and function MUL will have O(n^3) because of the nested loops.
//If we compute the equation, the runtime will be O(n^3).