#include "FileIO.h"
#include "Parser.h"
#include "Generator.h"

void main() {
	//    String  --->  List<Tokens>  --->  Tree<Tokens> --.
	//          LEXER                PARSER          TRANS  \  
	//            .                    .                  L  `-->  Tree<Tokens> --->  List<Tokens>  --->  String
	//            .                    .                   ATOR              FLATTENER           SEQUENCER 
	//            .                    .                   .                     .                   .        
	//            .                    .                   .                     .                   .        
	//                                              magic! & optimization                        formatting


}
