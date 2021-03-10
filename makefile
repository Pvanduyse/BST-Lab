lab6: main.cpp BSTInterface.h NodeInterface.h BST.h BST.cpp
	g++ -std=c++11 -g -o lab6 main.cpp BST.cpp

turnin.txt: lab6
	./lab6
	bash check.sh

clean:
	rm -f lab6 turnin.txt details.txt out_file*
