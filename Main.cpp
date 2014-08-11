//#include "FileIO.h"
//#include "Parser.h"
//#include "Generator.h"
//
//void main() {
//	//    String  --->  List<Tokens>  --->  Tree<Tokens> --.
//	//          LEXER                PARSER          TRANS  \  
//	//            .                    .                  L  `-->  Tree<Tokens> --->  List<Tokens>  --->  String
//	//            .                    .                   ATOR              FLATTENER           SEQUENCER 
//	//            .                    .                   .                     .                   .        
//	//            .                    .                   .                     .                   .        
//	//                                              magic! & optimization                        formatting
//
//
//}

#include "List.h"
#include <iostream>
using namespace std;

void print(const List<int>& L) {
	for(LIterator<int> i(L); i.can_continue(); i.next()) {
		cout << i.val() << " ";
	}
	cout << endl;
}

void main() {
	List<int> L;
	L.append(4);
	L.append(5);
	L.append(6);
	for(LIterator<int> i(L); i.can_continue(); i.next()) {
		print(L);
		if(i.val() == 5) {
			i.remove();
			cout << "removed: "; print(L);
			i.insert(5);
			cout << "inserted: "; print(L);
		}
	}
	
	cout << "tada!" << endl;
	char l; cin >> l;
}
