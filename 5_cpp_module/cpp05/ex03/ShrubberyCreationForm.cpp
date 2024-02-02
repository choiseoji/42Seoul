#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("", false, 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, false, 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) : AForm(scf.getName(), scf.getIsSigned(), 145, 137) { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    if (this != &scf)
    {
        const AForm* basePtr = &scf;
        copyArg(basePtr);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

void ShrubberyCreationForm::beExecuted(std::string target) const
{
    std::string file_name;

    file_name = target+"_shrubbery";
    std::ofstream file(file_name);
    if (file.is_open())
    {
        file << "                    \\" << std::endl;
        file << "          |         |" << std::endl;
        file << "          |       \\ /" << std::endl;
        file << "   _ .     \\   „;=`y   .   |" << std::endl;
        file << " .⁻⁻> \\«  ` |  `: /”» ’   /" << std::endl;
        file << ". ,/ `\\;`.  `=„\\`/; „=’  ”.=’    |" << std::endl;
        file << " ’   , =\\;` /, =”;„  ==./--=.”» /" << std::endl;
        file << "    ’     \\`v  8/,”-./ ``  ,-`/--’" << std::endl;
        file << "           \\\\\\|//  ` v__,=”   \\" << std::endl;
        file << "            \\\\y¡’ _,/,<=’" << std::endl;
        file << "             \\8|y’,-’  ``\\" << std::endl;
        file << "             |{ o/" << std::endl;
        file << "             |) |" << std::endl;
        file << "             |; |" << std::endl;
        file << "             |; |" << std::endl;
        file << "            „{) o\\" << std::endl;
        file.close();
    }
}
