#pragma once
#include "std_lib_facilities.h"



// 4a - forskjellen mellom const og constexpr er at kompilatoren vet om constexpr sin verdi før den skal kompilere.
// const sin verdi vet kompilatoren om først etter at den har kjørt, bruker constexpr her og ikke const siden vi vet 
// om verdien til variablene før vi kjører spillet

void playmastermind();
int checkCharactersAndPosition(string code, string guess);
int checkCharacters(string code, string guess);