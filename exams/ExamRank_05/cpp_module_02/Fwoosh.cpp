#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}
Fwoosh::~Fwoosh() {}
// this is commented out because it is not needed
ASpell *Fwoosh::clone() const
{
    return (new Fwoosh());
}

int main() {
    printf("asd");

}

