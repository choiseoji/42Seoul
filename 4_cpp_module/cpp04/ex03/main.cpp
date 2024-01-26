#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"

int main()
{
    static Floor floor;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    ICharacter* seo = new Character("seo");
    me->use(2, *seo);    // 존재하지 않는 materia 사용
    me->use(4, *seo);    // idx 범위 넘어간 것 사용
    me->unequip(2);  // 존재하지 않는 materia 해제
    me->unequip(-1);   // idx 범위 넘어간 것 해제

    me->unequip(0);
    me->unequip(1);
    me->use(0, *seo);

    delete bob;
    delete seo;
    delete me;
    delete src;
    return 0;
}
