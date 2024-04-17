set:
	g++ testSet.cpp Set.cpp -o set.out

newset:
	g++ testnewSet.cpp newSet.cpp -o newset.out

payerset:
	g++ testPayerSet.cpp PayerSet.cpp Set.cpp -o payerset.out

clean:
	rm -f *.out
