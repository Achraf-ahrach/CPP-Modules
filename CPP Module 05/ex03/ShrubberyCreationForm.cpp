#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 0, 145, 137)
{
    target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 0, 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator = (other);
    target = other.target;

    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm()
{
    *this = other;
}

void   ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (getsigning() == 0 && getgrade_sign() > executor.getGrade())
        throw AForm::GradeTooHighException("ShrubberyCreationForm: check that the form is signed and grade of the bureaucrat is very low !");
    else if (getsigning() == 0)
        throw AForm::GradeTooHighException("ShrubberyCreationForm: check that the form is signed !");
    else if (getgrade_sign() > executor.getGrade())
        throw AForm::GradeTooHighException("ShrubberyCreationForm: grade of the bureaucrat is very low !");
    else
    {
        std::string _name = target + "_shrubbery";
        std::ofstream outputFile(_name.c_str());
        if (!outputFile)
        {
            std::cout << "ShrubberyCreationForm: Failed to open file : " << target + "_shrubbery" << std::endl;
            return ;
        }
        outputFile << "\n";
        outputFile << "                      ___\n";
        outputFile << "                _,-'\"\"   \"\"\"\"`--.\n";
        outputFile << "             ,-'          __,,-- -\\\n";
        outputFile << "           ,'    __,--\"\"\"\"dF      ;\n";
        outputFile << "          /   .-\"Hb_,--\"\"\"dF      /\n";
        outputFile << "        ,'       _Hb ___dF\"\"-._,-\'\n";
        outputFile << "      ,'      _,-\"\"\"\"   \"\"--..__\n";
        outputFile << "     '     ,-'                  `.\n";
        outputFile << "      `._,'     _   _             ;\n";
        outputFile << "       ,'     ,' `-'Hb-.___..._,-'\n";
        outputFile << "       '    ,'\"'Hb.-'HH''-.dHF\"\n";
        outputFile << "        `--'   \"Hb  HH  dF\"\n";
        outputFile << "                \"Hb HH dF\"\n";
        outputFile << "                 \"HbHHdF\"\n";
        outputFile << "                  |HHHF\n";
        outputFile << "                  |HHH|\n";
        outputFile << "                  |HHH|\n";
        outputFile << "                  |HHH|\n";
        outputFile << "                  |HHH|\n";
        outputFile << "                  |HHH|\n";
        outputFile << "                  dHHHb\n";
        outputFile << "                .dFd|bHb.               o\n";
        outputFile << "      o       .dHFdH|HbTHb.          o /\n";
        outputFile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n";
        outputFile << "##########################################\n";
    }
}
